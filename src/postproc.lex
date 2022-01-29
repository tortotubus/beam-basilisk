%option noyywrap

%{

static int input (void);

static void comment (void)
{
  int c;  
  while ((c = input()) != 0) {
    fputc (c, yyout);
    if (c == '*') {
      while ((c = input()) == '*')
	;
      
      if (c == '/')
	return;
      
      if (c == 0)
	break;
    }
  }
}

static int line = 1, indef = 0;
  
#define YY_INPUT(buf,result,max_size)			      \
  {							      \
    int c = fgetc(yyin);				      \
    if (c == '\n') { line++; }				      \
    result = (c == EOF) ? YY_NULL : (buf[0] = c, 1);	      \
  }
  
%}

SP     [ \t]
WS     [ \t\v\n\f]
ES     (\\([\'\"\?\\abfnrtv]|[0-7]{1,3}|x[a-fA-F0-9]+))
STRING \"([^"\\\n]|{ES})*\"

%%

"/*"                                    { comment(); }
"//".*                                  { ECHO; /* consume //-comment */ }

^{SP}*#{SP}+[0-9]+{SP}+{STRING}({SP}+[0-9]+)* {
  /* replace # 3 "machin.h" 2 4 with #line 3 "machin.h" */
  char * s = strchr(yytext, '#') + 1;
  line = atoi(s);
  if (!indef) {
    fputs ("#line", yyout);
    char * s1 = strchr(s, '"');
    s1 = strchr(s1 + 1, '"');
    *(s1 + 1) = '\0';  
    fputs (s, yyout);
  }
}

^{SP}*@{SP}*def{SP}.*                   {
  /* replace @def ... @ with #define ... \\ */
  fputs ("#define", yyout);
  fputs (strstr (yytext, "def") + 3, yyout);
  indef = 1;
}

^{SP}*@{SP}* {
  if (indef) {
    indef = 0;
    fprintf (yyout, "\n#line %d\n", line - 1);
  }
  else
    REJECT;
}

^{SP}*@.*	                        {
  /* replace @define etc. with #define etc. */
  *strchr(yytext, '@') = '#'; ECHO;
}

{STRING}+	{ ECHO; }
\n            {
  if (indef)
    fputs ("\\\n", yyout);
  else
    ECHO;
}
.		{ ECHO; }

%%

int postproc (FILE * fin, FILE * fout)
{
  if (0) yyunput (0, NULL); // just prevents 'yyunput unused' compiler warning
  yyin = fin;
  yyout = fout;
  line = 1;
  indef = 0;
  return yylex();
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <assert.h>

int dimension = 2, bghosts = 0, layers = 0;
  
int debug = 0, catch = 0, cadna = 0, nolineno = 0, events = 0, progress = 0;
int nohook = 0;
char dir[] = ".qccXXXXXX";

char * autolink = NULL;
int autolinks = 0, source = 0;
  
char * dname (const char * fname);
FILE * dopen (const char * fname, const char * mode);
  
int includes (int argc, char ** argv, char ** out, 
	      char ** grid, int * default_grid,
	      int * dimension, int * bg, int * layers,
	      const char * dir);

extern int endfor (FILE * fin, FILE * fout);

FILE * writepath (char * path, const char * mode)
{
  char * s = path;
  while ((s = strchr (s, '/'))) {
    *s = '\0';
    if (access (path, R_OK|W_OK|X_OK) && mkdir (path, 0700))
      return NULL;
    *s++ = '/';
  }
  return fopen (path, mode);
}

void cleanup (int status, const char * dir)
{
  if (!debug && dir) {
    char command[80] = "rm -r -f ";
    strcat (command, dir);
    int s = system (command); s = s;
  }
  exit (status);
}

char * dname (const char * fname)
{
  char * out = malloc (strlen (dir) + strlen (fname) + 2);
  strcpy (out, dir); strcat (out, "/"); strcat (out, fname);
  return out;
}

FILE * dopen (const char * fname, const char * mode)
{
  char * out = dname (fname);
  FILE * fout = fopen (out, mode);
  free (out);
  return fout;
}

void compdir (FILE * fin, FILE * fout, FILE * swigfp, 
	      char * swigname,
	      char * grid)
{
#if 1  
  int nboundary = 0;
  int boundaryindex[80], periodic[80];
  #define doubletype "double"
  int nvar = 0, nevents = 0, * nexpr;
  char ** eventfunc;
  char * eventarray;
  char ** eventarray_elems;
  int nsetboundary = 0;
#endif

  FILE * fout1 = dopen ("_endfor.c", "w");
  if (endfor (fin, fout1))
    cleanup (1, dir);
  fclose (fout1);

  fout1 = dopen ("_endfor.c", "r");
  extern int postproc (FILE * fin, FILE * fout);
  postproc (fout1, fout);
  fclose (fout1);

  fout = dopen ("_boundarydecl.h", "w");
  int i;
  for (i = 0; i < nboundary; i++)
    if (!periodic[i])
      fprintf (fout, 
	       "static %s _boundary%d (Point point, Point neighbor,"
	       " scalar _s, void * data);\n"
	       "static %s _boundary%d_homogeneous (Point point,"
	       " Point neighbor, scalar _s, void * data);\n", 
	       doubletype, i, doubletype, i);
  fclose (fout);

  fout = dopen ("_grid.h", "w");
  /* new variables */
  fprintf (fout,
	   "size_t datasize = %d*sizeof (%s);\n",
	   nvar, doubletype);
  /* attributes */
  FILE * fp = dopen ("_attributes.h", "a");
  fputs ("\n"
	 "} _Attributes;\n"
	 "_Attributes * _attribute;\n",
	 fp);
  fclose (fp);
  /* event functions */
  for (i = 0; i < nevents; i++) {
    char * id = eventfunc[i];
    fprintf (fout, 
	     "static int %s (const int i, const %s t, Event * _ev);\n",
	     id, doubletype);
    int j;
    for (j = 0; j < nexpr[i]; j++)
      fprintf (fout,
	       "static int %s_expr%d (int * ip, %s * tp, Event * _ev);\n",
	       id, j, doubletype);
    if (eventarray[i])
      fprintf (fout, "static %s %s_array[] = %s,-1};\n", 
	       eventarray[i] == 'i' ? "int" : doubletype, id,
	       eventarray_elems[i]);
  }
  /* boundaries */
  for (i = 0; i < nsetboundary; i++)
    fprintf (fout, "static void _set_boundary%d (void);\n", 
	     boundaryindex[i]);
  /* stencil point functions */
#if 0  
  fp = dopen ("_stencils.h", "w");
  for (i = varstack; i >= 0; i--) {
    var_t var = _varstack[i];
    if (var.called)
      print_function_rotate (&var, fp, "#define _call_%s 1\n");
  }
  fclose (fp);
  file_prepend ("_stencils_reversed.h", "_stencils.h");
#endif
  /* _init_solver() */
  fputs ("void _init_solver (void) {\n"
	 "  void init_solver();\n"
	 "  init_solver();\n", fout);
  /* init_solver functions */
#if 0  
  for (i = 0; i < ninit; i++)
    fprintf (fout,
	     "  void %s;\n"
	     "  %s;\n", initfunc[i], initfunc[i]);
#endif
  /* events */
  fprintf (fout,
	   "  Events = (Event *) pmalloc (sizeof (Event), __func__, __FILE__, %s);\n"
	   "  Events[0].last = 1;\n", nolineno ? "0" : "__LINE__");
#if 0  
  int last;
  for (last = 0; last <= 1; last++)
    for (i = 0; i < nevents; i++)
      if (eventchild[i] < 0 && eventlast[i] == last) {
	int j = i;
	while (j >= 0) {
	  write_event (j, fout);
	  j = eventparent[j];
	}
      }
#endif
  fprintf (fout,
	   "  void allocate_globals (int);\n"
	   "  allocate_globals (%d);\n"
	   "  set_fpe();\n", nvar);
  if (catch)
    fputs ("  catch_fpe();\n", fout);
  if (progress)
    fputs ("  last_events();\n", fout);
  fprintf (fout, "  %s_methods();\n", grid);
#if 0  
  for (i = varstack; i >= 0; i--) {
    var_t var = _varstack[i];
    if (var.i[0] >= 0) {
      if (var.constant) {
	// global constants
	if (var.type == scalar)
	  fprintf (fout, 
		   "  init_const_scalar ((scalar){_NVARMAX+%d}, \"%s\", %s);\n",
		   var.i[0], var.v, var.constant);
	else if (var.type == vector) {
	  int i;
	  fprintf (fout, "  init_const_vector ((vector){{_NVARMAX+%d}",
		   var.i[0]);
	  for (i = 1; i < dimension; i++)
	    fprintf (fout, ",{_NVARMAX+%d}", var.i[i]);
	  fprintf (fout, "}, \"%s\", (%s [])%s);\n",
		   var.v, doubletype, var.constant);
	}
	else
	  assert (0);
      }
      // global variables
      else if (var.type == scalar)
	fprintf (fout, "  init_scalar ((scalar){%d}, \"%s\");\n",
		 var.i[0], var.v);
      else if (var.type == vector) {
	fprintf (fout, "  init_%svector ((vector){{%d}",
		 var.face ? "face_" : 
		 var.vertex ? "vertex_" : 
		 "",
		 var.i[0]);
	int i;
	for (i = 1; i < dimension; i++)
	  fprintf (fout, ",{%d}", var.i[i]);
	fprintf (fout, "}, \"%s\");\n", var.v);
      }
      else if (var.type == tensor) {
	fprintf (fout, "  init_tensor ((tensor){");
	int i, j, k = 0;
	for (i = 0; i < dimension; i++) {
	  fprintf (fout, "{{%d}", var.i[k++]);
	  for (j = 1; j < dimension; j++)
	    fprintf (fout, ",{%d}", var.i[k++]);
	  fprintf (fout, "}");
	  if (i < dimension - 1)
	    fputc (',', fout);
	}
	fprintf (fout, "}, \"%s\");\n", var.v);
      }
      else if (var.type == bid)
	fprintf (fout, "  %s = new_bid();\n", var.v);
      else
	assert (0);
    }
  }  
  for (i = 0; i < nsetboundary; i++)
    fprintf (fout, "  _set_boundary%d();\n", boundaryindex[i]);
#endif
  fputs ("}\n", fout);
  fclose (fout);

  if (source && autolinks && autolink)
    printf ("%s\n", autolink);
  
  /* SWIG interface */
  if (swigfp) {
    //    int i;
    fputs ("\n%{\n", swigfp);
#if 0    
    for (i = varstack; i >= 0; i--) {
      var_t var = _varstack[i];
      if (var.i[0] >= 0 && !var.constant)
	fprintf (swigfp, "  extern %s %s;\n", typestr (var), var.v);
    }
#endif
    fputs ("%}\n\n", swigfp);
#if 0    
    for (i = varstack; i >= 0; i--) {
      var_t var = _varstack[i];
      if (var.i[0] >= 0 && !var.constant)
	fprintf (swigfp, "extern %s %s;\n", typestr (var), var.v);
    }
#endif
    fputs ("\n%pythoncode %{\n", swigfp);
#if 0
    for (i = varstack; i >= 0; i--) {
      var_t var = _varstack[i];
      if (var.i[0] >= 0 && !var.constant)
	fprintf (swigfp, "%s = %s(_%s.cvar.%s)\n",
		 var.v, typestr (var), swigname, var.v);
    }
#endif
    fputs ("%}\n", swigfp);
    fclose (swigfp);
  }
}

int main (int argc, char ** argv)
{
  char * cc = getenv ("CC99"), command[1000], command1[1000] = "";
  if (cc == NULL)
    strcpy (command, CC99);
  else
    strcpy (command, cc);
  char * file = NULL;
  int i, dep = 0, tags = 0, swig = 0;
  for (i = 1; i < argc; i++) {
    if (!strncmp (argv[i], "-grid=", 6))
      ;
    else if (!strcmp (argv[i], "-MD"))
      dep = 1;
    else if (!strcmp (argv[i], "-tags"))
      tags = 1;
    else if (!strcmp (argv[i], "-python"))
      swig = 1;
    else if (!strcmp (argv[i], "-debug"))
      debug = 1;
    else if (!strcmp (argv[i], "-events"))
      events = 1;
    else if (!strcmp (argv[i], "-catch"))
      catch = 1;
    else if (!strcmp (argv[i], "-source"))
      source = 1;
    else if (!strcmp (argv[i], "-autolink"))
      autolinks = 1;
    else if (!strcmp (argv[i], "-nohook"))
      nohook = 1;
    else if (!strcmp (argv[i], "-progress"))
      progress = 1;
    else if (!strcmp (argv[i], "-Wall")) {
      char * s = strchr (command, ' ');
      if (s) {
	char command1[1000];
	strcpy (command1, s);
	*(s+1) = '\0';
	strcat (command, argv[i]);
	strcat (command, command1);
      }
      else
	strcat (command, argv[i]);
    }
    else if (!strcmp (argv[i], "-cadna")) {
      cadna = 1;
      char * cc = getenv ("CADNACC");
      if (cc == NULL)
	strcpy (command, CADNACC);
      else
	strcpy (command, cc);
    }
    else if (!strncmp (argv[i], "-Ddimension=", 12))
      dimension = 1 + argv[i][12] - '1';
    else if (catch && !strncmp (argv[i], "-O", 2))
      ;
    else if (!strcmp (argv[i], "-nolineno"))
      nolineno = 1;
    else if (!strcmp (argv[i], "-o")) {
      strcat (command1, " ");
      strcat (command1, argv[i++]);
      if (i < argc) {
	strcat (command1, " ");
	strcat (command1, argv[i]);
      }
    }
    else if (argv[i][0] != '-' && 
	     (tags || !strcmp (&argv[i][strlen(argv[i]) - 2], ".c"))) {
      if (file) {
	fprintf (stderr, "usage: qcc -grid=[GRID] [OPTIONS] FILE.c\n");
	return 1;
      }
      file = argv[i];
    }
    else if (!file) { 
      strcat (command, " ");
      strcat (command, argv[i]);
    }
    else {
      strcat (command1, " ");
      strcat (command1, argv[i]);
    }
  }
  char * openmp = strstr (command, "-fopenmp");
  if (openmp) {
    if (strstr (command, "-D_MPI")) {
      fprintf (stderr,
	       "qcc: warning: OpenMP cannot be used with MPI (yet): "
	       "switching it off\n");
      int i;
      for (i = 0; i < strlen("-fopenmp"); i++)
	openmp[i] = ' ';
    }
    else if (swig) {
      fprintf (stderr,
	       "qcc: warning: OpenMP cannot be used with Python (yet): "
	       "switching it off\n");
      int i;
      for (i = 0; i < strlen("-fopenmp"); i++)
	openmp[i] = ' ';
    }
  }
  int status;
  if (debug) {
    status = system ("rm -r -f .qcc");
    strcpy (dir, ".qcc");
    status = mkdir (dir, 0700);
  }
  else
    status = (mkdtemp (dir) == NULL);
  if (status) {
    perror (dir);
    return 1;
  }
  if (file) {
    char * out[100], * grid = NULL;
    int default_grid;
    includes (argc, argv, out, &grid, &default_grid,
	      &dimension, &bghosts, &layers,
	      dep || tags ? NULL : dir);
    FILE * swigfp = NULL;
    char swigname[80] = "";
    if (swig) {
      strcpy (swigname, file);
      char * dot = strchr (swigname, '.');
      *dot = '\0'; strcat (swigname, ".i");
      swigfp = fopen (swigname, "a");
      if (!swigfp) {
	fprintf (stderr, "qcc: could not open '%s': ", swigname);
	return 1;
      }
      *dot = '\0';
    }
    if (!dep && !tags) {
      char * basename = strdup (file), * ext = basename;
      while (*ext != '\0' && *ext != '.') ext++;
      char * cpp = malloc (strlen(basename) + strlen("-cpp") + strlen(ext) + 1);
      if (*ext == '.') {
	*ext = '\0';
	strcpy (cpp, basename);
	strcat (cpp, "-cpp");
	*ext = '.';
	strcat (cpp, ext);
      }
      else {
	strcpy (cpp, basename);
	strcat (cpp, "-cpp");
      }
      FILE * fin = dopen (file, "r");
      if (!fin) {
	perror (file);
	cleanup (1, dir);
      }
      FILE * fp = dopen ("_attributes.h", "w");
      fputs ("typedef struct {\n", fp);
      fclose (fp);
      fp = dopen ("_maps.h", "w");
      fclose (fp);
      FILE * fout = dopen (cpp, "w");
      if (swig)
	fputs ("@include <Python.h>\n", fout);
      fputs ("@if _XOPEN_SOURCE < 700\n"
	     "  @undef _XOPEN_SOURCE\n"
	     "  @define _XOPEN_SOURCE 700\n"
	     "@endif\n"
	     "@if _GNU_SOURCE\n"
	     "@include <stdint.h>\n"
	     "@include <string.h>\n"
	     "@include <fenv.h>\n"
	     "@endif\n",
	     fout);
      if (catch)
	fputs ("#define TRASH 1\n"
	       "#define _CATCH last_point = point;\n", 
	       fout);
      else
	fputs ("#define _CATCH\n", fout);
      fprintf (fout, "#define dimension %d\n", dimension);
      if (bghosts)
	fprintf (fout, "#define BGHOSTS %d\n", bghosts);
      if (layers)
	fprintf (fout, "#define LAYERS 1\n");
      fputs ("#include \"common.h\"\n", fout);
      /* catch */
      if (catch)
	fputs ("void catch_fpe (void);\n", fout);
      /* grid */
      if (default_grid)
	fprintf (fout, "#include \"grid/%s.h\"\n", grid);
      /* declaration of boundary condition fonctions */
      fputs ("@include \"_boundarydecl.h\"\n", fout);
      char s[81];
      while (fgets (s, 81, fin)) {
	// replace '#include <' with '@include <'
	char * s1 = s; while (strchr (" \t", *s1)) s1++;
	if (*s1 == '#') {
	  char *s2 = s1 + 1; while (strchr (" \t", *s2)) s2++;
	  if (!strncmp (s2, "include", 7)) {
	    while (!strchr (" \t", *s2)) s2++;
	    while (strchr (" \t", *s2)) s2++;
	    if (*s2 == '<')
	      *s1 = '@';
	  }
	}
	fputs (s, fout);
      }
      if (swigfp)
	fputs ("#include \"python.h\"\n", fout);
      if (progress)
	fputs ("#include \"grid/progress.h\"\n", fout);
      fclose (fout);
      fclose (fin);
      fout = dopen (file, "w");
      if (!fout) {
	perror (file);
	cleanup (1, dir);
      }

      char preproc[1000], * cppcommand = getenv ("CPP99");
      strcpy (preproc, "cd ");
      strcat (preproc, dir);
      strcat (preproc, " && ");
      if (!cppcommand && strcmp (CPP99, ""))
	cppcommand = CPP99;
      if (!cppcommand) {
	if (source) {
	  /* remove -D_GNU_SOURCE flags from $CC99 */
	  char tmp[1000]; strcpy (tmp, command);
	  char * s = strtok (tmp, " \t");
	  while (s) {
	    if (strncmp (s, "-D_GNU_SOURCE", 13)) {
	      strcat (preproc, s);
	      strcat (preproc, " ");
	    }
	    s = strtok (NULL, " \t");
	  }
	}
	else
	  strcat (preproc, command);
	strcat (preproc, " -E");
      }
      else
	strcat (preproc, cppcommand);
      // remove "-pedantic option from preprocessor
      // This is mostly to avoid the preprocessor warning:
      // "ISO C99 requires at least one argument in a variadic macro"
      // note that the option is kept for the final compilation
      char * pedantic = strstr (preproc, "-pedantic");
      if (pedantic)
	for (i = 0; i < strlen ("-pedantic"); i++)
	  pedantic[i] = ' ';
      strcat (preproc, " -I. -I");
      strcat (preproc, LIBDIR);
      strcat (preproc, " ");
      if (events) {
	strcat (preproc, " -DDEBUG_EVENTS=1 -DBASILISK=\"\\\"");
	strcat (preproc, BASILISK);
	strcat (preproc, "\\\"\" ");
      }
      if (nolineno)
	strcat (preproc, " -D'LINENO=0' ");
      strcat (preproc, cpp);
      if (debug) {
	fprintf (stderr, "preproc: %s\n", preproc);
	strcat (preproc, " | tee _preproc.c");
      }

      fin = popen (preproc, "r");
      if (!fin) {
	perror (preproc);
	cleanup (1, dir);
      }

      compdir (fin, fout, swigfp, swigname, grid);
      int status = pclose (fin);
      if (status == -1 ||
	  (WIFSIGNALED (status) && (WTERMSIG (status) == SIGINT || 
				    WTERMSIG (status) == SIGQUIT)))
	cleanup (1, dir);

      fout = dopen ("_tmp", "w");
      fin = dopen (file, "r");
      char line[1024];
      int c, lineno = 1;
      char * fname = NULL;
      // includes _attributes.h
      while (fgets (line, 1024, fin)) {
	if (!strcmp (line, "#include \"_attributes.h\"\n"))
	  break;
	else {
	  if (!strncmp (line, "#line ", 6)) {
	    lineno = atoi (&line[6]) - 1;
#define nonspace(s) { while (strchr(" \t\v\n\f", *s)) s++; }
#define space(s) { while (!strchr(" \t\v\n\f", *s)) s++; }
	    char * s = &line[6]; space (s); nonspace(s);
	    free (fname);
	    fname = strdup (s);
	  }
	  fputs (line, fout);
	}
	lineno++;
      }
      fp = dopen ("_attributes.h", "r");
      while ((c = fgetc (fp)) != EOF)
	fputc (c, fout);
      fclose (fp);
#if 0      
      fp = dopen ("_stencils_reversed.h", "r");
      while ((c = fgetc (fp)) != EOF)
	fputc (c, fout);
      fclose (fp);
#endif
      fprintf (fout, "#line %d %s\n", lineno, fname);
      free (fname);
      // includes _boundarydecl.h
      while (fgets (line, 1024, fin))
	if (!strcmp (line, "#include \"_boundarydecl.h\"\n"))
	  break;
	else
	  fputs (line, fout);
      fp = dopen ("_boundarydecl.h", "r");
      while ((c = fgetc (fp)) != EOF)
	fputc (c, fout);
      fclose (fp);
      // rest of the file
      while (fgets (line, 1024, fin))
	fputs (line, fout);
      fclose (fin);

#if 0      
      fin = dopen ("_boundary.h", "r");
      while ((c = fgetc (fin)) != EOF)
	fputc (c, fout);
      fclose (fin);
#endif
      
      fin = dopen ("_grid.h", "r");
      while ((c = fgetc (fin)) != EOF)
	fputc (c, fout);
      fclose (fin);

      fclose (fout);

      char src[80], dst[80];
      strcpy (src, dir); strcat (src, "/_tmp");
      if (source) {
	strcpy (dst, "_");
      }
      else {
	strcpy (dst, dir); strcat (dst, "/");
      }
      strcat (dst, file);
      rename (src, dst);

      strcat (command, " -I");
      strcat (command, LIBDIR);
      strcat (command, " ");
      strcat (command, dir);
      strcat (command, "/");
      strcat (command, file); 
      strcat (command, command1);
    }
  }
  else if (dep || tags) {
    fprintf (stderr, "usage: qcc -grid=[GRID] [OPTIONS] FILE.c\n");
    cleanup (1, dir);
  }
  else
    strcat (command, command1);
  /* compilation */
  if (!dep && !tags && !source) {
    if (autolinks && autolink)
      strcat (command, autolink);
    if (debug)
      fprintf (stderr, "command: %s\n", command);
    status = system (command);
    if (status == -1 ||
	(WIFSIGNALED (status) && (WTERMSIG (status) == SIGINT || 
				  WTERMSIG (status) == SIGQUIT)))
      cleanup (1, dir);
    cleanup (WEXITSTATUS (status), dir);
  }
  cleanup (0, dir);
  return 0;
}

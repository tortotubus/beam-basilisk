/**
# Computation kernels */

#include <stdlib.h>
#include <string.h>
#include "ast.h"
#include "symbols.h"

typedef struct {
  char * error;
} KernelData;

static
void kernel (Ast * n, Stack * stack, void * data)
{
  KernelData * d = data;

  if (d->error)
    return;
  
  switch (n->sym) {
    
  /**
  ## Strings (unsupported) */

  case sym_STRING_LITERAL: {
    char s[1000];
    AstTerminal * t = ast_terminal (n);
    snprintf (s, 999, "\\n@error %s:%d: GLSL: error: strings are not supported\\n", t->file, t->line);
    d->error = strdup (s);
    return;
  }    

  /**
  ## Function pointers */

  case sym_IDENTIFIER: {
    if (ast_is_function_pointer (n, stack))
      str_prepend (ast_terminal (n)->start, "_p_");
    break;
  }
    
  /**
  ## Pointers to structures are not supported */

  case sym_PTR_OP: {
    char s[1000];
    AstTerminal * t = ast_terminal (n);
    snprintf (s, 999, "\\n@error %s:%d: GLSL: error: pointers are not supported\\n", t->file, t->line);
    d->error = strdup (s);
    return;
  }

  /**
  ## Remove some reserved GLSL keywords */
    
  case sym_STATIC: case sym_INLINE:
    ast_terminal (n)->start[0] = '\0';
    break;

  /**
  ## Typedef struct */

  case sym_TYPEDEF: {
    Ast * struct1, * identifier;
    if ((struct1 = ast_schema (ast_ancestor (n, 2), sym_declaration_specifiers,
			       1, sym_declaration_specifiers,
			       0, sym_type_specifier,
			       0, sym_types,
			       0, sym_struct_or_union_specifier,
			       0, sym_struct_or_union,
			       0, sym_STRUCT)) &&
	(identifier = ast_schema (ast_ancestor (n, 3), sym_declaration,
				  1, sym_init_declarator_list,
				  0, sym_init_declarator,
				  0, sym_declarator,
				  0, sym_direct_declarator,
				  0, sym_generic_identifier,
				  0, sym_IDENTIFIER))) {
      char * s = ast_terminal (n)->start; s[0] = '\0';
      ast_terminal (n)->start = ast_terminal (struct1)->start;
      ast_terminal (struct1)->start = ast_terminal (identifier)->start;
      ast_terminal (identifier)->start = s;
    }
    break;
  }
    
  case sym_postfix_expression: {
    Ast * list;
    if ((list = ast_schema (n, sym_postfix_expression,
			    3, sym_postfix_initializer,
			    1, sym_initializer_list))) {
      
      /**
      ## Postfix initializers */
      
      Ast * a = n->child[0];
      ast_set_child (n, 0, n->child[1]);
      ast_set_child (n, 1, a);
      a = n->child[3];
      ast_set_child (n, 3, n->child[2]);
      ast_set_child (n, 2, list);
      ast_destroy (a);
    }
    else if (ast_attribute_access (n, stack)) {

      /**
      ## Attribute access */

      if (n->parent->sym == sym_function_call) {
	Ast * identifier = ast_schema (n, sym_postfix_expression,
				       2, sym_member_identifier,
				       0, sym_generic_identifier,
				       0, sym_IDENTIFIER);
	ast_before (n->parent, "_attr_", ast_terminal (identifier)->start, "(");
	ast_terminal (ast_schema (n, sym_postfix_expression,
				  1, token_symbol('.')))->start[0] = ',';
	ast_terminal (identifier)->start[0] = '\0';
	ast_after (n->parent, ")");
      }
      else {
	ast_before (n, "_attr(");
	ast_terminal (ast_schema (n, sym_postfix_expression,
				  1, token_symbol('.')))->start[0] = ',';
	ast_after (n, ")");
      }
    }
    break;
  }

  /**
  ## Cast expressions */

  case sym_cast_expression:
    if (ast_schema (n, sym_cast_expression,
		    1, sym_type_name)) {
      Ast * a = n->child[0];
      ast_set_child (n, 0, n->child[1]);
      ast_set_child (n, 1, a);
      a = n->child[3];
      ast_set_child (n, 3, n->child[2]);
      ast_set_child (n, 2, a);
    }
    break;

  case sym_pointer: {
    Ast * p, * type, * identifier;
    if ((p = ast_schema (n, sym_pointer,
			 0, token_symbol('*'))) &&
	(type = ast_schema (ast_ancestor (n, 2), sym_parameter_declaration,
			    0, sym_declaration_specifiers,
			    0, sym_type_specifier,
			    0, sym_types,
			    0, sym_TYPEDEF_NAME)) &&
	(!strcmp (ast_terminal (type)->start, "scalar") ||
	 !strcmp (ast_terminal (type)->start, "vector") ||
	 !strcmp (ast_terminal (type)->start, "tensor")) &&
	(identifier = ast_schema (n->parent, sym_declarator,
				  1, sym_direct_declarator,
				  0, sym_generic_identifier,
				  0, sym_IDENTIFIER))) {

      /**
      ## Scalar, vector and tensor lists parameters */

      ast_terminal (p)->start[0] = '\0';
      ast_after (identifier, "[12]"); // fixme: need to set the correct fixed size
      //      ast_print_tree (ast_ancestor (n, 2), stderr, 0, 0, -1);
    }
    else if ((identifier = ast_schema (ast_ancestor (n, 2), sym_parameter_declaration,
				       1, sym_declarator,
				       0, sym_pointer,
				       0, token_symbol ('*'))) &&
	     (type = ast_schema (ast_ancestor (n, 2), sym_parameter_declaration,
				 0, sym_declaration_specifiers,
				 0, sym_type_specifier,
				 0, sym_types)) &&
	     (type->child[0]->sym == sym_DOUBLE ||
	      type->child[0]->sym == sym_FLOAT ||
	      type->child[0]->sym == sym_INT)) {
      
      /**
      ## "inout" function parameter */
      
      ast_before (type->child[0], "inout ");
      ast_terminal (identifier)->start[0] = '\0';
    }
    
    break;
  }
    
  /**
  ## forin_declaration_statement */

  case sym_forin_declaration_statement: {
    Ast * declarator = n->child[3];
    Ast * identifier = ast_schema (declarator, sym_declarator,
				   0, sym_direct_declarator,
				   0, sym_generic_identifier,
				   0, sym_IDENTIFIER);
    if (!identifier) {
      AstTerminal * t = ast_left_terminal (n);
      fprintf (stderr,
	       "%s:%d: error: incorrect declaration\n",
	       t->file, t->line);
      exit (1);
    }
    ast_before (n, "{");
    ast_after ((Ast *)ast_right_terminal (n->child[0]), "in");
    ast_after ((Ast *)ast_right_terminal (n->child[2]), ",");
    free (ast_terminal (n->child[4])->start);
    ast_terminal (n->child[4])->start = strdup (",");
    ast_after (n, " endforin()}");
    break;
  }

  /**
  ## forin_statement */

  case sym_forin_statement: {
    int narg = 0;
    foreach_item (n->child[2], 2, expr)
      narg++;
    ast_before (n, "{");
    char suffix[20]; snprintf (suffix, 19, "%d", narg);
    ast_after ((Ast *)ast_right_terminal (ast_child (n, sym_for_scope)), "in", suffix);
    free (ast_terminal (ast_child (n, sym_IDENTIFIER))->start);
    ast_terminal (ast_child (n, sym_IDENTIFIER))->start = strdup (",");
    ast_after (n, " endforin", suffix, "()}");
    break;
  }

  /**
  ## Dereference of "inout" parameters */

  case sym_unary_operator: {
    Ast * identifier, * ref, * type;
    if (n->child[0]->sym == token_symbol ('*') &&
	(identifier = ast_schema (n->parent, sym_unary_expression,
				  1, sym_cast_expression,
				  0, sym_unary_expression,
				  0, sym_postfix_expression,
				  0, sym_primary_expression,
				  0, sym_IDENTIFIER)) &&
	(ref = ast_identifier_declaration (stack, ast_terminal (identifier)->start)) &&
	(type = ast_schema (ast_ancestor (ref, 4), sym_parameter_declaration,
			    0, sym_declaration_specifiers,
			    0, sym_type_specifier,
			    0, sym_types)) &&
	ast_terminal (type->child[0])->before &&
	!strcmp (ast_terminal (type->child[0])->before + strlen (ast_terminal (type->child[0])->before) - 6, "inout ")) {
      free (ast_terminal (n->child[0])->start);
      ast_terminal (n->child[0])->start = strdup("");
    }
    break;
  }
    
  case sym_function_call: {
    Ast * identifier = ast_function_call_identifier (n);
    if (!identifier) break;
    AstTerminal * t = ast_terminal (identifier);
    if (!t) break;
    
    /**
    ## Field assignments 
  
    Kernels often need to know the type of access to fields (i.e. read
    or write). Here we append "_out" to stencil access functions linked
    to assignments (i.e. "write" operations ). */
    
    if (!strcmp (t->start, "val")) {
      if (ast_child (ast_parent (n, sym_assignment_expression), sym_assignment_operator))
	str_append (t->start, "_out_");
      break;
    }

    /**
    ## Undeclared or unsupported functions */
    
    if (!(identifier = ast_identifier_declaration (stack, t->start))) {
      char s[1000];
      snprintf (s, 999, "\\n@error %s:%d: GLSL: error: unknown function '%s'\\n", t->file, t->line, t->start);
      d->error = strdup (s);
      return;
    }
    
    /**
    ## Function pointers */

    if (ast_schema (ast_ancestor (identifier, 3), sym_declarator,
		    0, sym_pointer,
		    0, token_symbol('*'))) {
      char * s = NULL;
      str_append (s, "_f_", t->start);
      free (t->start);
      t->start = s;
      AstTerminal * o = ast_terminal (ast_child (n, token_symbol('(')));
      free (o->start); o->start = strdup ("((");
      AstTerminal * c = ast_terminal (ast_child (n, token_symbol(')')));
      free (c->start); c->start = strdup ("))");
      break;
    }
    
    /**
    ## Function calls */
    
    Ast * definition = ast_parent (identifier, sym_function_definition);
    if (!(identifier = ast_find (definition, sym_direct_declarator,
				 0, sym_direct_declarator,
				 0, sym_generic_identifier,
				 0, sym_IDENTIFIER)) ||
	strcmp (ast_terminal (identifier)->start, t->start))
      break;

    /**
    Here we check for "inout" arguments (i.e. pointers taken using '&'). */
    
    Ast * parameters = ast_find (ast_schema (definition, sym_function_definition,
					     0, sym_function_declaration,
					     1, sym_declarator),
				 sym_direct_declarator,
				 2, sym_parameter_type_list,
				 0, sym_parameter_list);
    Ast * arguments = ast_schema (n, sym_function_call,
				  2, sym_argument_expression_list);
    if (arguments) {
      while (parameters->child[0]->sym == parameters->sym)
	parameters = parameters->child[0];
      Ast * parameter = ast_child (parameters, sym_parameter_declaration);
      foreach_item_r (arguments, sym_argument_expression_list_item, argument) {
	Ast * ampersand, * type, * pointer;
	if ((ampersand = ast_schema (ast_is_unary_expression (argument->child[0]), sym_unary_expression,
				     0, sym_unary_operator,
				     0, token_symbol ('&'))) &&
	    (pointer = ast_schema (parameter, sym_parameter_declaration,
				   1, sym_declarator,
				   0, sym_pointer,
				   0, token_symbol ('*'))) &&
	    (type = ast_schema (parameter, sym_parameter_declaration,
				0, sym_declaration_specifiers,
				0, sym_type_specifier,
				0, sym_types)) &&
	    (type->child[0]->sym == sym_DOUBLE ||
	     type->child[0]->sym == sym_FLOAT ||
	     type->child[0]->sym == sym_INT))
	  ast_terminal (ampersand)->start[0] = '\0';
	parameters = parameters->parent, parameter = ast_child (parameters, sym_parameter_declaration);
	if (!parameter) break;
      }
    }

    break;
  }
    
  }
}

static
char * stringify (Ast * n, char * output)
{
  AstTerminal * t = ast_left_terminal (n);
  char * before = t->before;
  if (n->sym == sym_function_definition)
    t->before = NULL;
  char * s = ast_str_print (n, NULL, 0, 1);
  t->before = before;
  for (char * i = s; *i; i++) {
    char a[] = "1";
    switch (*i) {
    case '\n': str_append (output, "\\n"); break;
    case '\\': str_append (output, "\\\\"); break;
    case '"':  str_append (output, "\\\""); break;
    case '#':
      if (i[-1] == '\n') { str_append (output, "// #"); break; }
      // fall through
    default:  a[0] = *i; str_append (output, a); break;
    }
  }
  free (s);
  ast_destroy (n);
  return output;
}

char * ast_kernel (Ast * n, Ast * argument, char * s)
{
  AstRoot * root = ast_get_root (n);
  Stack * stack = root->stack;
  stack_push (stack, &n);
  KernelData d = {0};
  Ast * statement = n->sym == sym_function_definition ?
    ast_copy (n) : ast_copy (ast_child (n, sym_statement));
  ast_traverse (statement, stack, kernel, &d);

  if (d.error) {
    if (argument)
      ast_after (argument, ".kernel=$(\"", d.error, "\")");
    else
      str_append (s, "$(\"", d.error, "\")");
  }
  else {
    if (argument)
      ast_after (argument, ".kernel=$(\"");
    else
      str_append (s, "$(\"");
    s = stringify (statement, s);
    if (argument)
      ast_after (argument, s, "\")");
    else
      str_append (s, "\")");
  }
  free (d.error);
  ast_pop_scope (stack, n);
  return s;
}

/**
# Einstein summation notation

This header file contains all the functions related to the Einstein summation macro used by the $\texttt{Basilisk C}$ preprocessor. This macro allows the user to write tensor algebra in index notation using $\texttt{Basilisk C}$ code. The syntax follows the famous [Einstein summation convention](https://en.wikipedia.org/wiki/Einstein_notation).

### Mathematical definitions
Let us give the basis of the Einstein summation convention through the example of a simple scalar product between two second-order tensors in $3D$ space. In mathematics and physics, it is customary to write second-order tensors as $\textbf{A} = \sum_{i,j = 1}^3 A_{ij} \bm e_i\bm e_j$ where $\bm e_i$ and $\bm e_j$ are basis vectors in $3D$ space and $A_{ij}$ is the component of the tensor $\textbf A$ projected on the vectors $\bm e_i\bm e_j$. In tensor notation the inner product between two arbitrary second-order tensors : $\textbf{A}$ and $\textbf{B}$, can be written as $\textbf{C} =  \textbf{A}\cdot\textbf{B}$. If the basis is orthonormal, the components of the tensor $\textbf C$ are given by :
$$ C_{ij} = \sum_{k=1}^3 A_{ik} B_{kj}.  $$
Since the summation operator can be quite cumbersome in the Einstein summation convention we rewrite this operation as, 
$$ C_{ij} = A_{ik} B_{kj} $$. 
where the summation over $k$ from $1$ to $3$ is made implicit.
We took the example of a simple scalar product, nevertheless notice that this notation extends to any tensor operations which might be a lots more complex.   
Therefore, to remove any ambiguity to the Einstein summation notation one has to follow these rules :
1. Each index can appear at most twice in any term.
2. Repeated indices are implicitly summed over. 
3. Each term must contain identical non-repeated indices.


For example the expression : $M_{ij}v_iv_j$ is valid and indicate a double summation over $i$ and $j$. 
While the rexpression $M_{ij}v_ju_j$ is ambigous since the index $j$ appear $3$ times. 
For a more complete and rigourous definition of the Einstein summation convention we recommand the wiki page : [Einstein summation convention](https://en.wikipedia.org/wiki/Einstein_notation). 


### User interface

To write a scalar product in $\texttt{Basilisk C}$ one needs first to define vector and second-order tensor-like structures. The default vector structure is the "coord" struct. The second or higher-order structures must be defined by the user. 
```
typedef struct {
  coord x,y,z;
}tensor;
tensor A,B,C; 
```
Note that the name "tensor" is arbitrary. However, the name of the structure's members must read as, $x$, $y$ and $z$. Following the Einstein summation convention the scalar product introduced in the previous paragraph can be encoded in $\texttt{Basilisk C}$ as, 
```
einstein_sum(i,j,k){
  C.i.j = A.i.k * B.k.j; 
}
```
With this macro, the preprocessor of $\texttt{Basilisk C}$ interprets all lines of code within the braces as tensor operations. The letters given within the parenthesis indicate the indices on which the Einstein summation takes place. In this case a summation will be applied on the index $k$ and permutations will be performed on the indices $i$ and $j$. 
To verify that the $\texttt{Basilisk C}$ preprocessor gives the desired results, one can precompile the $\texttt{Basilisk C}$ file with the command line
```
qcc -source my_file.c
```
The results of the precompilation stored in "_my_file.c" will be,
``` 
{
  C.x.x = A.x.x * B.x.x+ A.x.y * B.y.x+ A.x.z * B.z.x;
  C.x.y = A.x.x * B.x.y+ A.x.y * B.y.y+ A.x.z * B.z.y;
  C.x.z = A.x.x * B.x.z+ A.x.y * B.y.z+ A.x.z * B.z.z;
  C.y.x = A.y.x * B.x.x+ A.y.y * B.y.x+ A.y.z * B.z.x;
  C.y.y = A.y.x * B.x.y+ A.y.y * B.y.y+ A.y.z * B.z.y;
  C.y.z = A.y.x * B.x.z+ A.y.y * B.y.z+ A.y.z * B.z.z;
  C.z.x = A.z.x * B.x.x+ A.z.y * B.y.x+ A.z.z * B.z.x;
  C.z.y = A.z.x * B.x.y+ A.z.y * B.y.y+ A.z.z * B.z.y;
  C.z.z = A.z.x * B.x.z+ A.z.y * B.y.z+ A.z.z * B.z.z;
}
```
Note that the preprocessor duplicated the lines for each permutation of $i$ and $j$ and applied a summation over the index $k$. This macro also applies to $\texttt{Basilisk C}$ vector fields (such as the velocity field "u.x[]") and any other user-defined structures with members named $x$, $y$ and $z$.  

For higher-order rank tensors one can remark that these expressions become quite cumbersome.
It is for that reason that the "einstein_sum" macro has been created. 
For more examples one can check the test file [einstein_sum.c](http://basilisk.fr/src/test/einstein_sum.c). 

### Specific cases 

As long as the user follows the rules mentioned above, the desired result will be obtained. 
However, the "einstein_sum" macro is somewhat more permissive than the original rules of the convention. 
For example the code
```
U.i = M.i.j*u.j*v.j;
```
which is **wrongly defined** will still be compiled, and in $2D$ it will gives, 
```
U.x = M.x.x*u.x*v.x + M.x.y*u.y*v.y;
U.y = M.y.x*u.x*v.x + M.y.y*u.y*v.y;
```

The use of C functions within the macro is also allowed. 
Let "function(args)" be an arbitrary C function. 
Then the expression, 
```
U.i = function(M.i.j*u.j*v.j);
```
will be expanded to, 
```
U.x = function(M.x.x*u.x*v.x + M.x.y*u.y*v.y);
U.y = function(M.y.x*u.x*v.x + M.y.y*u.y*v.y);
```
The summation is applied at the lowest level of the expression where all the indices that must be summed over are present. 
Here the summation takes place inside the paranthesis since all indices "j" are contained within them. 

A useful example of the use of a function is the one of the L2 norm of the second-order tensor $\textbf C$. 
It can be computed as, 
```
Norm = sqrt(C.i.j*C.i.j);
```


Lastly, if no equality sign is identified, then the preprocessor will not perform any summation operations. It will only carry the permutation on the present line of code. For example if one wants to print the content of a tensor he may write 
```
  einstein_sum(i,j){
    fprintf(qerr,"%g\n",C.i.j);
  }
```
which gives in $2D$, 
```
fprintf(qstderr(),"%g %g\n",C.x.x);
fprintf(qstderr(),"%g %g\n",C.x.y);
fprintf(qstderr(),"%g %g\n",C.y.x);
fprintf(qstderr(),"%g %g\n",C.y.y);
```


### Conclusion

In summary, the "einstein_sum" macro follows these steps :
1. It Identifies if a given line of code is an assignment expression with a '=' sign or not. 
   1. If it is, it identifies the indices on the right and left-hand side of the expression. 
   Then, it carries a summation of the indices that appear only on the right-hand side. 
   2. If it is not an equality, it does nothing at this step. 
2. Then it copies past the lines of codes and carries permutations on the indices present on the line (excluding the one that has been summed over). 
3. Repeat steps 1. and 2. for all lines within the macro. 
  
> **Warning**
> Note that these steps do not follow the original Einstein summation convention rules. 
> Therefore some expressions are in any case ambiguous and thus treated arbitrarily. 
> Consequently, the user is advised to always check for the pre-compiler results using "qcc -source my_file.c" before using his code. 

 */


// This structure carries information about the indices present in the 
// expression
typedef struct {
  int dimension;
  char * current_id, * forbiden_id;
} Einstein_sumData;

// This function append a block to an expression with a "+" sign separator
Ast * ast_add_list_append (Ast * list, int item_sym, Ast * item)
{
  ast_set_line (item, ast_right_terminal (list));
  Ast * parent = list->parent;
  int index = ast_child_index (list);
  Ast * l =  ast_new_children (ast_new (parent, list->sym),
			       list, 
			       ast_terminal_new_char (item, "+"),
			       ast_new (item, item_sym));
  ast_attach (l->child[2], item);
  ast_set_child (parent, index, l);
  return l;
}

// Reads the input id list given to the macro
static void einstein_sum_id_list(Ast * n, Stack * stack, void * data){
  if(n->sym == sym_IDENTIFIER){
    AstTerminal * t = ast_terminal (n);
    if(strlen(t->start) > 1){
      fprintf (stderr,
"%s:%d: error: the args of einstein_sum(...,%s,...) must be of length one\n",
              t->file, t->line,t->start);
      exit (1);
    }
    char * id_list = data;
    char first_char[2];
    first_char[0] = *t->start,first_char[1] = '\0';
    strcat(id_list,first_char);
  }
}

static char * get_einstein_sum_args(Ast * n, Stack * stack){    
  // stop when the macro eintein sum is found
  Ast * ein_macro = n;
  char * indentifier = "init";
  while (strcmp(indentifier,"einstein_sum"))
  {
    ein_macro = ast_parent(n, sym_macro_statement);
    indentifier = ast_terminal(ast_schema (ein_macro, sym_macro_statement,
                             0, sym_function_call,
                             0, sym_postfix_expression,
                             0, sym_primary_expression,
                             0, sym_IDENTIFIER))->start;
  }
  // gather the args in the buffer
  char buffer[100] = {0};
  ast_traverse (ein_macro->child[0]->child[2],
               stack, einstein_sum_id_list , buffer);
  int length = strlen(buffer);
  buffer[length] = '\0';
  char * indices = malloc((length+1) * sizeof(char));
  strcpy(indices,buffer);
  return indices;
}

static void einstein_sum_get_member_id(Ast * n, Stack * stack, void * data){
  if(n->sym == sym_member_identifier){
    AstTerminal * t = ast_terminal (ast_schema (n, 
                                                sym_member_identifier,
                                                0, sym_generic_identifier,
                                                0, sym_IDENTIFIER));
    char * sub_id_list = data;
    char * id_list = get_einstein_sum_args(n,stack);
    char first_char[2];
    first_char[0] = *t->start,first_char[1] = '\0';
    if(strchr(id_list,*t->start))
      strcat(sub_id_list,first_char);
  }
}


static Ast * get_expression_statement(Ast * n){
  while (n->sym != sym_expression_statement && n->sym == sym_expression)
    n = n->parent;  
  return n;
}

// get all the indicies present in the block (Ast * n)
static char * get_expression_id(Ast * n, Stack * stack){
  char buffer[100] = {0};
  ast_traverse (n, stack, einstein_sum_get_member_id , buffer);
  int length = strlen(buffer);
  buffer[length+1] = '\0';
  char * sub_id_list = malloc(80 * sizeof(char));
  strcpy(sub_id_list,buffer);
  return sub_id_list;
}

// return the right-hand-side of an expression from a lower level block
static Ast * get_right_hand_side(Ast * n, Stack * stack){    
  // stop when the macro eintein sum is found
  Ast * right_hand_side = n;
  while(!ast_child(right_hand_side,sym_assignment_operator))
    right_hand_side = ast_parent(right_hand_side, sym_assignment_expression);
  right_hand_side = ast_child(right_hand_side,sym_assignment_expression);
  return right_hand_side;
}

// permute the .i by .i_x
static void einstein_sum_repace_id (Ast * n, Stack * stack, void * data)
{
  switch (n->sym) {
  case sym_member_identifier: {
    AstTerminal * t = ast_terminal (ast_schema (n, 
                                                sym_member_identifier,
                                                0, sym_generic_identifier,
                                                0, sym_IDENTIFIER));
    char * id_list = get_einstein_sum_args(n,stack);
    if (t->start[1] == '\0' && strchr (id_list, *t->start))
      // char * id_old
      strcat(t->start,"_x");
    break;
  } 
  }
}

// Increment the _x to _y or _z and so on 
static void einstein_sum_rotate (Ast * n, Stack * stack, void * data)
{
  switch (n->sym) {
  case sym_member_identifier: {
    AstTerminal * t = ast_terminal (ast_schema (n, 
                                                sym_member_identifier,
                                                0, sym_generic_identifier,
                                                0, sym_IDENTIFIER));
    int len = strlen (t->start);
    Einstein_sumData * d = data;
    if (len >= 2 && t->start[len - 2] == '_' &&
	      strchr ("xyz", t->start[len - 1]) &&
        t->start[0] == d->current_id[0]) 
      t->start[len - 1] = 'x' + (t->start[len - 1] + 1 - 'x') % d->dimension;
  }
  }
}

// This funciton perform the summation step within an expression 
static void einstein_sum_sum(Ast * n, Stack * stack,void * data){
  if(n->sym == sym_additive_expression 
  || n == get_right_hand_side(n,stack)
  ){
    Einstein_sumData * d = data;

    Ast * body = ast_last_child(n);
    if( n == get_right_hand_side(n,stack))
    while (body->sym != sym_additive_expression)
      body = ast_last_child(body);
      

    char * current_id_list = get_expression_id(body,stack);
    // indentify the list of the indicies on the right hand side of the expr 
    Ast * right_hand_side = get_right_hand_side(body,stack);
    char * id_list_after = get_expression_id(right_hand_side,stack);
    // list that contain index to be summed
    char sum_id[80];
    int j=0;
    for(int i = 0;i<strlen(current_id_list);i++){
      int k =0; 
      int m=0;
      // check how many times the index appear in the expr
      for (int l=0;l<strlen(current_id_list);l++)
        if(current_id_list[l] == current_id_list[i])
          k++;
      // check how many times the index appear in the original expr
      for(int l=0;l<strlen(id_list_after);l++)
        if(id_list_after[l]==current_id_list[i])
          m++;
      
      if(!strchr(d->forbiden_id,current_id_list[i]) && 
        !strchr(sum_id,current_id_list[i]) && k==m){
        sum_id[j] = current_id_list[i];
        j++;
      }
      sum_id[j] = '\0';
    }

    int id_N = strlen(sum_id);
    if(!j) {
      id_N = 0;
      sum_id[0] = '\0';
    }
    d->current_id = malloc(sizeof(char)*2);
    d->current_id[1]='\0';
    for(int i = 0; i<id_N; i++){
      d->current_id[0] = sum_id[i];
      Ast * copy = body;
      for (int j = 1; j < d->dimension; j++){ 
        // perform the rotation on the index that mus be summed 
        copy = ast_copy(copy);
        stack_push (stack, &copy);
        ast_traverse (copy, stack, einstein_sum_rotate, d);
        ast_pop_scope (stack, copy);  
        body = ast_add_list_append(body,copy->sym,copy);
      }
    }
    strcat(d->forbiden_id,sum_id);
  }
}

static void einstein_sum_repace_id_back (Ast * n, Stack * stack, void * data)
{
  switch (n->sym) {
  case sym_member_identifier: {
    AstTerminal * t = ast_terminal (ast_schema (n, 
                                                sym_member_identifier,
                                                0, sym_generic_identifier,
                                                0, sym_IDENTIFIER));
    char * id_list = get_einstein_sum_args(n,stack);
    int len = strlen(t->start);
    if (t->start[len - 2] == '_' &&
	      strchr ("xyz", t->start[len - 1]) &&
	      strchr (id_list, t->start[len - 3]))
        t->start[1] = '\0',t->start[0] = t->start[len - 1] ;
    break;
  } 
  }
}

static void einstein_sum_expression (Ast * n, Stack * stack, void * data)
{ 
  if(n->sym == sym_assignment_expression &&
    get_expression_statement(n->parent)->sym == sym_expression_statement &&
    get_expression_statement(n->parent)->parent->sym == sym_statement &&
    n->parent->sym == sym_expression){
    Einstein_sumData * d = data;
    
    // transform into block item 
    Ast * expr_statement = get_expression_statement(n->parent);
    Ast * statement = get_expression_statement(n->parent)->parent;
    Ast * item = ast_block_list_get_item (statement);
      if(!item) item = get_expression_statement(n->parent);
    Ast * item_list = item->parent;

    /**
     This is the first step, it just permute every indicies such as .i into 
     .i_x and so on. 
     */
    stack_push (stack, &item);
    ast_traverse (item, stack, einstein_sum_repace_id, d);
    ast_pop_scope (stack, item);  
    
    /**
     The second step identify and perform the summation. 
     */
    char * id_list_before = get_expression_id(n,stack);
    int id_N = strlen(id_list_before);
    // check if the expression is an equallity  
    if(ast_child(n,sym_assignment_operator)){
      Ast * right_hand_side = ast_child(n,sym_assignment_expression);
      Ast * left_hand_side = ast_child(n,sym_unary_expression);
      // indices appearing on the left hands side of the expression
      id_list_before = get_expression_id(left_hand_side,stack);
      // save the indices appearing on the left hands side
      d->forbiden_id = malloc(sizeof(char)*80);
      strcpy(d->forbiden_id,id_list_before);
      // traverse over the whole expression and perform sum
      stack_push (stack, &right_hand_side);
      ast_traverse (right_hand_side, stack, einstein_sum_sum, d);
      ast_pop_scope (stack, right_hand_side);  
      id_N = strlen(id_list_before);
    }

    // Remove any duplicates in "id_list_before"
    for (int i = 0; i < id_N; i++)
      for (int j = i + 1; j < id_N;){
        if (id_list_before[i] == id_list_before[j]){
          for (int k = j; k < id_N; k++){
            id_list_before[k] = id_list_before[k + 1];
            id_N--;
          }
        }else{
          j++;
        }
      }

    /**
     The final step is to perform permutaions on the remaining indcies
     */
    d->current_id = malloc(2*sizeof(char));
    d->current_id[0] ='\0';
    for(int i = 0;i<id_N;i++){
      d->current_id[0] = id_list_before[id_N -(i+1)];
      Ast * copy = expr_statement;
      for (int j = 1; j < d->dimension; j++){ 
        copy = ast_copy(copy);
        stack_push (stack, &copy);
        ast_traverse (copy, stack, einstein_sum_rotate, d);
        ast_pop_scope (stack, copy);  
        expr_statement = ast_block_list_append(expr_statement,copy->sym,copy);
      }
    }
    // replace the i_x indicators by the actual member name x,yz...
    stack_push (stack, &item_list);
    ast_traverse (item_list, stack, einstein_sum_repace_id_back, d);
    ast_pop_scope (stack, item_list);  
  }
}

static void einstein_sum_global (Ast * n, Stack * stack, int dimension)
{
  Ast * item = ast_block_list_get_item (n->parent->parent);
  Einstein_sumData data = {dimension,NULL,NULL}; 
  if(n->child[0]->child[2]->sym == 85){ // 85 correspond to ')' sign
    AstTerminal * t = ast_left_terminal (n);
    fprintf (stderr,
            "%s:%d: error: you must express indices as input in macro : einstein_sum(...) \n",
            t->file, t->line);
    exit (1);
  }
  Ast * body = ast_last_child (n);
  stack_push (stack, &body);
  ast_traverse (body, stack, einstein_sum_expression, &data);
  ast_pop_scope (stack, body); 
  // remove macro name and append the body 
  ast_replace_child(item,0,body);
  ast_remove (n, ast_left_terminal (body));
}

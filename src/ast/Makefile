CFLAGS += -Wall -g -I$(BASILISK)

libast.a: ast.o tokens.o basilisk.o translate.o typedef.o allocator.o
	ar cr $@ $^

basilisk.c: basilisk.yacc
	bison -Dparse.trace -d -o basilisk.c basilisk.yacc
	sed -i 's/^ *YY_REDUCE_PRINT *(yyn);/ YY_REDUCE_PRINT (yyn); DEFAULT_ACTION (yyn);/' basilisk.c

symbols.h: basilisk.c Makefile
	echo "// Automatically generated from basilisk.yacc" > symbols.h
	@echo 'const char * symbol_name (int sym);' >> symbols.h
	@echo 'int token_symbol (int token);' >> symbols.h
	@awk '/^enum yysymbol_kind_t/{a=1}{if(a)print $$0;}/};/{a=0}' \
		basilisk.c | sed 's/YYSYMBOL_/sym_/g' >> symbols.h

tokens.c: tokens.lex
	flex -o tokens.c tokens.lex

basilisk.o: ast.h parser.h

ast.o: ast.h parser.h symbols.h

typedef.o: ast.h parser.h symbols.h

tokens.o: ast.h basilisk.c

translate.o: ast.h symbols.h

allocator.o: allocator.h

clean:
	rm -f *.o *.a

qcc: qcc.c libast.a
	$(CC) $(CFLAGS) -o $@ $^

expr: expr.c ast.h libast.a
	$(CC) $(CFLAGS) -o $@ $< -L. -last

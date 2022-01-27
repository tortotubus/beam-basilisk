CFLAGS += -Wall -g -I$(BASILISK)

libbasilisk.a: node.o tokens.o basilisk.o transform.o
	ar cr $@ $^

basilisk.c: basilisk.yacc
	bison -Dparse.trace -d -o basilisk.c basilisk.yacc
	sed -i 's/# define YY_REDUCE_PRINT(Rule)$$//' basilisk.c

symbols.h: basilisk.c Makefile
	echo "// Automatically generated from basilisk.yacc" > symbols.h
	@echo "#define YY_NULLPTR NULL" >> symbols.h
	@awk '/static const char \*const yytname/ {a=1}{if(a)print $$0;}/};/{a=0}' basilisk.c >> symbols.h
	@awk '/^enum yysymbol_kind_t/{a=1}{if(a)print $$0;}/};/{a=0}' \
		basilisk.c | sed 's/YYSYMBOL_/sym_/g' >> symbols.h

tokens.c: tokens.lex
	flex -o tokens.c tokens.lex

basilisk.o: node.h 

node.o: node.h symbols.h

tokens.o: node.h basilisk.c

transform.o: node.h symbols.h

clean:
	rm -f *.o *.a

qcc: qcc.c libbasilisk.a
	$(CC) $(CFLAGS) -o $@ $^

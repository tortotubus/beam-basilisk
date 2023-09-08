BASILISK=$(subst /ast/interpreter,,$(CURDIR))
CFLAGS += -I../.. -I.. -DBASILISK=\"$(BASILISK)\"
QCC = ../../qcc

interpreter.o: dimension.c graph.c ../ast.h ../symbols.h

check: $(subst .c,.tst,$(wildcard test*.c)) \
	test15.vtst test16.vtst test20.vtst \
	$(subst .c,.dtst,$(wildcard dimension-tests/test*.c))

refs:
	for f in dimension-tests/test*.c; do 				\
		$(QCC) -source -dimensions -run=1 $$f 2>&1 | 		\
                sed "s|$(BASILISK)||g" > `echo $$f | sed 's/\.c/.ref/'`; \
	done

%.tst: %.c %.ref $(QCC)
	$(QCC) -source -run=1 $< 2>&1 | sed "s|$(BASILISK)||g" > $@
	-rm -f _$<
	diff $@ $*.ref || (rm -f $@ && exit 1)

%.dtst: %.c %.ref $(QCC)
	$(QCC) -source -dimensions -run=1 $< 2>&1 | sed "s|$(BASILISK)||g" > $@
	diff $@ $*.ref || (rm -f $@ && exit 1)

%.vtst: %.c %.ref $(QCC)
	valgrind -q $(QCC) -source -run=1 $< 2>&1 | sed "s|$(BASILISK)||g" > $@
	-rm -f _$<
	diff $@ $*.ref || (rm -f $@ && exit 1)

clean:
	rm -f *.o *.a *.*tst

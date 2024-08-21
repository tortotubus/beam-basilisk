#!/bin/bash

while true; do
    cd /home/basilisk-wiki/wiki
    for d in `darcs show files --no-files`; do
	if test -d $d -a -f $d/Makefile.tests; then
	    alltests=$(cat <<EOF | make -s -f - target
include $d/Makefile.tests
target:
	echo \$(ALLTESTS)
EOF
		    )
	    for f in $alltests; do
		basename=`basename $f .c`
		if test -d $d/$basename -a -f $d/$basename.s.d; then
		    while ssh $SANDBOX tsp | grep running > /dev/null; do sleep 60; done
		    cd $d
		    if test -f Makefile; then
			makefile=Makefile
		    else
			makefile=/home/basilisk-wiki/wiki/sandbox/Makefile
		    fi
		    echo running $d/$f
		    make -f $makefile $basename.tst
		    cd /home/basilisk-wiki/wiki
		    sleep 5
		fi
	    done
	fi
    done
done

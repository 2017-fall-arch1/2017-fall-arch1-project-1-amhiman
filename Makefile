all: bstMain

CFLAGS=-g -O3

# $@ target
# $^ prerequisites

bstMain: bst.o bstMain.o
	cc -o $@ $^

bst.o: bst.c bst.h
	cc -c $(CFLAGS) bst.c

bstMain.o: bstMain.c bst.h
	cc -c $(CFLAGS) bstMain.c

clean:
	rm -f *.o bstMain

demo: bstMain
	./bstMain 

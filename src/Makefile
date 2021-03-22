all: tokenizer.o history.o gui.o
	gcc -o test tokenizer.o history.o  

tokenizer.o: tokenizer.c tokenizer.h
	gcc -c tokenizer.c

history.o: history.c history.h
	gcc -c history.c

gui.o: gui.c
	gcc -c gui.c
	gcc -o test gui.o

clean:
	rm -f *.o *.c~ tokenizer

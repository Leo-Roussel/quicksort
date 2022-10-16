CC = gcc
CFLAGS = -ansi -Wall -pedantic -c
LDFLAGS =
EXEC = test.out main.out
.PHONY: all run clean fclean 
all: $(EXEC)
%.out: %.o 
	$(CC) -o $@ $^ $(LDFLAGS)
%.o: %.c
	$(CC) -o $@ $(CFLAGS) $<
test.out: test.o quicksort.o
test.o: quicksort.c quicksort.h
quicksort.o: quicksort.c
main.out: main.o quicksort.o
main.o: quicksort.c quicksort.h
run:
	./test.out && ./main.out
clean:
	rm *.o
fclean: clean
	rm $(EXEC)

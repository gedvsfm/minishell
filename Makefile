.PHONY:clean
CC=gcc
CFLAGS=-Wall -g
BIN=minishell
<<<<<<< HEAD
OBJS=main.o parse.o init.o execute.o builtin.o
=======
OBJS=main.o parse.o
>>>>>>> f45601bf0c043f4bf38953fd6a39650096daa65d
$(BIN):$(OBJS)
	$(CC) $(CFLAGS) $^ -o $@
%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f *.o $(BIN)

CC = gcc
CFLAGS = -g -Wall -lm
BIN = tp3
XFLAGS1 = -a 100 -b brasilia -c 199.9 -d 9 -e .9 -f 1.9 -g heuristica
XFLAGS2 = -a
XFLAGS3 = -a
XFLAGS4 = -a
XFLAGS5 = -a
RM = *.o *.h.gch $(BIN)

grafo: grafo.c grafo.h
	$(CC) -c grafo.c grafo.h $(CFLAGS)

io: io.c io.h
	$(CC) -c io.c io.h $(CFLAGS)

geografia: geografia.c geografia.h
	$(CC) -c geografia.c geografia.h $(CFLAGS)

main: grafo io geografia tp3.c
	$(CC) -o $(BIN) tp3.c grafo.o io.o geografia.o $(CFLAGS)

valgrind: clean all
	valgrind ./$(BIN) $(XFLAGS1)
all: main

clean:
	rm -rf $(RM)

run: clean all
	./$(BIN) $(XFLAGS1)

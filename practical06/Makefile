CC = gcc
CCFLAGS = -O3 -Wall
LDFLAGS = -lm

all: Matmultc

Matmultc: Main.o Matmult.o
	$(CC) -o $@ $^ $(LDFLAGS)
##$(CC) -o Matmultc Main.o Matmult.o $(LDFLAGS)

Matmult.o: Matmult.c
	$(CC) -c $(CCFLAGS) $<
##$(CC) -c $(CCFLAGS) Matmult.c

Main.o: Main.c
	$(CC) -c $(CCFLAGS) $<
##$(CC) -c $(CCFLAGS) Main.c

clean:
	rm *.o

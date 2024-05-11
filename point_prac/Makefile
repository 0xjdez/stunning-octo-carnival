
CC=gcc
CFLAGS= -Wall -Wextra

all: final

final: main.o point.o
	$(CC) $(CFLAGS) main.o point.o utils.o -o final

main.o: main.c
	$(CC) $(CFLAGS) -c main.c utils.c

point.o: point.c
	$(CC) $(CFLAGS) -c point.c

utils.o: utils.c
	$(CC) $(CFLAGS) -c utils.c

clean:
	rm main.o point.o utils.o final
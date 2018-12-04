#make file for car parking system
CC=gcc
CFLAGS=-I.
LIBS =  -lpthread
DEPS =

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

carpark:main.o
	gcc -o  carpark main.c ${LIBS}
clean:
	rm -f *.o carpark

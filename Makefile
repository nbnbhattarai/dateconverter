CC = gcc
CFLAGS = -Wall -g
EXECUTABLE = ndc

HEADERFILES = util.h dateconverter.h

all: $(EXECUTABLE)

$(EXECUTABLE): util.o dateconverter.o dc.o
	$(CC) util.o dateconverter.o dc.o  -o $(EXECUTABLE)

util.o: util.c $(HEADERFILES)
	$(CC) -c util.c

dateconverter.o: dateconverter.c $(HEADERFILES)
	$(CC) -c dateconverter.c

dc.o: dc.c $(HEADERFILES)
	$(CC) -c dc.c

clean:
	rm -f *.o
	rm -f $(EXECUTABLE)

# this is makefile for dateconverter
# copyright (c) 2014, Nabin Bhattarai

CC = gcc
CFLAGS = -Wall -g
EXECUTABLE = ndc

HEADERFILES = util.h dateconverter.h

all: $(EXECUTABLE)

$(EXECUTABLE): util.o dateconverter.o dc.o
	@echo "Compiling..."
	@$(CC) util.o dateconverter.o dc.o  -o $(EXECUTABLE)
	@echo "Compiled Successfully."

util.o: util.c $(HEADERFILES)
	@$(CC) -c util.c

dateconverter.o: dateconverter.c $(HEADERFILES)
	@$(CC) -c dateconverter.c

dc.o: dc.c $(HEADERFILES)
	@$(CC) -c dc.c
install:
	@cp ndc /usr/bin/
	@echo Package Installed
clean:
	@rm -f *.o
	@rm -f $(EXECUTABLE)

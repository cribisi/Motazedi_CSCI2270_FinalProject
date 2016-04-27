#Makefile for finalProject
PROG=final
CC=g++
OBJS=main.o MovieCatalog.o
CPPFLAGS= -Wall -std=c++11

$(PROG): $(OBJS)
	$(CC) $(CPPFLAGS) -o $(PROG) $(OBJS)
main.o: main.cpp
	$(CC) -c $(CPPFLAGS) main.cpp
MovieCatalog.o: MovieCatalog.h MovieCatalog.cpp
	$(CC) -c $(CPPFLAGS) MovieCatalog.cpp
clean:
	$(RM) $(PROG) $(OBJS)

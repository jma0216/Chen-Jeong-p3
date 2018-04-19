all: size newer dirlist forkpid

size: size.o
	g++ -o size size.o

newer: newer.o
	g++ -o newer newer.o

dirlist: dirlist.o
	g++ -o dirlist dirlist.o

forkpid: forkpid.o
	g++ -o forkpid forkpid.o

size.o: size.cpp
	g++ -c size.cpp -Wall -std=c++14 -g -O0 -pedantic-errors

newer.o: newer.cpp
	g++ -c newer.cpp -Wall -std=c++14 -g -O0 -pedantic-errors

dirlist.o: dirlist.cpp
	g++ -c dirlist.cpp -Wall -std=c++14 -g -O0 -pedantic-errors

forkpid.o: forkpid.cpp
	g++ -c forkpid.cpp -Wall -std=c++14 -g -O0 -pedantic-errors

clean:
	rm size newer dirlist forkpid size.o newer.o dirlist.o forkpid.o

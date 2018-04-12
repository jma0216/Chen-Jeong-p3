all: cat wc false true env

cat: cat.o
	g++ -o cat cat.o

wc: wc.o
	g++ -o wc wc.o

false: false.o
	g++ -o false false.o

true: true.o
	g++ -o true true.o

env: env.o
	g++ -o env env.o

cat.o: cat.cpp
	g++ -c cat.cpp -Wall -std=c++14 -g -O0 -pedantic-errors

wc.o: wc.cpp
	g++ -c wc.cpp -Wall -std=c++14 -g -O0 -pedantic-errors

false.o: false.cpp
	g++ -c false.cpp -Wall -std=c++14 -g -O0 -pedantic-errors

true.o: true.cpp
	g++ -c true.cpp -Wall -std=c++14 -g -O0 -pedantic-errors

env.o: env.cpp
	g++ -c env.cpp -Wall -std=c++14 -g -O0 -pedantic-errors

clean:
	rm cat wc false true env cat.o wc.o false.o true.o env.o

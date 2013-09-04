bitt:main.o bittree.o
	g++ -o bitt main.o bittree.o
bittree.o:bittree.cpp
	g++ -c bittree.cpp
main.o:main.cpp bittree.h
	g++ -c main.cpp
clean:
	rm *~ *.o

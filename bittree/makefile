bitt:main_int.o bittree_int.o
	g++ -o bitt main_int.o bittree_int.o
bittree_int.o:bittree_int.cpp
	g++ -c bittree_int.cpp
main_int.o:main_int.cpp bittree_int.h
	g++ -c main_int.cpp


bitt_t:main.o
	g++ -o bitt main.o 
main.o:main.cpp bittree.h
	g++ -c main.cpp

clean:
	rm *~ *.o


Checkers: main.o Grid.o
	g++ -Wall -g -o Checkers main.o Grid.o

main.o: main.cpp Grid.h
	g++ -Wall -g -c main.cpp

Grid.o: Grid.cpp Grid.h
	g++ -Wall -g -c Grid.cpp

clean: rm -f *.o

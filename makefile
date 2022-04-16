compile:
	g++ -c -Wall -pedantic-errors Sorting.cpp
	g++ -c -Wall -pedantic-errors main.cpp

link: compile
	g++ -o main main.o Sorting.o

clean:
	rm -f main Sorting.o main.o

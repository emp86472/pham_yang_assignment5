compile2:
	g++ -c -Wall -pedantic-errors Sorting.cpp
	g++ -c -Wall -pedantic-errors main2.cpp

compile1:
	g++ -c -Wall -pedantic-errors Sorting.cpp
	g++ -c -Wall -pedantic-errors main.cpp

link1: compile1
	g++ -o main main.o Sorting.o

link2: compile2
	g++ -o main2 main2.o Sorting.o

clean:
	rm -f main Sorting.o main.o
	rm -f main2 Sorting.o main2.o

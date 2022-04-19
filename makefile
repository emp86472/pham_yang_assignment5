MAIN = main

compile:
	g++ -c -Wall -pedantic-errors Sorting.cpp
	g++ -c -Wall -pedantic-errors $(MAIN).cpp

link: compile
	g++ -o $(MAIN) $(MAIN).o Sorting.o

run: link
	./$(MAIN) random.txt

clean:
	rm -f $(MAIN) Sorting.o $(MAIN).o

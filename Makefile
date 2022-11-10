output: main.o person.o match.o
	g++ main.o person.o match.o -o output

main.o: main.cpp
	g++ -c main.cpp

person.o: ./entities/person.cpp 
	g++ -c ./entities/person.cpp

match.o: ./entities/match.cpp
	g++ -c ./entities/match.cpp

remove:
	rm *.o

run: output
	./output

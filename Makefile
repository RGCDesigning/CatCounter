catcounter: main.o catcounter.o
	g++ main.o catcounter.o -o catcounter

main.o: main.cpp
	g++ -c main.cpp

catcounter.o: ./src/catcounter.cpp
	g++ -c ./src/catcounter.cpp

clean:
	rm -f *.o catcounter
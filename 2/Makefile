main: main.o solver.o
	g++ main.o solver.o -o main \
	&& ./main

main.o: main.cpp
	g++ -c main.cpp -o main.o

solver.o: solver.h solver.cpp
	g++ -c solver.cpp -o solver.o

clean:
	rm -f main main.o solver.o
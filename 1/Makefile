main: main.o solver.o
	g++ solver.o main.o -o main \
	&& ./main

main.o: main.cpp
	g++ -c main.cpp -o main.o

solver.o: solver.cpp solver.h
	g++ -c solver.cpp -o solver.o

clean:
	rm -f main main.o solver.o
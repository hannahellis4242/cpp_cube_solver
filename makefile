all : cube_solver test

clean :
	rm cube_solver test *.o

run : cube_solver
	./cube_solver

cube_solver : main.o Value.o Configuration.o
	g++ -std=c++17 $^ -o $@

test : test.o Value.o Configuration.o
	g++ -std=c++17 $^ -o $@

%.o : %.cpp
	g++ -std=c++17 -c $<

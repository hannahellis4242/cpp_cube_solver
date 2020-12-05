all : cube_solver

clean :
	rm cube_solver *.o

run : cube_solver
	./cube_solver

cube_solver : main.o Value.o
	g++ -std=c++17 $^ -o $@

%.o : %.cpp
	g++ -std=c++17 -c $<

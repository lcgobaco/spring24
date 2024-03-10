COMPILER = g++ -std=c++14 -g
all: main

main: main.o Course.o ComputerScienceTransferCourses.o StudentFortFolio.o Menu.o
	$(COMPILER) -o $@ $^

Course.o: Course.cpp
	$(COMPILER) -c $<

Menu.o: Menu.cpp
	$(COMPILER) -c $<
	
StudentFortFolio.o: StudentFortFolio.cpp
	$(COMPILER) -c $<

ComputerScienceTransferCourses.o: ComputerScienceTransferCourses.cpp
	$(COMPILER) -c $<

clean:
	rm -f main *.o

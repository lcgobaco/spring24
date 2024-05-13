COMPILER = g++ -std=c++14 -g
all: main

main: main.o Course.o Menu.o StudentFortfolio.o ComputerScienceTransferCourses.o
	$(COMPILER) -o $@ $^

Course.o: Course.cpp
	$(COMPILER) -c $<

StudentFortfolio.o: StudentFortfolio.cpp
	$(COMPILER) -c $<

ComputerScienceTransferCourses.o: ComputerScienceTransferCourses.cpp
	$(COMPILER) -c $<

Menu.o: Menu.cpp
	$(COMPILER) -c $<

clean:
	rm -f main *.o

COMPILER = g++ -std=c++14 -g
all: main

main: main.o Course.o ArrayList.o ComputerScienceTransferCourses.o
	$(COMPILER) -o $@ $^

Course.o: Course.cpp
	$(COMPILER) -c $<

ArrayList.o: ArrayList.cpp
	$(COMPILER) -c $<

ComputerScienceTransferCourses.o: ComputerScienceTransferCourses.cpp
	$(COMPILER) -c $<

clean:
	rm -f main *.o

COMPILER = g++ -std=c++14 -g
all: main

main: main.o Course.o Menu.o StudentPortfolioMenu.o ComputerScienceTransferCourses.o
	$(COMPILER) -o $@ $^

Course.o: Course.cpp
	$(COMPILER) -c $<

StudentPortfolioMenu.o: StudentPortfolioMenu.cpp
	$(COMPILER) -c $<

ComputerScienceTransferCourses.o: ComputerScienceTransferCourses.cpp
	$(COMPILER) -c $<

Menu.o: Menu.cpp
	$(COMPILER) -c $<

clean:
	rm -f main *.o

zip: main
	rm -f lab2-LucasGobaco.zip
	zip -r lab2-LucasGobaco.zip *.cpp *.h Makefile README.md

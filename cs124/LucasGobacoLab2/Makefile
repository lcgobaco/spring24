COMPILER = g++ -std=c++14 -g
ZIPFILE = lab2-LucasGobaco.zip

default: main

all: clean main

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

zip: all
	rm -f $(ZIPFILE)
	zip -r $(ZIPFILE) *.cpp *.h Makefile README.md
	zipinfo $(ZIPFILE)

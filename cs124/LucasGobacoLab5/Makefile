COMPILER = g++ -std=c++17 -g
all: main

main: main.o assignment.o faculty.o group.o menu.o section.o
	$(COMPILER) -o $@ $^

main.o: main.cpp
	$(COMPILER) -c $<

assigment.o: assignment.cpp
	$(COMPILER) -c $<

faculty.o: faculty.cpp
	$(COMPILER) -c $<

group.o: group.cpp
	$(COMPILER) -c $<

menu.o: menu.cpp
	$(COMPILER) -c $<

section.o: section.cpp
	$(COMPILER) -c $<

clean:
	rm *.o

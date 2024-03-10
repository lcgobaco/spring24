COMPILER = g++ -std=c++14 -g
all: main

main: main.o Course.o Menu.o StudentFortFolio.o
	$(COMPILER) -o $@ $^

Course.o: Course.cpp
	$(COMPILER) -c $<

StudentFortFolio.o: StudentFortFolio.cpp
	$(COMPILER) -c $<

Menu.o: Menu.cpp
	$(COMPILER) -c $<

clean:
	rm -f main *.o

COMPILER = g++ -std=c++14 -g
all: main

main: main.o Person.o
	$(COMPILER) -o $@ $^

main.o: main.cpp Person.o
	$(COMPILER) -c $<

Person.o: Person.cpp
	$(COMPILER) -c $<

clean:
	rm -f main *.o

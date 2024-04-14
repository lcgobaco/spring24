COMPILER = g++ -std=c++14 -g
all: main

main: main.o Person.o DateTime.o
	$(COMPILER) -o $@ $^

main.o: main.cpp
	$(COMPILER) -c $<

Person.o: Person.cpp
	$(COMPILER) -c $<

DateTime.o: DateTime.cpp
	$(COMPILER) -c $<

clean:
	rm -f main *.o

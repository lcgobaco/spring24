COMPILER = g++ -std=c++14 -g
all: main

main: main.o list.o
	$(COMPILER) -o $@ $^

main.o: main.cpp
	$(COMPILER) -c $<
	
list.o: list.cpp
	$(COMPILER) -c $<


clean:
	rm -f main *.o

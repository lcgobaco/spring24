COMPILER = g++ -std=c++14 -g
all: main

main: main.o hashtable.o
	$(COMPILER) -v -o $@ $^

hashtable.o: hashtable.cpp
	$(COMPILER) -c $<

main.o: main.cpp
	$(COMPILER) -c $<

clean:
	rm -f main *.o



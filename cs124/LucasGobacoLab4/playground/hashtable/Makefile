COMPILER = g++ -std=c++17 -g
all: main

main: hashtable.o
	$(COMPILER) -o $@ $^

clean:
	rm -f main *.o

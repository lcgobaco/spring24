COMPILER = g++ -std=c++14 -g
all: main

main: main.o binarytree.o
	$(COMPILER) -v -o $@ $^

binarytree.o: binarytree.cpp
	$(COMPILER) -c $<

main.o: main.cpp
	$(COMPILER) -c $<

clean:
	rm -f main *.o



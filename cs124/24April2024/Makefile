COMPILER = g++ -std=c++17 -g
all: main

# main: main.o binary_search_tree.o
main: main.o
	$(COMPILER) -o $@ $^

main.o: main.cpp binary_search_tree.h
	$(COMPILER) -c $<

#binary_search_tree.o: binary_search_tree.cpp binary_search_tree.h
#	$(COMPILER) -c $<

clean:
	rm -f main *.o



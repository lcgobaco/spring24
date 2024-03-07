COMPILER = g++ -std=c++14 -g
#COMPILER = g++ -g
all: main

main: main.o
	$(COMPILER) -o $@ $^

main.o: main.cpp
	$(COMPILER) -c $<

clean:
	rm -f main *.o

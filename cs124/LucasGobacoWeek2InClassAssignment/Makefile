all: main

main: main.o Menu.o
	clang++ -std=c++14 -o $@ $^

main.o: main.cpp Menu.h
	clang++ -std=c++14 -c $<

Menu.o: Menu.cpp Menu.h 
	clang++ -std=c++14 -c $<

clean:
	rm -f main *.o
	rm -f Menu *.o
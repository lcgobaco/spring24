all: clean main

main: main.o Time.o DateTime.o User.o Menu.o UserMenu.o
	g++ -std=c++14 -o $@ $^

Time.o: Time.cpp
	g++ -std=c++14 -c $<

DateTime.o: DateTime.cpp
	g++ -std=c++14 -c $<

main.o: main.cpp Time.o DateTime.o User.o Menu.o
	g++ -std=c++14 -c $<

User.o: User.cpp
	g++ -std=c++14 -c $<

UserMenu.o: UserMenu.cpp
	g++ -std=c++14 -c $<

Menu.o: Menu.cpp
	g++ -std=c++14 -c $<

clean:
	rm -f main *.o

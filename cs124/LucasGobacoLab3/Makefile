COMPILER = g++ -std=c++14 -g
all: main

main: main.o Person.o DateTime.o Time.o Utils.o ContactMenu.o Menu.o User.o
	$(COMPILER) -o $@ $^

main.o: main.cpp
	$(COMPILER) -c $<

Person.o: Person.cpp
	$(COMPILER) -c $<

DateTime.o: DateTime.cpp
	$(COMPILER) -c $<

Time.o: Time.cpp
	$(COMPILER) -c $<

Utils.o: Utils.cpp
	$(COMPILER) -c $<

ContactMenu.o: ContactMenu.cpp
	$(COMPILER) -c $<

Menu.o: Menu.cpp
	$(COMPILER) -c $<

User.o: User.cpp
	$(COMPILER) -c $<

clean:
	rm -f main *.o

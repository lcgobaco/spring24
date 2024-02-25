all: main

main: main.o time.o datetime.o user.o menu.o
	g++ -std=c++14 -o $@ $^

time.o: Time.cpp
	g++ -std=c++14 -c $<

datetime.o: DateTime.cpp
	g++ -std=c++14 -c $<

main.o: main.cpp time.o datetime.o user.o menu.o
	g++ -std=c++14 -c $<

user.o: User.cpp
	g++ -std=c++14 -c $<

menu.o: Menu.cpp
	g++ -std=c++14 -c $<

clean:
	rm -f main *.o

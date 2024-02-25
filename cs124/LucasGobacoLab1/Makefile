all: main

main: main.o time.o datetime.o user.o menu.o
	clang++ -std=c++14 -o $@ $^

time.o: Time.cpp
	clang++ -std=c++14 -c $<

datetime.o: DateTime.cpp
	clang++ -std=c++14 -c $<

main.o: main.cpp time.o datetime.o user.o menu.o
	clang++ -std=c++14 -c $<

user.o: User.cpp
	clang++ -std=c++14 -c $<

menu.o: Menu.cpp
	clang++ -std=c++14 -c $<

clean:
	rm -f main *.o

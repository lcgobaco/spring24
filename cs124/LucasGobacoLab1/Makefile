COMPILER = g++ -std=c++14 -g
ZIPFILE = lab1-LucasGobaco.zip
all: main

main: main.o Time.o DateTime.o User.o Menu.o UserMenu.o Utils.o
	$(COMPILER) -o $@ $^

Time.o: Time.cpp
	$(COMPILER) -c $<

DateTime.o: DateTime.cpp
	$(COMPILER) -c $<

main.o: main.cpp Time.o DateTime.o User.o Menu.o
	$(COMPILER) -c $<

User.o: User.cpp
	$(COMPILER) -c $<

UserMenu.o: UserMenu.cpp
	$(COMPILER) -c $<

Menu.o: Menu.cpp
	$(COMPILER) -c $<

Utils.o: Utils.cpp
	$(COMPILER) -c $<

clean:
	rm -f main *.o

zip: main
	rm -f $(ZIPFILE)
	zip -r $(ZIPFILE) *.cpp *.h Makefile README.md
	zipinfo $(ZIPFILE)

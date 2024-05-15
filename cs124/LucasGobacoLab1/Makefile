COMPILER = g++ -std=c++14 -g
ZIPFILE = lab1-LucasGobaco.zip

default: main

all: clean main

main: main.o Time.o DateTime.o User.o Menu.o UserMenu.o Utils.o
	$(COMPILER) -o $@ $^

Time.o: Time.cpp Time.h
	$(COMPILER) -c $<

DateTime.o: DateTime.cpp DateTime.h
	$(COMPILER) -c $<

main.o: main.cpp Time.o DateTime.o User.o Menu.o
	$(COMPILER) -c $<

User.o: User.cpp User.h
	$(COMPILER) -c $<

UserMenu.o: UserMenu.cpp UserMenu.h Utils.h
	$(COMPILER) -c $<

Menu.o: Menu.cpp Menu.h
	$(COMPILER) -c $<

Utils.o: Utils.cpp Utils.h
	$(COMPILER) -c $<

clean:
	rm -f main *.o

zip: all
	rm -f $(ZIPFILE)
	zip -r $(ZIPFILE) *.cpp *.h Makefile README.md
	zipinfo $(ZIPFILE)

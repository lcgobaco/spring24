COMPILER = g++ -std=c++14 -g
ZIPFILE = lab3-LucasGobaco.zip
default: main

all: clean main

main: main.o Person.o DateTime.o Time.o Utils.o ContactMenu.o ContactList.o Menu.o Contact.o
	$(COMPILER) -o $@ $^

main.o: main.cpp Person.h ContactMenu.h
	$(COMPILER) -c $<

Person.o: Person.cpp Person.h
	$(COMPILER) -c $<

DateTime.o: DateTime.cpp DateTime.h Utils.h
	$(COMPILER) -c $<

Time.o: Time.cpp Time.h
	$(COMPILER) -c $<

Utils.o: Utils.cpp
	$(COMPILER) -c $<

ContactMenu.o: ContactMenu.cpp ContactMenu.h Contact.h Utils.h
	$(COMPILER) -c $<

Menu.o: Menu.cpp Menu.h
	$(COMPILER) -c $<

Contact.o: Contact.cpp Contact.h
	$(COMPILER) -c $<

ContactList.o: ContactList.cpp ContactList.h LinkedList.h
	$(COMPILER) -c $<

clean:
	rm -f main *.o

zip: all
	rm -f $(ZIPFILE)
	zip -r $(ZIPFILE) *.cpp *.h Makefile README.md
	zipinfo $(ZIPFILE)

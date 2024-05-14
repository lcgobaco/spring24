COMPILER = g++ -std=c++14 -g
ZIPFILE = lab3-LucasGobaco.zip
default: main

all: clean main

main: main.o Person.o DateTime.o Time.o Utils.o ContactMenu.o ContactList.o Menu.o Contact.o
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

Contact.o: Contact.cpp
	$(COMPILER) -c $<

ContactList.o: ContactList.cpp
	$(COMPILER) -c $<

clean:
	rm -f main *.o

zip: all
	rm -f $(ZIPFILE)
	zip -r $(ZIPFILE) *.cpp *.h Makefile README.md
	zipinfo $(ZIPFILE)

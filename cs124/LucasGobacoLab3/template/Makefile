COMPILER = g++ -std=c++14 -g
ZIPFILE = lab3-template-LucasGobaco.zip
default: main

all: clean main

main: main.o contact.o contactList.o contactMenu.o menu.o
	$(COMPILER) -o $@ $^

contact.o: contact.cpp
	$(COMPILER) -c $<

contactList.o: contactList.cpp
	$(COMPILER) -c $<

contactMenu.o: contactMenu.cpp
	$(COMPILER) -c $<

menu.o: menu.cpp
	$(COMPILER) -c $<

clean:
	rm -f main *.o

zip: all
	rm -f $(ZIPFILE)
	zip -r $(ZIPFILE) *.cpp *.h Makefile README.md
	zipinfo $(ZIPFILE)

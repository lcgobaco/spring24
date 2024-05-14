COMPILER = g++ -std=c++17 -g
ZIPFILE = lab5-LucasGobaco.zip
default: main

all: clean main

main: main.o assignment.o faculty.o gradeScale.o menu.o section.o Utils.o
	$(COMPILER) -o $@ $^

main.o: main.cpp
	$(COMPILER) -c $<

assigment.o: assignment.cpp
	$(COMPILER) -c $<

faculty.o: faculty.cpp
	$(COMPILER) -c $<

gradeScale.o: gradeScale.cpp
	$(COMPILER) -c $<

menu.o: menu.cpp
	$(COMPILER) -c $<

section.o: section.cpp
	$(COMPILER) -c $<

Utils.o: Utils.cpp
	$(COMPILER) -c $<

clean:
	rm *.o

zip: main
	rm -f $(ZIPFILE)
	zip -r $(ZIPFILE) *.cpp *.h Makefile README.md
	zipinfo $(ZIPFILE)

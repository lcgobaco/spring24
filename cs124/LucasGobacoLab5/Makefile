COMPILER = g++ -std=c++17 -g
ZIPFILE = lab5-LucasGobaco.zip

default: main

all: clean main

main: main.o assignmentMenu.o menu.o sectionHT.o gradeScaleHT.o facultyHT.o assignmentBST.o faculty.o gradeScale.o section.o assignment.o Utils.o
	$(COMPILER) -o $@ $^

main.o: main.cpp
	$(COMPILER) -c $<

assignmentMenu.o: assignmentMenu.cpp
	$(COMPILER) -c $<

faculty.o: faculty.cpp
	$(COMPILER) -c $<

assigment.o: assignment.cpp
	$(COMPILER) -c $<

gradeScale.o: gradeScale.cpp
	$(COMPILER) -c $<

section.o: section.cpp
	$(COMPILER) -c $<

menu.o: menu.cpp menu.h
	$(COMPILER) -c $<

Utils.o: Utils.cpp Utils.h
	$(COMPILER) -c $<

sectionHT.o: sectionHT.cpp sectionHT.h
	$(COMPILER) -c $<

gradeScaleHT.o: gradeScaleHT.cpp gradeScaleHT.h
	$(COMPILER) -c $<

facultyHT.o: facultyHT.cpp facultyHT.h
	$(COMPILER) -c $<

assignmentBST.o: assignmentBST.cpp
	$(COMPILER) -c $<

clean:
	rm *.o

zip: all
	rm -f $(ZIPFILE)
	zip -r $(ZIPFILE) *.cpp *.h Makefile README.md
	zipinfo $(ZIPFILE)

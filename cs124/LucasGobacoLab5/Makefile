COMPILER = g++ -std=c++17 -g
ZIPFILE = lab5-LucasGobaco.zip
default: main

all: clean main

main: main.o assignment.o faculty.o gradeScale.o menu.o section.o Utils.o Utils.h \
	sectionHT.o gradeScaleHT.o facultyHT.o
	$(COMPILER) -o $@ $^

main.o: main.cpp binary_tree.h binary_search_tree.h common.h
	$(COMPILER) -c $<

assigment.o: assignment.cpp common.h
	$(COMPILER) -c $<

faculty.o: faculty.cpp common.h
	$(COMPILER) -c $<

gradeScale.o: gradeScale.cpp common.h
	$(COMPILER) -c $<

section.o: section.cpp common.h
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

clean:
	rm *.o

zip: all
	rm -f $(ZIPFILE)
	zip -r $(ZIPFILE) *.cpp *.h Makefile README.md
	zipinfo $(ZIPFILE)

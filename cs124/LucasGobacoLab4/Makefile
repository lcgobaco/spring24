COMPILER = g++ -std=c++17 -g
ZIPFILE = lab4-LucasGobaco.zip
default: main

all: clean main

main: main.o dateTime.o dateType.o menu.o task.o \
	taskHashTable.o \
	taskMenu.o taskException.o utils.o
	$(COMPILER) -o $@ $^

main.o: main.cpp
	$(COMPILER) -c $<

dateTime.o: dateTime.cpp
	$(COMPILER) -c $<

dateType.o: dateType.cpp
	$(COMPILER) -c $<

menu.o: menu.cpp menu.h
	$(COMPILER) -c $<

task.o: task.cpp task.h
	$(COMPILER) -c $<

taskHashTable.o: taskHashTable.cpp taskHashTable.h
	$(COMPILER) -c $<

taskMenu.o: taskMenu.cpp taskMenu.h
	$(COMPILER) -c $<

utils.o: utils.cpp
	$(COMPILER) -c $<

taskException.o: taskException.cpp
	$(COMPILER) -c $<

clean:
	rm -f main *.o

zip: all
	rm -f $(ZIPFILE)
	zip -r $(ZIPFILE) *.cpp *.h Makefile README.md
	zipinfo $(ZIPFILE)

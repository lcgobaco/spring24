COMPILER = g++ -std=c++17 -g
ZIPFILE = lab4-LucasGobaco.zip
default: main

all: clean main

main: main.o dateTime.o dateType.o menu.o task.o taskList.o taskHashTable.o taskMenu.o taskException.o utils.o
	$(COMPILER) -o $@ $^

main.o: main.cpp
	$(COMPILER) -c $<

dateTime.o: dateTime.cpp
	$(COMPILER) -c $<

dateType.o: dateType.cpp
	$(COMPILER) -c $<

menu.o: menu.cpp
	$(COMPILER) -c $<

task.o: task.cpp
	$(COMPILER) -c $<

taskList.o: taskList.cpp
	$(COMPILER) -c $<

taskHashTable.o: taskHashTable.cpp
	$(COMPILER) -c $<

taskMenu.o: taskMenu.cpp
	$(COMPILER) -c $<

utils.o: utils.cpp
	$(COMPILER) -c $<

taskException.o: taskException.cpp
	$(COMPILER) -c $<

clean:
	rm -f main *.o

zip: main
	rm -f $(ZIPFILE)
	zip -r $(ZIPFILE) *.cpp *.h Makefile README.md
	zipinfo $(ZIPFILE)

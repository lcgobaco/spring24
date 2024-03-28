COMPILER = g++ -std=c++14 -g
all: main

main: main.o billing.o doctor.o patient.o person.o
	$(COMPILER) -o $@ $^

billing.o: billing.cpp
	$(COMPILER) -c $<

doctor.o: doctor.cpp
	$(COMPILER) -c $<

patient.o: patient.cpp
	$(COMPILER) -c $<

person.o: person.cpp
	$(COMPILER) -c $<

clean:
	rm -f main *.o

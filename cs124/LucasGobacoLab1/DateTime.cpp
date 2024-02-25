#include "DateTime.h"

    // Constructor
    DateTime::DateTime(int h, int m, int s, int mon, int d, int y)
        : Time(h, m, s), month(mon), day(d), year(y) {}

    // Destructor
    DateTime::~DateTime() {
        std::cout << "Destroying DateTime Object" << std::endl;
    }

    // Setter methods
    void DateTime::setMonth(int mon) {
        month = mon;
    }

    void DateTime::setDay(int d) {
        day = d;
    }

    void DateTime::setYear(int y) {
        year = y;
    }

    // Getter methods
    int DateTime::getMonth() const {
        return month;
    }

    int DateTime::getDay() const {
        return day;
    }

    int DateTime::getYear() const {
        return year;
    }


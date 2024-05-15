#pragma once
#include "person.h"

class Contact : public Person {
public:
	bool operator==(const Contact&);
	bool operator>(const Contact&);
	bool operator<(const Contact&);

private:
	static string sortByField;
};

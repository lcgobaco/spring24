#include "contact.h"

string Contact::sortByField = "id";

bool Contact::operator==(const Contact& c) {
	return true;

}
bool Contact::operator>(const Contact& c) {
	return true;
}

bool Contact::operator<(const Contact& c) {
	return true;
}
#pragma once
#include "linkedlist.h"
#include "contact.h"

class ContactList : public LinkedList<Contact> {
public:
	
	
	
	
	
	
	
	void moveFirst();
	void moveNext();
	void movePrevious();
	void moveLast();

	void sortBy(bool ascending = true);
	void print() const;
};
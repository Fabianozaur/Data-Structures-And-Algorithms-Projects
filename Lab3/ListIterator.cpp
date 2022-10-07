#include "ListIterator.h"
#include "IteratedList.h"
#include <exception>
#include <iostream>

using namespace std;

ListIterator::ListIterator(const IteratedList& list) : list(list) {
	//TODO - Implementation
	first();
}

void ListIterator::first() {
	//TODO - Implementation
	pozitie = list.head;
}

void ListIterator::next() {
	//TODO - Implementation
	if (!valid() )
		throw std::exception();
	pozitie = list.arr[pozitie].next;
}

bool ListIterator::valid() const {
	//TODO - Implementation
	if (pozitie <= -1)
		return false;
	return true;
}

TElem ListIterator::getCurrent() const {
	//TODO - Implementation

	if (valid())
		return list.getElement(*this);
	throw exception();
}




#include <exception>
#include "BagIterator.h"
#include "Bag.h"

using namespace std;


BagIterator::BagIterator(const Bag& c): bag(c)
{
	ht = c.ht;
	current = 0;
	while (current < ht.capacity && ht.v[current] == NULL)
		current++;
	if (current < ht.capacity)
	{
		node = ht.v[current];
		freq = 1;
	}
	else
		node = NULL;
	//TODO - Implementation
}

void BagIterator::first() {
	//TODO - Implementation
	current = 0;
	while (current < ht.capacity && ht.v[current] == NULL)
		current++;
	if (current < ht.capacity)
	{
		node = ht.v[current];
		freq = 1;
	}
	else
		node = NULL;
}


void BagIterator::next() {
	//TODO - Implementation
	if (valid() == false)
		throw(exception());
	if (freq < node->frequency)
	{
		freq++;
		return;
	}
	node = node->next;
	freq = 1;
	if (node == NULL)
	{
		current++;
		while (current < ht.capacity && ht.v[current] == NULL)
			current++;
		if (current < ht.capacity)
			node = ht.v[current];
		else
			node = NULL;
	}
}


bool BagIterator::valid() const {
	//TODO - Implementation
	if (node == NULL || current >= ht.capacity)
		return false;
	return true;
}



TElem BagIterator::getCurrent() const
{
	//TODO - Implementation
	if (valid() == false)
		throw(exception());
	return node->elem;
	
}

#include "MultiMapIterator.h"
#include "MultiMap.h"
#include <exception>

using namespace std;



MultiMapIterator::MultiMapIterator(const MultiMap& c): col(c) {
	//TODO - Implementation
	currentNode = col.head;
	if (currentNode != NULL)
		currentValue = currentNode->first;
	else
		currentValue = NULL;
}

TElem MultiMapIterator::getCurrent() const{
	//TODO - Implementation
	if (valid() == true)
	{
		TKey c = currentNode->key;
		TValue v = currentValue->val;
		return make_pair(c, v);
	}
	throw exception(); 
}

bool MultiMapIterator::valid() const {
	//TODO - Implementation
	if(currentNode==NULL)
		return false;
	else
		return true;
}

void MultiMapIterator::next() {
	//TODO - Implementation
	if (currentNode == NULL)
		throw exception();
	else
	{
		if (currentValue->next != NULL)
			currentValue = currentValue->next;
		else
		{
			currentNode = currentNode->next;
			if (currentNode != NULL)
				currentValue = currentNode->first;
			else
				currentValue = NULL;

		}
	}
}

void MultiMapIterator::first() {
	//TODO - Implementation
	currentNode = col.head;
	if (currentNode != NULL)
		currentValue = currentNode->first;
	else
		currentValue = NULL;
}

void MultiMapIterator::goBack(int k)
{
	if (k <= 0)
		throw exception();
	if (!valid())
		throw exception();
	while (k != 0 && valid())
	{
		if (currentValue->previous != NULL)
			currentValue = currentValue->previous;
		else
		{
			currentNode = currentNode->previous;
			if (currentNode != NULL)
				currentValue = currentNode->first;
			else
				currentValue = NULL;
		}
		k--;
	}
}


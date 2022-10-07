#include "Bag.h"
#include "BagIterator.h"
#include <exception>
#include <iostream>
using namespace std;


int Bag::hashFuntion(TElem elem) const
{
	return abs(elem) % m;
}

void Bag::resize()
{
	int exCapacity = ht.capacity;
	ht.capacity *= 2;
	m *= 2;
	Node** newHash = new Node * [ht.capacity];
	for (int i = 0; i < ht.capacity; i++)
		newHash[i] = NULL;
	Node* prevNode = NULL;
	for (int i = 0; i < exCapacity; i++)
	{
		Node* currentNode = ht.v[i];
		while (currentNode != NULL)
		{
			prevNode = currentNode;
			int pos = hashFuntion(currentNode->elem);
			Node* newNode = new Node();
			newNode->elem = currentNode->elem;
			newNode->frequency = currentNode->frequency;
			newNode->next = newHash[pos];
			newHash[pos] = newNode;
			currentNode = currentNode->next;
			delete prevNode;
		}
	}
	delete[] ht.v;
	ht.v = newHash;
}

Bag::Bag() {
	//TODO - Implementation
	ht.capacity = m = 40;
	ht.size = 0;
	ht.v = new Node * [ht.capacity];
	for (int i = 0; i < m; i++)
	{
		ht.v[i] = NULL;
	}
}


void Bag::add(TElem elem) {
	//TODO - Implementation
	int pos = hashFuntion(elem);
	if (search(elem) == true)
	{
		Node* currentNode = this->ht.v[pos];
		while (currentNode != NULL)
		{
			if (currentNode->elem == elem)
			{
				currentNode->frequency++;
				ht.size++;
			}
			currentNode = currentNode->next;
		}
	}
	else
	{
		double x;
		x = static_cast<double>(ht.size) / static_cast<double>(m);
		if (x > 0.7)
			resize();
		Node* newNode = new Node();
		newNode->elem = elem;
		newNode->frequency = 1;
		newNode->next = ht.v[pos];
		ht.v[pos] = newNode;
		ht.size++;
	}
}


bool Bag::remove(TElem elem) {
	//TODO - Implementation
	if(search(elem)==false)
		return false;
	int pos = hashFuntion(elem);
	Node* currrentNode = ht.v[pos];
	while (currrentNode != NULL)
	{
		if (currrentNode->elem == elem)
		{
			if (currrentNode->frequency > 1)
			{
				currrentNode->frequency--;
				ht.size--;
				return true;
			}

		}
		currrentNode = currrentNode->next;
	}
	currrentNode = ht.v[pos];
	Node* prevNode = NULL;
	while (currrentNode->elem != elem)
	{
		prevNode = currrentNode;
		currrentNode = currrentNode->next;
	}
	if (prevNode == NULL)
		ht.v[pos] = ht.v[pos]->next;
	else
	{
		prevNode->next = currrentNode->next;
		currrentNode->next = NULL;
	}
	delete currrentNode;
	currrentNode= NULL;
	ht.size--;
	return true;
}


bool Bag::search(TElem elem) const {
	//TODO - Implementation
	int pos = hashFuntion(elem);
	Node* currrentNode = ht.v[pos];
	while (currrentNode != NULL)
	{
		if (currrentNode->elem == elem)
			return true;
		currrentNode = currrentNode->next;
	}
	return false; 
}

int Bag::nrOccurrences(TElem elem) const {
	//TODO - Implementation
	int pos = hashFuntion(elem);
	if (search(elem) == true)
	{
		Node* currrentNode = ht.v[pos];
		while (currrentNode != NULL)
		{
			if (currrentNode->elem == elem)
			{
				return currrentNode->frequency;
				
			}
			currrentNode = currrentNode->next;
		}
	}
	return 0;
}


int Bag::size() const {
	//TODO - Implementation
	return ht.size;
}


bool Bag::isEmpty() const {
	//TODO - Implementation
	if (ht.size == 0)
		return 1;
	return 0;
}

void Bag::Filter(Condition cond)
{
	int element;
	int pos = 0;
	while(pos<m)
	{
		if (ht.v[pos] != NULL)
		{
			Node* currrentNode = ht.v[pos];
			while (currrentNode != NULL)
			{

				element = currrentNode->elem;
				currrentNode = currrentNode->next;

				if (!cond(element))
				{
					remove(element);
					pos=0;
				}
			}
		}
		pos++;

	}
}

BagIterator Bag::iterator() const {
	return BagIterator(*this);
}


Bag::~Bag() {
	//TODO - Implementation
	for (int i = 0; i < ht.capacity; i++)
	{
		Node* currentNode =ht.v[i];
		Node* prevNode = NULL;
		while (currentNode != NULL)
		{
			prevNode = currentNode;
			currentNode = currentNode->next;
			delete prevNode;
		}
	}
	delete[] ht.v;
	
}


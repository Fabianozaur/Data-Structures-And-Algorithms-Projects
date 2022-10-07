#include "SortedBagIterator.h"
#include "SortedBag.h"
#include <exception>
#include <iostream>

using namespace std;

SortedBagIterator::SortedBagIterator(const SortedBag& b) : bag(b) {
	//TODO - Implementation
	Stack = new Node*[bag.size()];
	first();
}

TComp SortedBagIterator::getCurrent() {
	//TODO - Implementation
	//return NULL_TCOMP;
	if (valid()) {
		return Stack[stackTop - 1]->value;
	}
	throw std::exception();

}

bool SortedBagIterator::valid() {
	//TODO - Implementation
	return stackTop != 0;
}

void SortedBagIterator::next() {
	//TODO - Implementation
	if (!valid())
		throw std::exception();
	if (stackfFrecunacy > 1)
		stackfFrecunacy--;
	else {
		Node* currentNode = Stack[--stackTop];
		if (currentNode->right != nullptr)
		{
			currentNode = currentNode->right;
			do
			{
				stackfFrecunacy = currentNode->frequency;
				Stack[stackTop++] = currentNode;
				currentNode = currentNode->left;

			} while (currentNode != nullptr);
		}
	}
}

void SortedBagIterator::first() {
	//TODO - Implementation
	stackTop = 0;
	if (bag.root == nullptr)
		return;
	Node* currentNode = bag.root;
	do
	{
		Stack[stackTop++] = currentNode;
		stackfFrecunacy = currentNode->frequency;
		currentNode = currentNode->left;

	} while (currentNode != nullptr);
	
}


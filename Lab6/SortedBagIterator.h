#pragma once
#include "SortedBag.h"

class SortedBag;

class SortedBagIterator
{
	friend class SortedBag;

private:
	const SortedBag& bag;
	SortedBagIterator(const SortedBag& b);
	//TODO - Representation
	Node** Stack;
	int stackTop;
	int stackfFrecunacy;
public:
	TComp getCurrent();
	bool valid();
	void next();
	void first();
};


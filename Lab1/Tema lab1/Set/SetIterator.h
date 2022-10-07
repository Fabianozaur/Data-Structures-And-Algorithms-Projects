#pragma once
#include "Set.h"

class SetIterator
{
	//DO NOT CHANGE THIS PART
	friend class Set;
private:
	//DO NOT CHANGE THIS PART
	const Set& set;
	/*
		Constructor of set iterator
		Complexity: O(n)
	*/
	SetIterator(const Set& s);

	//TODO - Representation
	int current;	
	int len;		//this is the lenght of inSet array
	int minus;
	int c;
	int justTurnedPlus;
public:
	/*
		Sets iterator on the first position
		Complexity: O(n)
	*/
	void first(); 
	/*
		Sets iterator on the next position
		Complexity: O(n)
	*/
	void next();
	/*
		Returns the current element from the set
		Complexity: O(1)

	*/
	TElem getCurrent();
	/*
		Checks whatever the curent position is valid
		Complexity: O(n)
		Return true if the position is valid and false if it is not
	*/
	bool valid() const;
	void previous();
};



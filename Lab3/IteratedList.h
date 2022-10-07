#pragma once
//DO NOT INCLUDE LISTITERATOR

//DO NOT CHANGE THIS PART
class ListIterator;
#define NULL_TELEM -11111;
typedef int TElem;


class IteratedList {
private:
	//TODO - Representation
	//Complexity : T(1)
	int alloc();
	//Complexity : T(1)
	void free(int position);
	//Complexity : T(n)
	void resize();
	class Nod {
	public:
		TElem elem;
		int next;
		int prev;

	};
	Nod* arr;
	int capacity;
	int length;
	int head;
	int tail;
	int firstEmpty;

	//DO NOT CHANGE THIS PART
	friend class ListIterator;
public:

	// constructor
	//Complexity : T(n)
	IteratedList ();

	// returns the number of elements from the list
	//Complexity : T(1)
	int size() const;

	// verifies if the list is empty
	//Complexity : T(1)
	bool isEmpty() const;

	// returns the first position from the list
	//Complexity : T(1)
	ListIterator first() const;

	// returns the element from the given position
	//throws an exception if the position is not valid
	//Complexity : T(1)
	TElem getElement(ListIterator pos) const;

	// changes the element from the current position to the given one.
	//returns the old value from the position
	//throws exception if the position is not valid
	//Complexity : T(1)
	TElem setElement(ListIterator pos, TElem e);

	// adds a new element to the end of the list
	//Complexity : T(1)
	void addToEnd(TElem e);
	
	//adds a new element to the beginning of the list
	//Complexity : T(1)
	void addToBeginning(TElem e);

	// // adds a new element after the current element from the iterator
	//after addition, pos points to the newly added element
	//throws an exception if pos is not valid
	//Complexity : T(1)
	void addToPosition(ListIterator& pos, TElem e);

	// removes the element from position pos
	//returns the removed element
	//after removal pos is positioned on the next element (the one after the removed one) or it is invalid if the last element was removed
	//throws an exception if pos is not valid
	//Complexity : T(1)

	TElem remove(ListIterator& pos);

	// searches for the first occurrance of an element 
	//returns an iterator that points to the element, if it appear in the list, or an invalid iterator if the element is not in the list
	//Complexity : O(n)

	ListIterator search(TElem e) const;

	//Complexity : T(n)
	void removeBetween(ListIterator start, ListIterator stop);

	//destructor

	~IteratedList();
};

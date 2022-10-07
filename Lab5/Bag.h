#pragma once
//DO NOT INCLUDE BAGITERATOR


//DO NOT CHANGE THIS PART
#define NULL_TELEM -111111;
typedef int TElem;
class BagIterator; 
typedef bool (*Condition)(TElem);

typedef struct Node {
	TElem elem;
	int frequency;
	Node* next;
}Node;

typedef struct hashT {
	Node** v;
	int size;
	int capacity;
};

class Bag {

private:
	//TODO - Representation
	hashT ht;
	int m;
	//Complexity:T(1)
	int hashFuntion(TElem elem) const;
	//Complexity:T(n)  //of the newCapacity
	void resize();


	//DO NOT CHANGE THIS PART
	friend class BagIterator;
public:
	//constructor
	Bag();

	//adds an element to the bag
	//Complexity: Best Case:T(1) Worst Case T(n) Average Case :O(n)
	void add(TElem e);

	//removes one occurence of an element from a bag
	//returns true if an element was removed, false otherwise (if e was not part of the bag)
	//Complexity: O(n)
	bool remove(TElem e);

	//checks if an element appearch is the bag
	//Complexity: O(n)
	bool search(TElem e) const;

	//returns the number of occurrences for an element in the bag
	//Complexity: O(n)
	int nrOccurrences(TElem e) const;

	//returns the number of elements from the bag
	//Complexity: T(1)
	int size() const;

	//returns an iterator for this bag
	//Complexity: T(1)
	BagIterator iterator() const;

	//checks if the bag is empty
	//Complexity: T(1)
	bool isEmpty() const;

	void Filter(Condition cond);

	//destructor
	~Bag();
};
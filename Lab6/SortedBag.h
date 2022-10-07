#pragma once


typedef int TComp;

typedef TComp TElem;

typedef bool(*Relation)(TComp, TComp);

#define NULL_TCOMP -11111;

class SortedBagIterator;


struct Node
{
	TComp value;
	int frequency;
	Node* left;
	Node* right;
};


class SortedBag {

	friend class SortedBagIterator;

private:

	/*representation of SortedBag*/
	Node * root;
	int nrElems;
	Relation rel;

	Node* getMaximum(Node* start);
	Node* removeRec(Node* node, TComp e, bool &removed);


public:

	//constructor

	SortedBag(Relation r);

	//adds an element to the sorted bag

	void add(TComp e);

	//removes one occurrence of an element from a sorted bag

	//returns true if an element was removed, false otherwise (if e was not part of the sorted bag)

	bool remove(TComp e);



	//checks if an element appearch is the sorted bag

	bool search(TComp e) const;



	//returns the number of occurrences for an element in the sorted bag

	int nrOccurrences(TComp e) const;



	//returns the number of elements from the sorted bag

	int size() const;



	//returns an iterator for this sorted bag

	SortedBagIterator iterator() const;



	//checks if the sorted bag is empty

	bool isEmpty() const;

	//counts and returns the number of distinct elements in the SortedBag
	int distinctCount() const;

	int Countfunction(Node* node) const;

	//destructor

	~SortedBag();

};


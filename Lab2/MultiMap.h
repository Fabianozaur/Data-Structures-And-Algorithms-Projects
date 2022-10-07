#pragma once
#include<vector>
#include<utility>
//DO NOT INCLUDE MultiMapIterator

using namespace std;

//DO NOT CHANGE THIS PART
typedef int TKey;
typedef int TValue;
typedef std::pair<TKey, TValue> TElem;
#define NULL_TVALUE -11111;
#define NULL_TELEM pair<int,int>(-11111, -11111);
class MultiMapIterator;

struct ValuesNode
{
	TValue val;
	ValuesNode* previous;
	ValuesNode* next;
};

struct MultiMapNode
{
	TKey key;
	ValuesNode* first;
	ValuesNode* last;
	MultiMapNode* previous;
	MultiMapNode* next;
};
class MultiMap
{
	friend class MultiMapIterator;

private:
	//TODO - Representation
	MultiMapNode* head;
	MultiMapNode* tail;
	int length;

public:
	//constructor
	MultiMap();

	//adds a key value pair to the multimap
	//Complexity: O(n)
	void add(TKey c, TValue v);

	//removes a key value pair from the multimap
	//returns true if the pair was removed (if it was in the multimap) and false otherwise
	//Complexity: O(n)
	bool remove(TKey c, TValue v);

	//returns the vector of values associated to a key. If the key is not in the MultiMap, the vector is empty
	//Complexity: O(n)
	vector<TValue> search(TKey c) const;

	//returns the number of pairs from the multimap
	//Complexity: ϴ(1)
	int size() const;

	//checks whether the multimap is empty
	//Complexity: ϴ(1)
	bool isEmpty() const;

	//returns an iterator for the multimap
	//Complexity: ϴ(1)
	MultiMapIterator iterator() const;

	//descturctor
	//Complexity: O(n)
	~MultiMap();


};


#pragma once
#include "MultiMap.h"

class MultiMap;

class MultiMapIterator
{
	friend class MultiMap;

private:
	const MultiMap& col;
	//TODO - Representation
	MultiMapNode* currentNode;
	ValuesNode* currentValue;

	MultiMapIterator(const MultiMap& c);

public:
	//Complexity: ϴ(1)
	TElem getCurrent()const;
	//Complexity: ϴ(1)
	bool valid() const;
	//Complexity: ϴ(n)
	void next();
	//Complexity: ϴ(1)
	void first();
	void goBack(int k);
};


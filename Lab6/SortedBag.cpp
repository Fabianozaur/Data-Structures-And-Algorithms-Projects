#include "SortedBag.h"
#include "SortedBagIterator.h"



//O(n)
Node* SortedBag::getMaximum(Node* start)
{
	Node* currentNode = start;
	Node* maxNode = start;

	while (currentNode != nullptr)
	{
		maxNode = currentNode;
		currentNode = currentNode->right;
	}
	return maxNode;
}

SortedBag::SortedBag(Relation r)
{
	this->rel = r;
	this->root = nullptr;
	this->nrElems = 0;
}


//theta(1)
bool SortedBag::isEmpty() const
{
	return (this->nrElems == 0);
}

//O(n)
void SortedBag::add(TComp e)
{
	Node* currentNode = this->root;
	Node* parent = nullptr;

	while (currentNode != nullptr)
	{
		parent = currentNode;
		if (currentNode->value == e)
		{
			currentNode->frequency++;
			this->nrElems++;
			return;
		}
		else if (this->rel(e, currentNode->value))
		{
			currentNode = currentNode->left;
		}
		else
		{
			currentNode = currentNode->right;
		}
	}


	Node* newNode = new Node;
	newNode->value = e;
	newNode->frequency = 1;
	newNode->left = nullptr;
	newNode->right = nullptr;


	if (this->root == nullptr)
	{
		this->root = newNode;
	}
	else if (this->rel(e, parent->value))
	{
		parent->left = newNode;
	}
	else
	{
		parent->right = newNode;
	}
	this->nrElems++;
}


Node* SortedBag::removeRec(Node* node, TComp e, bool& removed)
{
	if (node == nullptr)
		return node;
	if (e == node->value)
	{
		removed = true;
		node->frequency--;
		if (node->frequency == 0)
		{
			if (node->left == nullptr)
			{
				Node* rightSon = node->right;
				delete node;
				return rightSon;
			}
			else if (node->right == nullptr)
			{
				Node* leftSon = node->left;
				delete node;
				return leftSon;
			}
			else
			{
				Node* maxNode = this->getMaximum(node->left);
				node->value = maxNode->value;
				node->frequency = maxNode->frequency;
				node->left = this->removeRec(node->left, maxNode->value, removed);
			}
		}
		else
			return node;
	}
	else if (this->rel(e, node->value))
	{
		node->left = this->removeRec(node->left, e, removed);
	}
	else
	{
		node->right = this->removeRec(node->right, e, removed);
	}
	return node;
}



//O(n)
bool SortedBag::remove(TComp e)
{
	bool removed = false;
	this->root = this->removeRec(this->root, e, removed);
	if (removed)
		this->nrElems--;
	return removed;
}


//O(n)
bool SortedBag::search(TComp e) const
{
	Node* currentNode = this->root;

	while (currentNode != nullptr)
	{
		if (currentNode->value == e)
		{
			return true;
		}
		else if (this->rel(e, currentNode->value))
		{
			currentNode = currentNode->left;
		}
		else
		{
			currentNode = currentNode->right;
		}
	}
	return false;
}

////O(n)
int SortedBag::nrOccurrences(TComp e) const
{
	Node* currentNode = this->root;

	while (currentNode != nullptr)
	{
		if (currentNode->value == e)
		{
			return currentNode->frequency;
		}
		else if (this->rel(e, currentNode->value))
		{
			currentNode = currentNode->left;
		}
		else
		{
			currentNode = currentNode->right;
		}
	}
	return 0;
}


int SortedBag::distinctCount() const
{
	Node* rootNode = this->root;
	return Countfunction(rootNode);

}

int SortedBag::Countfunction(Node* node) const
{
	if (node != nullptr)
	{
		return 1 + this->Countfunction(node->left) + this->Countfunction(node->right);
	}
	return 0;
}


//theta(1)
int SortedBag::size() const
{
	return this->nrElems;
}


SortedBagIterator SortedBag::iterator() const {
	return SortedBagIterator(*this);
}


SortedBag::~SortedBag() {
	//TODO - Implementation
}
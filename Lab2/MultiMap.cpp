#include "MultiMap.h"
#include "MultiMapIterator.h"
#include <exception>
#include <iostream>

using namespace std;


MultiMap::MultiMap() {
	//TODO - Implementation
	this->head = NULL;
	this->tail = NULL;
	this->length = 0;
}


void MultiMap::add(TKey c, TValue v) {
	//TODO - Implementation
	MultiMapNode* node = head;
	int keyExists = 0;
	while (node != NULL)
	{
		if (node->key == c)
		{
			keyExists = 1;
			break;
		}
		else
		{
			node = node->next;
		}
	}
	if (keyExists == 0)
	{
		if (head == NULL)
		{
			MultiMapNode* newNode = new MultiMapNode();
			newNode->next = NULL;
			newNode->key = c;
			ValuesNode* newValue = new ValuesNode();
			newNode->first = newValue;
			newNode->last = newValue;
			newValue->next = NULL;
			newValue->previous = NULL;
			newValue->val = v;
			head = newNode;
			tail = newNode;
			length++;
		}
		else
		{
			MultiMapNode* newNode = new MultiMapNode();
			newNode->key = c;
			ValuesNode* newValue = new ValuesNode();
			newNode->first = newValue;
			newNode->last = newValue;
			newValue->val = v;
			newNode->previous = tail;
			tail->next = newNode;
			newValue->next = NULL;
			newValue->previous = NULL;
			newNode->next = NULL;
			tail = newNode;
			length++;
		}
	}
	else
	{
		ValuesNode* newValue = new ValuesNode();
		newValue->previous = node->last;
		node->last->next = newValue;
		newValue->val = v;
		newValue->next = NULL;
		node->last = newValue;
		length++;
	}
}


bool MultiMap::remove(TKey c, TValue v) {
	//TODO - Implementation
	MultiMapNode* node = head;
	int ok = 0;
	while (node != NULL)
	{
		if (node->key == c)
		{
			ok = 1;
			break;
		}
		node = node->next;
	}
	if(ok==0)
		return  false;
	ValuesNode* value = node->first;
	if (value->next == NULL)
	{
		if (value->val == v)
		{
			if (head == node)
			{
				delete value;
				head = head->next;
				delete node;
				length--;
				return true;
			}
			MultiMapNode* prev = head;
			while (prev->next != node)
			{
				prev = prev->next;
			}
			prev->next = node->next;
			delete value;
			delete node;
			length--;
			return true;
		}
		else
			return false;
	}
	if (value->val == v)
	{
		node->first = value->next;
		value->next->previous = NULL;
		delete value;
		length--;
		return true;
	}
	ValuesNode* prev = value;
	value = value->next;
	while (value != NULL)
	{
		if (value->val == v)
		{
			prev->next = value->next;
			delete value;
			length--;
			return true;
		}
		else
		{
			prev = value;
			value = value->next;
		}
	}
	return false;

}


vector<TValue> MultiMap::search(TKey c) const {
	//TODO - Implementation
	vector<TValue> v= vector<TValue>();
	MultiMapNode* node = head;
	int keyExists = 0;
	while (node != NULL)
	{
		if (node->key == c)
		{
			keyExists = 1;
			break;
		}
		node = node->next;
		
	}
	if (keyExists == 1)
	{
		ValuesNode* newValue = node->first;
		while (newValue != NULL)
		{
			v.push_back(newValue->val);
			newValue = newValue->next;
		}
	}
	return v;
}


int MultiMap::size() const {
	//TODO - Implementation
	return length;
}


bool MultiMap::isEmpty() const {
	//TODO - Implementation
	if (head == NULL || tail == NULL)
		return true;
	return false;
}

MultiMapIterator MultiMap::iterator() const {
	return MultiMapIterator(*this);
}


MultiMap::~MultiMap() {
	//TODO - Implementation
	if (head != NULL)
	{
		MultiMapNode* node = head, * nodeDeleted;
		ValuesNode* value = NULL, * valueDeleted;
		while (node != NULL)
		{
			valueDeleted = value = node->first;
			while (value != NULL)
			{
				value = value->next;
				delete valueDeleted;
				valueDeleted = value;
			}
			node = node->next;
		}
		nodeDeleted = node = head;
		while (node != NULL)
		{
			node = node->next;
			delete nodeDeleted;
			nodeDeleted = node;
		}
	}
}


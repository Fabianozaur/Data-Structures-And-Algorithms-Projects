
#include <exception>
#include <iostream>
#include "ListIterator.h"
#include "IteratedList.h"


using namespace std;

int IteratedList::alloc()
{
	if (firstEmpty == -1)
	{
		//throw std::exception();
	}
	else
	{
		int p = firstEmpty;
		firstEmpty = arr[firstEmpty].next;
		arr[firstEmpty].prev = -1;
		arr[p].next = arr[p].prev = -1;
		return p;
	}
}

void IteratedList::free(int position)
{

	arr[position].next = firstEmpty;
	arr[position].prev = -1;
	if (firstEmpty != -1)
		arr[firstEmpty].prev = position;
	firstEmpty = position;

}

void IteratedList::resize()
{
	capacity *= 2;
	Nod* newArr = new Nod[capacity];
	int i;
	for ( i = 0; i < length; i++)
		newArr[i] = arr[i];
	while (i != capacity)
	{
		free(i);
		i++;
	}
	firstEmpty = capacity / 2;
}

IteratedList::IteratedList() {
	//TODO - Implementation
	capacity = 1000000;
	arr = new Nod[capacity];
	firstEmpty = -1;
	for (int i = 0; i < capacity; ++i)
	{
		//free(i);
		arr[i].next = i + 1;
		arr[i].prev = i - 1;
	}
	arr[capacity - 1].next = -1;
	firstEmpty = 0;
	length = 0;
	head = -1;
	tail = -1;
	
}

int IteratedList::size() const {
	//TODO - Implementation
	if(!isEmpty())
		return length;
	return 0;
}

bool IteratedList::isEmpty() const {
	//TODO -  Implementation
	if (length == 0)
		return true;
	return false;
}

ListIterator IteratedList::first() const {
	//TODO - Implementation
	ListIterator iterator = ListIterator(*this);
	iterator.first();
	return iterator;
}

TElem IteratedList::getElement(ListIterator pos) const {
	//TODO - Implementation
	if (!pos.valid())
		throw std::exception();
	return arr[pos.pozitie].elem;
}

TElem IteratedList::remove(ListIterator& pos) {
	//TODO - Implementation
	TElem soonToBeDeleted;
	if (!pos.valid())
		throw std::exception();
		//return NULL_TELEM;
	if (pos.pozitie == head)
	{
		soonToBeDeleted = arr[head].elem;
		arr[head].elem = NULL_TELEM;
		head = arr[head].next;
		arr[head].prev = -1;
		free(pos.pozitie);
		length--;
		pos.next();
		return soonToBeDeleted;
	}
	else if (pos.pozitie == tail)
	{
		soonToBeDeleted = arr[tail].elem;
		arr[tail].elem = NULL_TELEM;
		tail = arr[tail].prev;
		arr[tail].next = -1;
		free(pos.pozitie);
		length--;
		//pos.next();
		return soonToBeDeleted;
	}
	else if (head == tail)
	{
		soonToBeDeleted = arr[tail].elem;
		IteratedList();
		return soonToBeDeleted;

	}
	else
	{
		soonToBeDeleted = arr[pos.pozitie].elem;
		arr[arr[pos.pozitie].next].prev = arr[pos.pozitie].prev;
		arr[arr[pos.pozitie].prev].next = arr[pos.pozitie].next;
		free(pos.pozitie);
		length--;
		pos.next();
		return soonToBeDeleted;
	}
}

ListIterator IteratedList::search(TElem e) const{
	//TODO - Implementation
	ListIterator iterator = first();
	while (iterator.valid())
	{
		if (iterator.getCurrent()== e)
			return iterator;
		iterator.next();
	}                                                                  
	return iterator;
}

TElem IteratedList::setElement(ListIterator pos, TElem e) {
    //TODO - Implementation
	//if (arr[pos.pozitie].elem == -11111)
	if(!pos.valid())
		throw std::exception();
	TElem before = arr[pos.pozitie].elem;
	arr[pos.pozitie].elem = e;
	return before;
}

void IteratedList::addToPosition(ListIterator& pos, TElem e) {
    //TODO - Implementation
	if(!pos.valid())
		throw std::exception();
	else if (pos.pozitie == tail)
	{
		int newPos = alloc();
		arr[newPos].prev = tail;
		arr[tail].next = newPos;
		arr[newPos].elem = e;
		tail = newPos;
		length++;
	}
	else
	{
		
		int newPos = alloc();
		arr[newPos].next = arr[pos.pozitie].next;
		arr[newPos].prev = pos.pozitie;
		//arr[arr[pos.pozitie].prev].next = newPos;
		arr[pos.pozitie].next = newPos;
		arr[newPos].elem = e;
		length++;



	}
	pos.next();
}

void IteratedList::addToBeginning(TElem e) {
	//TODO - Implementation
	if (length == capacity)
		resize();
	int newPos = alloc();
	if (isEmpty())
	{
		arr[newPos].elem = e;
		head = newPos;
		tail = newPos;

	}
	else
	{
		arr[newPos].next = head;
		arr[head].prev = newPos;
		arr[newPos].elem = e;
		head = newPos;
	}
	length++;


}

void IteratedList::addToEnd(TElem e) {
	//TODO - Implementation
	int newPos = alloc();
	if (length == capacity)
		resize();
	if (isEmpty())
	{
		arr[newPos].elem = e;
		head = newPos;
		tail = newPos;

	}
	else
	{
		arr[newPos].prev = tail;
		arr[tail].next = newPos;
		arr[newPos].elem = e;
		tail = newPos;
	}
	length++;
}

void IteratedList::removeBetween(ListIterator start, ListIterator stop)
{
	ListIterator it3(*this);
	it3.pozitie = start.pozitie;
	if (!start.valid() || !stop.valid())
		throw std::exception();
	it3.next();
	while (it3.pozitie!=stop.pozitie)
	{
		it3.next();
		free(arr[it3.pozitie].prev);
		cout << arr[it3.pozitie].prev<<" ";
		//it3.next();
	}
	cout << it3.pozitie;
	free(it3.pozitie);
	arr[start.pozitie].next = stop.pozitie;
	arr[stop.pozitie].prev = start.pozitie;
}






IteratedList::~IteratedList() {
	//TODO - Implementation
	//delete[] arr;
}

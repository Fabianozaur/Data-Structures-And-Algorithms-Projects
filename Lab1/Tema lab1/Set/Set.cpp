#include "Set.h"
#include "SetITerator.h"
#include <cmath>
#include <iostream>

using namespace std;

Set::Set() {
	//TODO - Implementation
	lengthPlus=100;
	lengthMinus = 100;
	arrPlus = new bool[lengthPlus];
	for (int i = 0; i < lengthPlus; i++)
		arrPlus[i] = false;
	arrMinus= new bool[lengthMinus];
	for (int i = 0; i < lengthMinus; i++)
		arrMinus[i] = false;
	cont = 0;

}


bool Set::add(TElem elem) {
	//TODO - Implementation
	int newLength;
	if (elem >= 0)
	{
		if (elem >= lengthPlus)
		{
			newLength = elem*2;
			bool* newArrPlus = new bool[newLength];
			for (int i = 0; i < newLength; i++)
				newArrPlus[i] = false;
			for (int i = 0; i < lengthPlus; i++)
				newArrPlus[i] = arrPlus[i];
			delete[] arrPlus;
			arrPlus = newArrPlus;
			lengthPlus = newLength;
			/*for (int i = 0; i < lengthPlus; i++)
				cout << i << " " << arrPlus[i] << " \n";
				*/

		}
		if (arrPlus[elem] == false)
		{
			arrPlus[elem] = true;
			cont++;
			return true;
		}
		return false;
	}
	else
	{
		if (abs(elem) >= lengthMinus)
		{
			newLength = abs(elem)*2;
			bool* newArrMinus = new bool[newLength];
			for (int i = 0; i < newLength; i++)
				newArrMinus[i] = false;
			for (int i = 0; i < lengthMinus; i++)
				newArrMinus[i] = arrMinus[i];
			delete[] arrMinus;
			arrMinus = newArrMinus;
			lengthMinus = newLength;
		}
		if (arrMinus[abs(elem)] == false)
		{
			arrMinus[abs(elem)] = true;
			cont++;
			/*
			for (int i = 0; i < lengthMinus; i++)
				cout << i << " " << arrMinus[i] << " \n";
			*/
			return true;
		}
		return false;
	}

}


bool Set::remove(TElem elem) {
	//TODO - Implementation
	if (-elem >=lengthMinus || elem >=lengthPlus)
		return false;
	if (elem >= 0)
	{

		if (arrPlus[elem] == true)
		{
			arrPlus[elem] = false;
			cont--;
			return true;
		}
		return false;
	}
	else
	{
		if (arrMinus[-elem] == true)
		{
			arrMinus[-elem] = false;
			cont--;
			return true;
		}
		return false;
	}
}

bool Set::search(TElem elem) const {
	//TODO - Implementation
	
	if (elem >= 0)
	{
		if (elem >= lengthPlus)
			return false;
		if (arrPlus[elem] == true)
			return true;
		return false;
	}
	else
	{
		if (-elem >= lengthMinus)
			return false;
		if (arrMinus[-elem] == true)
			return true;
		return false;
	}
}


int Set::size() const {
	//TODO - Implementation

	return cont;

}


bool Set::isEmpty() const {
	//TODO - Implementation
	if (cont == 0)
		return true;
	return false;
}


Set::~Set() {
	//TODO - Implementation
	delete[] arrPlus;
	delete[] arrMinus;
}


SetIterator Set::iterator() const {
	return SetIterator(*this);
}



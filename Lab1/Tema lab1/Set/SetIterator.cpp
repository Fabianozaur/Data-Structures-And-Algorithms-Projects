#include "SetIterator.h"
#include "Set.h"
#include <iostream>
#include <exception>


SetIterator::SetIterator(const Set& m) : set(m)
{
	//TODO - Implementation
	len = set.size();
	minus = 1;
	c = 0;
	justTurnedPlus = 0;
	first();
}


void SetIterator::first() {
	//TODO - Implementation
	minus = 1;
	for (int i = set.lengthMinus -1; i >= 0; i--)
	{

		if (i == 0)
		{
			justTurnedPlus = 1;
			minus = 0;
			break;
		}
		else
			if (set.arrMinus[i] == true)
			{
				current = i;
				c=1;
				return;
			}
	}
	
	for (int i = 0; i < set.lengthPlus; i++)
			if (set.arrPlus[i] == true)
			{
				current = i;
				c=1;
				break;
			}
}


void SetIterator::next() {
	//TODO - Implementation
	if (minus == 1)
	{
		for (int i = current-1; i >= 0; i--)
			if (i == 0)
			{
				minus = 0;
				justTurnedPlus = 1;
				current = -1;
				for (int j =0; j < set.lengthPlus; j++)
					if (set.arrPlus[j] == true)
					{
						current = j;
						c++;
						break;
					}
			}
			else
			{
				if (set.arrMinus[i] == true)
				{
					current = i;
					c++;
					return;
				}
			}
	}
	else
	{for (int i = current+1; i < set.lengthPlus; i++)
			if (set.arrPlus[i] == true)
			{
				justTurnedPlus = 0;
				current = i;
				c++;
				return;
			}
	c++;
	}
}


TElem SetIterator::getCurrent()
{
	//TODO - Implementation
	if (minus == 1)
	{
		if (set.arrMinus[current] == true)
			return -current;
		else 
			return 0;
	}
	else
	{
		if (set.arrPlus[current] == true)
			return current;
		else
			return current;
	}


	//return NULL_TELEM;
}

bool SetIterator::valid() const {
	//TODO - Implementation
	if (len == 0 || len<c || c<=0)
		return false;
	return true;
}
void SetIterator::previous()
{
	if (len == 1)
	{//throw std::exception();
		std::cout << "Nu";
	}
	else
	{
		if (minus == 1)
		{
			for (int i = set.lengthMinus; i >= current; i--)
				if (set.arrMinus[i] == true)
				{
					current = i;
					break;
				}
		}
		else
		{
			if (justTurnedPlus == 1)
			{
				for(int i=1;i<=set.lengthMinus;i++)
					if (set.arrMinus[i] == true)
					{
						justTurnedPlus = 0;
						current = i;
						break;
					}
			}
			else
				for (int i = current; i >=0; i--)
					if (set.arrPlus[i] == true)
					{
						current = i;
						break;
						
					}
		}

	}
}




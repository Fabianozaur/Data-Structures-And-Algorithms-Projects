#include "ShortTest.h"
#include <assert.h>
#include "Set.h"
#include "SetIterator.h"
#include <iostream>
using namespace std;

void testAll() { 
	Set s;
	assert(s.isEmpty() == true);
	assert(s.size() == 0); 
	assert(s.add(5)==true);
	assert(s.add(1)==true);
	assert(s.add(10)==true);
	assert(s.add(7)==true);
	assert(s.add(1)==false);
	assert(s.add(10)==false);
	assert(s.add(-3)==true);
	assert(s.size() == 5);
	assert(s.search(10) == true);
	assert(s.search(16) == false);
	assert(s.remove(1) == true);
	assert(s.search(1) == false);
	assert(s.remove(6) == false);
	assert(s.size() == 4); 
	//added by me
	//assert(s.add(-10000) == true);
	//assert(s.add(-1) == true);
	//assert(s.add(12) == true);

	

	
	SetIterator it = s.iterator();
	it.first();
	int sum = 0;
	while (it.valid()) {
		TElem e = it.getCurrent();
		sum += e;
		it.next();
	}
	assert(sum == 19);

	it.first();
	while (it.valid()) {
		TElem e = it.getCurrent();
		SetIterator it2(it);
		while (it2.valid())
		{
			it2.next();
			//cout << it2.getCurrent() << endl;
			it2.previous();
			cout << it2.getCurrent()<<endl;
			
		}
		it.next();
		cout << endl;
	}
	
	
	

}


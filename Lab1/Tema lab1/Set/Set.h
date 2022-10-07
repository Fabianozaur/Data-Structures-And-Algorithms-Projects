#pragma once
//DO NOT INCLUDE SETITERATOR

//DO NOT CHANGE THIS PART
#define NULL_TELEM -11111
typedef int TElem;
class SetIterator;

class Set {
	//DO NOT CHANGE THIS PART
	friend class SetIterator;

    private:
		//TODO - Representation
        bool* arrPlus;   // this will be the boolean array that includes the numbers wich are bigger or eqal than 0
        bool* arrMinus;  //this will be the boolean array that includes the numbers wich are smaller than 0
        int cont;     //this will count the number of elements added to the set
        int lengthPlus; //this is the lenght of arrPlus
        int lengthMinus;//this is the lenght of arrMinus

    public:
        //implicit constructor
        //Complexity:O(n)
        Set();

        /*
            Adds an element to the set
            Complexity: O(n)
            Input:elemnt of type TElem: e 
            Output: returns True if th elemet was added and false otherwise
        */
        bool add(TElem e);

        /*
            Removes an element from the set
            Complexity: O(1)
            Input: an element of type TElem: e
            Output: returns True if th elemet was removed and false otherwise
        */
        bool remove(TElem e);

        /*
            Checks whether an element belongs to the set or not
            Complexity: O(1)
            Input: an element of type TElem: e
            Output: returns True if th elemet was found and false otherwise
         */
        bool search(TElem elem) const;

        /*
            Returns the number of elements;
            Complexity: O(1)
            Input: none
            Output: returns the size
        */
        int size() const;

        /*
            Check whether the set is empty or not;
            Complexity: O(1)
            Input: none
            Output: returns True if the set is empty and false otherwise
        */
        bool isEmpty() const;

        //return an iterator for the set
        SetIterator iterator() const;

        // destructor
        //Complexity: O(1)
        ~Set();

};






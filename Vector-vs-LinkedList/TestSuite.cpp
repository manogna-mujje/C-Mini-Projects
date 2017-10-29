/*
 * TestSuite.cpp
 *
 *  Created on: Oct 25, 2017
 *      Author: Mango
 */

#include <iostream>
#include <string>
#include "SortedVector.h"
#include "SortedList.h"
#include "Node.h"
#include <cstdlib>
#include <ctime>

using namespace std;

// How many times to do gets.
const int GETS_COUNT = 10000;

void vector_prepends(SortedVector& sv, const int size)
{
	for (int index = size-1; index >= 0; index--)
	{
		sv.prepend(index);
	}
}

void list_prepends(SortedList& sl, const int size)
{
	for (int index = size-1; index >= 0; index--)
			{
				sl.prepend(index);
			}
}

void vector_appends(SortedVector& sv, const int size)
{
	for (int index = 0; index < size; index++)
	   {
		sv.append(index);
		   }
}

void list_appends(SortedList& sl, const int size)
{
	for (int index = 0; index < size; index++)
		{
			sl.append(index);
		}
//	cout<< "List size: " << sl.size() <<endl;
}

void vector_gets(SortedVector& sv, const int size) throw (string)
{
    // First fill the vector data.
    vector_appends(sv, size);
    Node::reset();

    // Loop to access nodes at random positions.
    for (int i = 0; i < GETS_COUNT; i++)
    {
        int index = rand()%size;
        long value = sv.at(index).get_value();

        // Make sure we got the correct node.
        if (index != value) throw string("Vector data mismatch!");
    }
}

void list_gets(SortedList& sl, const int size) throw (string)
{
    // First fill the list data.
    list_appends(sl, size);
//    cout<< "List size: " << sl.size() <<endl;
    Node::reset();

    // Loop to access nodes at random positions.
    for (int i = 0; i < GETS_COUNT; i++)
    {
    		int index = rand()%size;
    	    long value = sl.at(index).get_value();
        /***** Complete this function. *****/

        // Make sure we got the correct node.
       if (index != value) throw string("List data mismatch!");
    }
}

void vector_removes(SortedVector& sv, const int size)
{
    // First fill the vector data.
    vector_appends(sv, size);
    Node::reset();

    // Loop to remove a node at a random position
    // one at a time until the nodes are all gone.
    while (sv.size() > 0)
    {
    		int index = 	rand()%sv.size();
    	    sv.remove(index);
    }
}

void list_removes(SortedList& sl, const int size)
{
    // First fill the list data.
    list_appends(sl, size);
    Node::reset();

    while (sl.size() > 0)
    {
    		int index = rand()%sl.size();
    	    sl.remove(index);
    }
}

void vector_inserts(SortedVector& sv, const int size)
{
  	while(sv.size()<size)
	{
		sv.insert(rand());
	}
}

void list_inserts(SortedList& sl, const int size)
{
	while(sl.size()<size)
	{
		sl.insert(rand());
	}
}

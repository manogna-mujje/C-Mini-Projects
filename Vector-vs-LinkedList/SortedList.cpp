/*
 * SortedList.cpp
 *
 *  Created on: Oct 25, 2017
 *      Author: Mango
 */
#include <iostream>
#include <iterator>
#include "SortedList.h"

using namespace std;

SortedList::SortedList()
{
    Node::reset();
}

SortedList::~SortedList()
{
    Node::reset();
}

int SortedList::size() const { return data.size(); }

bool SortedList::check()
{
    if (data.size() == 0) return true;

    list<Node>::iterator it = data.begin();
    list<Node>::iterator prev = it;

    it++;

    // Ensure that each node is greater than the previous node.
    while ((it != data.end()) && (*it > *prev))
    {
        prev = it;
        it++;
    }

    return it == data.end();  // Good if reached the end.
}

void SortedList::prepend(const long value)
{
	Node temp(value);
	data.push_front(temp);
}



void SortedList::append(const long value)
{
	Node temp(value);
	data.push_back(temp);
}

void SortedList::remove(const int index)
{
    int count = 0;
    list<Node>::iterator it = data.begin();
    while (it != data.end())
    {
    	   if(count == index)
    	   {
		   it = data.erase(it);
    	   }
    	   count++;
	   it++;
    }
}

void SortedList::insert(const long value)
{
	Node temp(value);
	int size = data.size();
	//When the container is empty
	if (size == 0)
	{
		data.push_back(temp);
		return;
	}
	else
	{
		//Add to the beginning if the value is the less than that of the first element
		if(value < data.front().get_value())
		{
			prepend(value);
			return;
		}
		//Add to the end if the value is the more than that of the last element
		else if(value > data.back().get_value())
		{
			append(value);
			return;
		}
		//Insert in the appropriate position of the vector
		else if(value > data.front().get_value() && value < data.back().get_value())
		{
			list<Node>::iterator it= data.begin();
			list<Node>::iterator prev = it;
			while(it != data.end())
			{
				advance(it,1);
				if ((temp > *prev) && (*it > temp))
				{
					data.insert(it, temp);
				}
				++prev;
			}
			return;
		}
	}
}

Node SortedList::at(const int index)
{
	list<Node>::iterator it = data.begin();
	while (it != data.end())
	{
		if(it->get_value() == index)
		{
			return *it;
		}
		it++;
	}
}

int SortedList::size()
{
	int count = 0;
	list<Node>::iterator it = data.begin();
	while (it != data.end())
	{
	   count++;
	   it++;
	}
	return count;
}


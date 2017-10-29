#include <iostream>
#include <iterator>
#include <vector>
#include "SortedVector.h"

using namespace std;

SortedVector::SortedVector()
{
    Node::reset();
}

SortedVector::~SortedVector()
{
    Node::reset();
}

int SortedVector::size() const { return data.size(); }

bool SortedVector::check() const
{
    if (data.size() == 0) return true;

    vector<Node>::const_iterator it = data.begin();
    vector<Node>::const_iterator prev = it;

    it++;

    // Ensure that each node is greater than the previous node.
    while ((it != data.end()) && (*it > *prev))
    {
        prev = it;
        it++;
    }

    return it == data.end();  // Good if reached the end.
}

void SortedVector::prepend(const long value)
{
	int size = data.size();
	if (size == 0)
	{
		Node first(value);
		data.push_back(first);
	}
	else
	{
		Node temp(value);
		if(data[0] > temp)
		{
			data.insert(data.begin(), temp);
			return;
		}
	}
}

void SortedVector::append(const long value)
{
	int size = data.size();
	if (size == 0)
	{
		Node first(value);
		data.push_back(first);
	}
	else
	{
		Node temp(value);
		if(temp > data[size-1])
		{
			data.push_back(temp);
		}
	}

}

void SortedVector::remove(const int index)
{
	vector<Node>::const_iterator it = data.begin() + index;
	it = data.erase(it);
}

void SortedVector::insert(const long value)
{
	Node temp(value);
	int size = data.size();
	//Push back when the container is empty
	if (size == 0)
	{
		Node first(value);
		data.push_back(first);
		return;
	}
	else
	{
		//Add to the beginning if the value is the less than that of the first element
		vector<Node>::const_iterator it = data.begin();
		if(value < data[0].get_value())
		{
			prepend(value);
			return;
		}
		//Add to the end if the value is the more than that of the last element
		else if(value > data[size-1].get_value())
		{
			append(value);
			return;
		}
		else
		{
			//Insert in the appropriate position of the vector
			while(it != data.end())
			{
				it++;
				if (value > prev(it,1)->get_value() && value < it->get_value())
				{
					Node temp(value);
					data.insert(it, temp);
					return;
				}
			}
		}
	}
}


Node SortedVector::at(const int index) const
{
	return data[index];
}

/*
 * BookList.cpp
 *
 *  Created on: Oct 17, 2017
 *      Author: Manogna Sindhusha Mujje
 */

#include <iostream>
#include "BookList.h"
#include "BookNode.h"
#include <cassert>

using namespace std;

BookList::BookList(const string name)
    : name(name), head(nullptr), tail(nullptr)
{
}

void BookList::print(string category)
{
   cout << endl;
	cout << "Book list: " << category << endl;
	cout << endl;
	Iterator iter = this -> begin();
	int count = 0;
	while(!iter.past_end())
	{
		count++;
		cout << iter.get() << endl;
		iter.next();
	}
	cout << "   (" << count << " Books)" << endl;
}

void BookList::push_front(Book b)
{
	BookNode* new_node = new BookNode(b);
	if (head == nullptr)
	{
		new_node -> next = nullptr;
		tail = new_node;
	}
	else
	{
		new_node -> next = head;
	}
	head = new_node;
}

void BookList::push_back(Book b)
{
	BookNode* new_node = new BookNode(b);
	tail -> next = new_node;
	tail = new_node;
}

Iterator BookList::begin()
{
	Iterator iter;
	iter.container = this;
   	iter.position = head;
	return iter;
}

Iterator BookList::end()
{
	Iterator iter;
	iter.position = NULL;
	iter.container = this;
	return iter;
}

bool Iterator::past_end() const
{
   if (position != nullptr)
   {
      return false;
   }
   else
   {
      return true;
   }
}

Book Iterator::get() const
{
   assert(!past_end());
   return(position -> book);
}

bool Iterator::operator==(const Iterator& i)
{
	return position == i.position;
}

void Iterator::next()
{
	assert(!past_end());
	position = position -> next;
	return;
}
void BookList::create(Book b)
{
	if(head == nullptr && tail == nullptr)
	{
		push_front(b);
	}
	else
	{
		for(Iterator i = this -> begin(); !(i== this -> end()); i.next())
		{
			if(i.get().isbn == b.isbn)
			{
				return;
			}
			else
			{
				long nodeNum = stol(i.get().isbn.substr(4,10));
				long bNum = stol(b.isbn.substr(4,10));
				if((bNum < nodeNum) && (head->book == i.get()))
				{
					push_front(b);
					return;
				}
				else if((bNum > nodeNum) && (tail->book == i.get()))
				{
					push_back(b);
					return;
				}
				else if((bNum > nodeNum) && !(tail->book == i.get()))
				{
					BookNode* before = i.position;
					BookNode* after = before->next;
					int nextNodeNum = stol((after->book).isbn.substr(4,10));
					if(bNum < nextNodeNum)
					{
						BookNode* new_node = new BookNode(b);
						before->next = new_node;
						new_node->next = after;
						return;
					}
				}
			}
		}
	}
}

BookList BookList:: merge(vector<BookList> catalog)
{
	int size = catalog.size();
	for (int i = 0; i< size; i++)
	{
		Iterator iter;
		iter =  catalog[i].begin();
		while(!iter.past_end())
		{
			Book b = iter.position -> getBook();
			this -> create(b);
			iter.next();
		}
	}
	return *this;
}

void BookList::split(BookList& splitOne, BookList& splitTwo)
{
   Iterator iter;
	iter =  this -> begin();
	while(!iter.past_end())
	{
		Book b = iter.position -> getBook();
		string lName = b.getLast();
		for(int i = 65; i <= 77; i++)
		{
		   	if(lName[0] == i)
			{
			   splitOne.create(b);
			}
		}
		for(int i = 78; i <= 90; i++)
		{
		   if(lName[0] == i)
			{
			   splitTwo.create(b);
			}
		}

		iter.next();
	}
}

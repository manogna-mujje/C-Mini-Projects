/*
 * BookList.h
 *
 *  Created on: Oct 17, 2017
 *      Author: Manogna Sindhusha Mujje
 */

#ifndef BOOKLIST_H_
#define BOOKLIST_H_

#include "BookNode.h"
#include <string>

using namespace std;

class Iterator;

/**
 * A list of book nodes.
 */
class BookList
{
public:
    /**
     * Constructor.
     * @param name the name of this list.
     */
    BookList(const string name);

    /**
     * Print the list.
     */
    void print(string category);

    /**
     * Function to create Node with a book
     */
    void create(Book b);

    /**
	 * Functions supporting create List.
	 */
    void push_front(Book b);
    void push_back(Book b);

    /**
     * Functions to run the Iterator through Linked Lists.
     */
    Iterator begin();
    Iterator end();

   /**
    * Merge and Split Functions.
    */
    BookList merge(vector<BookList> catalog);
    void split(BookList& splitOne, BookList& splitTwo);

private:
    string name;      // name of this book list
    BookNode *head;   // head of the list of book nodes
    BookNode *tail;   // tail of the list of book nodes
};

class Iterator
{
	public:

	   bool past_end() const;
	   void next();
	   Book get() const;

	   //Equal to Operatoe overloading
	   bool operator==(const Iterator& i);

	private:
	   BookNode* position;
	   BookList* container;
	friend class BookList;
};

#endif /* BOOKLIST_H_ */


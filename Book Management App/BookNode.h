/*
 * BookNode.h
 *
 *  Created on: Oct 17, 2017
 *      Author: Manogna Sindhusha Mujje
 */

#ifndef BOOKNODE_H_
#define BOOKNODE_H_

#include "Book.h"

/**
 * A book node in a linked list.
 */
class BookNode
{
public:
    /**
     * Constructor.
     * @param book this node's book.
     */
    BookNode(Book book);

    /**
     * Getter function.
     */
    	Book getBook() const;

    /**
     * == Operator Overloading.
     */
    bool operator ==(const BookNode& bn);

   /**
    *  Friend Classes Declaration.
    */
    friend class Iterator;
    friend class BookList;


private:
    Book book;       // this node's book
    BookNode *next;  // link to the next node in the list
};



#endif /* BOOKNODE_H_ */

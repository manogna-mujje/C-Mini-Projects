/*
 * BookNode.cpp
 *
 *  Created on: Oct 17, 2017
 *      Author: Manogna Sindhusha Mujje
 */
/***** Complete this file. *****/

#include <string>
#include "Book.h"
#include "BookNode.h"

using namespace std;

BookNode::BookNode(Book book)
{
	this->book = book;
	next = nullptr;
}

Book BookNode::getBook() const
{
	return book;
}

bool BookNode::operator ==(const BookNode& bn)
{
	return(this->book == bn.book);
}

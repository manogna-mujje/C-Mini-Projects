/*
 * Book.cpp
 *
 *  Created on: Oct 17, 2017
 *      Author: Manogna Sindhusha Mujje
 */

#include "Book.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

Book::Book()
{
	this->isbn = ("");
	this->last = ("");
	this->first= ("");
	this->title = ("");
}

Book::Book(string isbnNum, string lastName, string firstName, string bookTitle)
{
	isbn = isbnNum;
	last = lastName;
	first = firstName;
	title = bookTitle;
}
Book::~Book()
{
}

string Book::getIsbn() const
{
	return isbn;
}

string Book::getLast() const
{
   return last;
}

istream& operator >>(istream& input, Book& b)
{
	getline(input,b.isbn, ',');
	getline(input,b.last, ',');
	getline(input,b.first, ',');
	getline(input,b.title, '\n');
	return input;
}

ostream& operator <<(ostream& output, const Book& b)
{
	output << " Book" << "{" << "ISBN="  <<  b.isbn << "," << " last="
		   << b.last << "," <<  " first="  << b.first << "," << " title=" << b.title << "}";
	return output;
}

bool Book::operator ==(const Book& b)
{
	if(this->first == b.first && this->last == b.last && this->title == b.title && this->isbn == b.isbn)
		return true;
	else
		return false;
}

/*
 * Book.h
 *
 *  Created on: Oct 17, 2017
 *      Author: Manogna Sindhusha Mujje
 */

#ifndef BOOK_H_
#define BOOK_H_

#include <string>
#include <vector>


using namespace std;

class Book
{
	public:
	    /**
		 * Default constructor.
		 */
		Book();

		/**
		 * Constructor.
		 */
		Book(string isbn, string last, string first, string title);

		/**
		 * Destructor.
		 */
		~Book();

		string getIsbn() const;
		string getLast() const;

		/**
		 * Insertion and Extraction Operator Overloading.
		 */
		 friend ostream& operator <<(ostream& output, const Book& b);
		 friend istream& operator >>(istream& input, Book& b);

      /**
       * Friend Classes
       */
      friend class BookList;
      friend class Iterator;

		 /**
		  * == Operator Overloading
		  */
		 bool operator ==(const Book& b);

	private:
		string isbn;
		string last;
		string first;
		string title;
};



#endif /* BOOK_H_ */

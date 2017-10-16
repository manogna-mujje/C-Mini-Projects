/*
 * Book.h
 *
 *  Created on: Oct 3, 2017
 *      Author: Manogna Sindhusha Mujje
 */

#ifndef BOOK_H_
#define BOOK_H_

#include <vector>
#include <string>
using namespace std;

/***** Complete this file. *****/

/**
 * The Book class.
 */
class Book
{
public:
   struct bookIsbn
	{
    		int code;
    		char ch = '-';
    		int number;
	};
   bookIsbn fullIsbn;
    /**
     * Book categories.
     */
    enum class Category { FICTION, HISTORY, TECHNICAL, NONE };

    /**
     * Default constructor.
     */
    Book();

    /**
     * Constructor.
     */
    Book(string isbn, string last, string first, string title, Category category);

    /**
     * Destructor.
     */
    ~Book();

    /**
     * Insertion and Extraction Operator Overloading.
     */
    	 friend ostream& operator <<(ostream& output, const Book& b);
	 friend istream& operator >>(istream& input, Book& b);

	/*
	 * Functions to insert, remove and find books in catalog
	 */

	 vector<Book> insert(vector<Book> shelf, Book b);
	 vector<Book> remove(vector<Book> shelf, int position);
	 friend vector<Book> filter(vector<Book> shelf, string s);

	/*
	 * Search Functions
	 */
	 friend int binarySearch(vector<Book> shelf, int search);
	 friend vector<Book> linearSearch(vector<Book> shelf, string search, string key);

private:

	string strIsbn;
	string authorLname;
	string authorFname;
	string bookTitle ;
	string categ;
};



#endif /* BOOK_H_ */

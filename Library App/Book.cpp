/*
 * Book.cpp
 *
 *  Created on: Oct 3, 2017
 *      Author: Manogna Sindhusha Mujje
 */
#include "Book.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

Book::Book()
{

}

Book::Book(string isbn, string last, string first, string title, Category category)
{
//   cout << "Constructor with parametes called" << endl;
	int isbnLen = isbn.length();
	//Assigning the string isbn to struct bookIsbn
//	bookIsbn fullIsbn;

	//Converting string types to their corresponding integer values
	fullIsbn.code = stoi(isbn.substr(0,3));
	fullIsbn.number = stoi(isbn.substr(5, (isbnLen-4)));

//	bookIsbn = isbn;
	authorLname = last;
	authorFname = first;
	bookTitle = title;
//	categ = category;

   if(category == Category:: TECHNICAL)
   {
      categ = "technical";
   }
   else if(category == Category:: HISTORY)
   {
      categ = "history";
   }
   else if(category == Category:: FICTION)
   {
      categ = "fiction";
   }
   else if(category == Category:: NONE)
   {
      categ = "none";
   }
//   cout << "Constructor with params ended" << endl;
}

Book::~Book()
{

}
vector<Book> Book::insert(vector<Book> shelf, Book b)
{
   int size = shelf.size();
	int posLeft = 0;
	if (shelf.size() == 0)
	{
		shelf.push_back(b);
		cout << "Inserted at index " << 0 << ":" <<  b << endl;
		return shelf;
	}
	else
	{
		for(int i = 0; i < size; i++)
		{
			if (shelf[i].fullIsbn.number == b.fullIsbn.number)
			{
			   cout << "Inserted at index " << i << ":" <<  b << endl;
				return shelf;
			}
			else if ((shelf[i].fullIsbn.number > b.fullIsbn.number)
					&& (shelf[i+1].fullIsbn.number < b.fullIsbn.number))
			{
				posLeft = i;
			   break;
			}
		}
		if (posLeft >= 0)
   	{
   	   shelf.insert(shelf.begin() + (posLeft+1), b);
   	   cout << "Inserted at index " << posLeft+1 << ":" <<  b << endl;
   	}
	return shelf;
	}

}

vector<Book> Book::remove(vector<Book> shelf, int position)
{
	cout << "Removed" << shelf[position-1] << endl;
	shelf.erase(shelf.begin() + position-1);
	return shelf;
}

vector<Book> filter(vector<Book> shelf, string s)
{
	vector <Book> result;
	if (s.length() == 0)
	{
		cout << "All books in the catalog:" << endl;
		for (int i = 0; i < shelf.size(); i++)
		{
		   cout << shelf[i] << endl;
		}
		return result;
	}
	else
	{
		int len = s.length();
		string lhs, rhs;
		for (int i = 0; i < len; i++)
		{
			if(s[i] == '=')
			{
				lhs = s.substr(1, i-1);
				rhs = s.substr(i+1, len-i);
				break;
			}
		}
		if(lhs == "isbn")
		{
		   int len = rhs.length();
		   rhs = rhs.substr(4, (len-4));
			int position = binarySearch(shelf, stoi(rhs));
			cout << "Book with ISBN 978-" << rhs << ":" << endl;
			if (position != -1)
			{
			   result.push_back(shelf[position-1]);
			}
		}
		else
		{
			result = linearSearch(shelf, lhs, rhs);
		}
		return result;
	}

}
int binarySearch(vector<Book> shelf, int search)
{
	int n = shelf.size(), i, first, last, middle;
	first = 0;
	last = n-1;
 	while (first <= last)
	{
	   middle = (first+last)/2;
	   shelf[middle].fullIsbn.number = -1 * shelf[middle].fullIsbn.number;
		if(shelf[middle].fullIsbn.number < search)
		{
			first = middle + 1;

		}
		else if(shelf[middle].fullIsbn.number == search)
		{
			return (middle+1);
		}
		else
		{
			 last = middle - 1;
		}
		middle = (first + last)/2;
	}
	if (first > last)
	{
	   return -1;
	}
}

vector<Book> linearSearch(vector<Book> shelf, string search, string key)
{
	vector <Book> result;
	int size = shelf.size();
	for (int i = 0; i < size; i++)
	{
		if(search == "author")
		{
			if(shelf[i].authorLname == key)
			{
				result.push_back(shelf[i]);
			}
		}
		else if(search == "category")
		{
			if(shelf[i].categ == key)
			{
				result.push_back(shelf[i]);
			}
		}
	}
	if (search == "author")
	{
		cout << "Books by author " << key << ":" << endl;
	}
	else if (search == "category")
	{
		cout << "Books in category " << key << ":" << endl;
	}
	return result;
}

istream& operator >>(istream& input, Book& b)
{
   string str[5], line;
   for (int i = 0; i < 4; i++)
   {
		getline(input, str[i], ',');
   }
   getline(input, str[4]);

	int isbnLen = str[0].length();
	b.strIsbn = str[0].substr(1,isbnLen);
	b.fullIsbn.code = stoi(str[0].substr(0,4));
	b.fullIsbn.number = stoi(str[0].substr(4, (isbnLen-4)));
	b.authorLname = str[1];
	b.authorFname = str[2];
	b.bookTitle = str[3];
	b.categ = str[4];

	return input;
}

ostream& operator <<(ostream& output, const Book& b)
{
	output << " Book" << "{" << "ISBN="  <<  b.strIsbn
	<< "," << " last="<< b.authorLname << ","
	<<  " first="  << b.authorFname << "," << " title=" << b.bookTitle
			<< "," << " category=" <<  b.categ << "}";
	return output;
}

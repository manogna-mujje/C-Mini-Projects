/*
 * BookListsApp.cpp
 *
 *  Created on: Oct 17, 2017
 *      Author: Manogna Sindhusha Mujje
 */
#include <iostream>
#include <fstream>
#include <string>
#include "Book.h"
#include "BookNode.h"
#include "BookList.h"

using namespace std;

class BookList;

const string CATEGORIES_FILE_NAME = "categories.txt";

/**
 * The main. Create and print the book lists.
 */
int main()
{
	Book book;
	string category;
	vector<BookList> catalog; //Vector to store each of the linked lists
	ifstream infile;

	infile.open(CATEGORIES_FILE_NAME);
	if (infile.fail())
	{
		cout << "Failed to open " << CATEGORIES_FILE_NAME << endl;
		return -1;
	}
	while (infile >> category)
	{
		BookList section(category);
		ifstream inlist;
		inlist.open(category+".txt");
		if (inlist.fail())
		{
			cout << "Failed to open" << category+".txt" << endl;
			return -1;
		}
		while(!inlist.fail())
		{
			inlist >> book;
			if (book.getIsbn() != "")
			{
				section.create(book);
			}
		}
		catalog.push_back(section);
		section.print(category);
	}

	// Merge Lists and print.

	BookList mergeList("MERGED");
	mergeList.merge(catalog);
	mergeList.print("MERGED");

	// Split Lists into two and print

	BookList splitOne("AUTHORS A-M");
	BookList splitTwo("AUTHORS N_Z");
	mergeList.split(splitOne, splitTwo);
	splitOne.print("AUTHORS A-M");
	splitTwo.print("AUTHORS N_Z");

	return 0;
}

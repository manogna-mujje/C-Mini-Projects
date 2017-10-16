/*
 * BookApp.cpp
 *
 *  Created on: Oct 3, 2017
 *      Author: Manogna Sindhusha Mujje
 */

#include <iostream>
#include <fstream>
#include "Book.h"
#include <string>
#include <vector>


/***** Complete this file. *****/

using namespace std;

// Status codes.
enum class StatusCode {OK, DUPLICATE, NOT_FOUND, INVALID_COMMAND};

const string INPUT_FILE_NAME = "commands.in";

/**
 * The main. Open the command input file and loop to process commands.
 */
int main()
{
    // Open the input file.
    ifstream input;
    input.open(INPUT_FILE_NAME);
    if (input.fail())
    {
        cout << "Failed to open " << INPUT_FILE_NAME << endl;
        return -1;
    }

    vector<Book> catalog;  // book catalog

    char command;
    input >> command;  // read the first command

    string status;
    /**
     * Loop to read commands until the end of file.
     */
    while (!input.fail())
    {
		cout << endl << command << " ";

		/*** Complete this main. *****/

		if(command == '+')
		{
		   int prevSize = catalog.size();
			Book b;
			input >> b;
			catalog = b.insert(catalog, b); //Function to insert book
			if (catalog.size() == prevSize)
			{
				status = "*** Duplicate ISDN ***";
				cout << status << endl;
			}
		}
		else if(command == '-')
		{
	   	int prevSize = catalog.size();
			string removeIsbn;
			getline(input, removeIsbn);
			removeIsbn = removeIsbn.substr(5, (removeIsbn.size()-4));
			int position = binarySearch(catalog, stoi(removeIsbn));
			if (position >= 0)
			{
				catalog = catalog[position].remove(catalog, position);//Function to remove book
			}
			else
			{
			   cout << "Removed Book{ISBN=978-" << removeIsbn <<
			   ", last=, first=, title=, category=none}" << endl;
				status = "*** Book not found ***";
				cout << status << endl;
			}
		}
		else if(command == '?')
		{
	   	int prevSize = catalog.size();
		   vector <Book> result;
			string findData;
			getline(input, findData);
			result = filter(catalog, findData);//Function to filter books
			int resLen = result.size();
			for (int i = 0; i < resLen; i++)
			{
				cout << result[i] << endl;
			}
			if (catalog.size() == prevSize)
			{
				status = "*** Book not found ***";
			}
		}
		else
		{
		   string space;
			getline(input, space);
			status = "*** Invalid command ***";
			cout << status << endl;
		}

		input >> command; // read the next command
    }
    return 0;
}



/*
 * frsh.cpp
 *
 *  Created on: Sep 15, 2017
 *      Author: Manogna Sindhusha Mujje
 */

#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

const int MAX_START = 50;   // maximum starting number
/* To check whether the size and starting value are appropiate and initialize a vector of vectors to all zeroes
 * @param: size of the matrix
 * @param: starting value
 */
void do_prime_spiral(const int n, const int start);

/* To make the prime spiral and update the values in the matrix to appropriate values
 * @param: matrix reference
 * @param: matrix size
 * @param: starting value of matrix
 */
void make_prime_spiral(vector<vector<int> > &table, int n, int start);

/* To check the prime numbers and print the prime spiral accordingly
 * @param: matrix reference
 * @param: matrix size
 */
void print_prime_spiral(vector<vector<int> > &table, int n);

/* To update the values of matrix when moving in right direction
 * @param: matrix reference
 * @param: Number of steps taken in right direction
 * @param: Current row
 * @param: Current column
 * @param: Value of the element in that position
 */
void go_right(vector<vector<int> > &table, const int numsteps, int &row, int &col, int &val);

/* To update the values of matrix when moving in right direction
 * @param: matrix reference
 * @param: Number of steps taken in upward direction
 * @param: Current row
 * @param: Current column
 * @param: Value of the element in that position
 */
void go_up(vector<vector<int> > &table, const int numsteps, int &row, int &col, int &val);

/* To update the values of matrix when moving in right direction
 * @param: matrix reference
 * @param: Number of steps taken in left direction
 * @param: Current row
 * @param: Current column
 * @param: Value of the element in that position
 */
void go_left(vector<vector<int> > &table, const int numsteps, int &row, int &col, int &val);

/* To update the values of matrix when moving in right direction
 * @param: matrix reference
 * @param: Number of steps taken in downward direction
 * @param: Current row
 * @param: Current column
 * @param: Value of the element in that position
 */
void go_down(vector<vector<int> > &table, const int numsteps, int &row, int &col, int &val);

/**
 * The main: Generate and print spirals of various sizes.
 */
int main()
{
    do_prime_spiral(5, 1);
    do_prime_spiral(25, 11);
    do_prime_spiral(35, 0);
    do_prime_spiral(50, 31);
    do_prime_spiral(101, 41);
}
void do_prime_spiral(const int n, const int start)
{
	cout << "Prime spiral of size " << n << " starting at " << start << endl;

	if (start < 1 || start > 50)
	{
		cout << "***** Error: Starting value " << start << " < 1 or > 50" << endl;
		cout << endl;
	}
	else if (n % 2 == 0)
	{
		cout << "***** Error: Size " << n << " must be odd." << endl;
		cout << endl;
	}
	else
	{
		int rows, columns;
		vector< vector<int> > vec;

		for (int i = 0; i < n; i++) 
		{
		    vector<int> row; // Create an empty row
		    for (int j = 0; j < n; j++) 
		    {
		        row.push_back(0); // Add "0" as an element (column) to the row
		    }
		    vec.push_back(row);// Add this row to the vector
		}
		make_prime_spiral(vec, n, start);
		print_prime_spiral(vec, n);
	}
}
void make_prime_spiral(vector<vector<int> > &table, int n, int start)
{
	string direction[4] = {"right", "up", "left", "down"};
	int value, curr_row, curr_col;
	curr_row = (n-1)/2;
	curr_col = (n-1)/2;
	table[curr_row][curr_col] = start;
	value = start;

	// Generate an array to store the number of steps taken in each direction

	vector<int> steps;
	for (int i = 1; i < n; i++)
	{
		int count = 0;
		while(count < 2)
		{
			count++;
			steps.push_back(i);
		}
	}
	steps.push_back(n-1);
	int size = steps.size();


//Assigning the direction while making the steps

	int di = 0; // Index to the direction array
	int i = 0, k = 0;// i is the main vector index and k is the index to steps vector
	while(i < n*n - 1)
	{
		//Assign the start value to mid subscript
		di = k % 4;
		int  num = steps[k];

		if (direction[di] == "right")
		{
			go_right(table, num, curr_row, curr_col, value);
			i = i + num;
		}
		if (direction[di] == "up")
		{
			go_up(table, num, curr_row, curr_col,value);
			i = i + num;
		}
		if (direction[di] == "left")
		{
			go_left(table, num, curr_row, curr_col,value);
			i = i + num;
		}
		if (direction[di] == "down")
		{
			go_down(table, num, curr_row, curr_col,value);
			i = i + num;
		}
		k = k+1;
	}
}
// Assingning the array elements to their respective values in the spiral
// While going right
void go_right(vector<vector<int> > &table, const int numsteps, int &row, int &col, int &val)
{
	for (int i = 0; i < numsteps; i++)
	{
		col = col + 1; //Column number gets incremented by 1
		val = val + 1;
		table[row][col] = val;
	}
}
//While going up
void go_up(vector<vector<int> > &table, const int numsteps, int &row, int &col, int &val)
{
	for (int i = 0; i < numsteps; i++)
	{
		row = row - 1; //Row number gets decremented by 1
		val = val + 1;
		table[row][col] = val;
	}
}
//While going left
void go_left(vector<vector<int> > &table, const int numsteps, int &row, int &col, int &val)
{
	for (int i = 0; i < numsteps; i++)
	{
		col = col - 1; //Column number gets decremented by 1
		val = val + 1;
		table[row][col] = val;
	}
}
//While going down
void go_down(vector<vector<int> > &table, const int numsteps, int &row, int &col, int &val)
{
	for (int i = 0; i < numsteps; i++)
		{
			row = row + 1; //Row number gets incremented by 1
			val = val + 1;
			table[row][col] = val;
		}
}

//Check whether the  number is prime and print the values accordingly
void print_prime_spiral(vector<vector<int> > &table, int n)
{
	cout << endl;
	// To select each of the values from the vector
	for (int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			bool flag = true;
			if (table[i][j] == 1)
			{
				flag = false;
			}
			for (int k = 2; k <= table[i][j]/2; ++k) // Loop the numbers upto less than half of current number
			{
				if (table[i][j] % k == 0) // Checking if the number is divisible by any of these numbers
				{
					flag = false;
					break;
				}

			}
			if (flag)
			{
				cout << "#" ;
			}
			else
			{
				cout << "." ;
			}
		}
		cout << endl;
	}
	cout << endl;
}

/*
 * mrngspirals.cpp
 *
 *  Created on: Sep 15, 2017
 *      Author: Manogna Sindhusha Mujje
 */
#include <iostream>
#include <iomanip>

using namespace std;

const int MAX_SIZE  = 101;  // maximum size of the square matrix
const int MAX_START = 50;   // maximum starting number


void make_spiral(int [][MAX_SIZE], int n, int start);
void print_spiral(int [][MAX_SIZE], int n);
void do_spiral(const int n, const int start);
void go_right(int arr[][MAX_SIZE],int numsteps, int &row, int &col, int &val);
void go_up(int arr[][MAX_SIZE], int numsteps, int &row, int &col, int &val);
void go_left(int arr[][MAX_SIZE], int numsteps, int &row, int &col, int &val);
void go_down(int arr[][MAX_SIZE], int numsteps, int &row, int &col, int &val);

/**
 * The main: Generate and print spirals of various sizes.
 */
int main()
{
    do_spiral(1, 1);
    do_spiral(5, 1);
    do_spiral(9, 11);
    do_spiral(12, 13);
    do_spiral(15, 17);
}
void do_spiral(const int n, const int start)
{
	cout << "Spiral of size " << n << " starting at " << start << endl;

	if (n % 2 == 0)
	{
		cout << "***** Error: Size " << n << " must be odd." << endl;
		cout << endl;
	}
	else
	{
		int array[MAX_SIZE][MAX_SIZE];
		make_spiral(array, n, start);
		print_spiral(array, n);
	}
}
void make_spiral(int arr[][MAX_SIZE], int n, int start)
{
	string direction[4] = {"right", "up", "left", "down"};
	int value, curr_row, curr_col;
	curr_row = (n-1)/2;
	curr_col = (n-1)/2;
	arr[curr_row][curr_col] = start;
	value = start;

	// Generate an array to store the number of steps taken in each direction

	int j = 0, steps[MAX_SIZE*MAX_SIZE] = {};
	for (int i = 1; i < n; i++)
	{
		int count = 0;
		while(count < 2)
		{
			count++;
			steps[j] = i;
			j = j+1;
		}
	}
	steps[j] = steps[j-1];

//Assigning the direction while making the steps

	int di; // Index to the direction array
	for (int i = 0; i < n*n; i++)
	{
		di = i % 4;
		if (direction[di] == "right")
		{
			go_right(arr,steps[i], curr_row, curr_col,value);
		}
		if (direction[di] == "up")
		{
			go_up(arr, steps[i], curr_row, curr_col,value);
		}
		if (direction[di] == "left")
		{
			go_left(arr, steps[i], curr_row, curr_col,value);
		}
		if (direction[di] == "down")
		{
			go_down(arr, steps[i], curr_row, curr_col,value);
		}
	}
}
// Assingning the array elements to their respective values in the spiral
// While going right
void go_right(int arr[][MAX_SIZE],int numsteps, int &row, int &col, int &val)
{
	for (int i = 0; i < numsteps; i++)
	{
		col = col + 1; //Column number gets incremented by 1
		val = val + 1;
		arr[row][col] = val;
	}
}
//While going up
void go_up(int arr[][MAX_SIZE], int numsteps, int &row, int &col, int &val)
{
	for (int i = 0; i < numsteps; i++)
	{
		row = row - 1; //Row number gets decremented by 1
		val = val + 1;
		arr[row][col] = val;
	}
}
//While going left
void go_left(int arr[][MAX_SIZE], int numsteps, int &row, int &col, int &val)
{
	for (int i = 0; i < numsteps; i++)
	{
		col = col - 1; //Column number gets decremented by 1
		val = val + 1;
		arr[row][col] = val;
	}
}
//While going down
void go_down(int arr[][MAX_SIZE], int numsteps, int &row, int &col, int &val)
{
	for (int i = 0; i < numsteps; i++)
		{
			row = row + 1; //Row number gets incremented by 1
			val = val + 1;
			arr[row][col] = val;
		}
}

//Printing the values in a 2d array
void print_spiral(int arr[][MAX_SIZE], int n)
{
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cout << setw(4) << arr[i][j] << " " ;
		}
		cout << endl;
	}
	cout << endl;
}

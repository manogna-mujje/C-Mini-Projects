/*
 * primes.cpp
 *
 *  Created on: Sep 13, 2017
 *      Author: Mango
 */
#include <iostream>
#include <iomanip>

using namespace std;

const int MAX_NUMBER = 1000;  // maximum possible prime number
const int ROW_SIZE   = 20;    // row size for printing


void compute_primes(int x[]); // To compute prime numbers
void print_primes(int p[], int q[]);// To print prime numbers


int main()
{
	//Defining an array with all the values upto maximum
	//Defining the starting value and setting to 1
	int arr[MAX_NUMBER], num = 1;
	// Pushing each the values one by one in to the array
	for (int i = 0; i < MAX_NUMBER ; i++)
	{
		arr[i] = num++;
	}
	compute_primes(arr);
	return 0;
}
void compute_primes(int array[])
{
	bool flag;
	int status[MAX_NUMBER] = {};
	status[0] = 1;

	//Declaring the index of array element as 'iter'
	//	Declaring the next value and setting to 1 by accessing it through array elements
	int iter = 1, next = array[iter];

	// To loop until the square of next number isn't greater than maximum number
	while(next * next < MAX_NUMBER)
	{
		// Inner loop iterates through all numbers until maximum
		for(int i = next; i < MAX_NUMBER; i++)
		{
			if(array[i] % next == 0)
			{
				status[i] = 1;
				flag = false; //set the flag value to '1' for composite numbers
			}
		}
		// To increase the next number to next non-composite value
		while(flag == false)
		{
			iter = iter + 1;
			if (status[iter] == 0 )
			{
				flag = true;
				next = array[iter];
			}
		}
	}
	print_primes(array,status);
	return;
}
/**Original array containing all numbers is passed through parameter p[] and
 * status array is passed through q[] */

void print_primes(int p[], int q[])
{
	int element;

/**Accessing each of the array values and priting the values by comparing it with the
 * corresponding elements in status array **/
	for (int i = 1; i < MAX_NUMBER; i++)
		{
			if (q[i] == 0)
			{
				element++;
				cout << right << p[i] << " " <<setw(3);
				if (element % 20 == 0) // To just fix 20 elements per row
				{
					cout << endl;
				}
			}
		}
	cout << endl;
	cout << "\n" << "Done!" << endl;
	return;
}

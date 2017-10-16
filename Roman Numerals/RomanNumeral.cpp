/*
 * RomanNumeral.cpp
 *
 *  Created on: Sep 27, 2017
 *      Author: Manogna Sindhusha Mujje
 */
#include <iostream>
#include <string>
#include <cmath>
#include <ctype.h>
#include "RomanNumeral.h"

using namespace std;

//Default Consructor
RomanNumeral::RomanNumeral(): roman(""), decimal(0)
{
}

//Constructor with integer parameter
RomanNumeral::RomanNumeral(int n): decimal(n), roman()
{
	roman = to_roman(n);
}

//Constructor with string parameter
RomanNumeral::RomanNumeral(string s): roman(s), decimal()
{
	decimal = to_decimal(s);
}

//Setter functions to private member variables
void RomanNumeral::set_decimal(int decimalValue) { decimal = decimalValue; }
void RomanNumeral::set_roman(string romanValue) { roman = romanValue; }

//Getter functions to private member variables
int RomanNumeral::get_decimal() const { return decimal; }
string RomanNumeral::get_roman() const { return roman; }

//Overloaded + operator
string operator +(const RomanNumeral& rn1, const RomanNumeral& rn2)
{
   RomanNumeral rn;
	rn.set_decimal(rn1.decimal + rn2.decimal);
	rn.set_roman(rn.to_roman(rn.decimal));
	return (rn.roman);
}

//Overloaded - operator
string operator -(const RomanNumeral& rn1, const RomanNumeral& rn2)
{
   RomanNumeral rn;
	rn.set_decimal(abs(rn1.decimal - rn2.decimal));
	rn.set_roman(rn.to_roman(rn.decimal));
	return (rn.roman);
}

//Overloaded * operator
string operator *(const RomanNumeral& rn1, const RomanNumeral& rn2)
{
   RomanNumeral rn;
	rn.set_decimal(rn1.decimal * rn2.decimal);
	rn.set_roman(rn.to_roman(rn.decimal));
	return (rn.roman);
}

//Overloaded / operator
string operator /(const RomanNumeral& rn1, const RomanNumeral& rn2)
{
   RomanNumeral rn;
	rn.set_decimal(rn1.decimal / rn2.decimal);
	rn.set_roman(rn.to_roman(rn.decimal));
	return (rn.roman);
}

//Overloaded << operator
ostream& operator <<(ostream& outs, RomanNumeral& rn)
{
	outs << "[" << rn.decimal  << ":" << rn.roman << "]";
	return outs;
}

//Overloaded >> operator
istream& operator >>(istream& ins, RomanNumeral& rn)
{
	string r;
	ins >> r;

	if(isalpha(r[0]))
	{
		rn.roman = r;
		rn.decimal = rn.to_decimal(r);
	}
	else if (isdigit(r[0]))
	{
		rn.decimal = stoi(r);
		rn.roman = rn.to_roman(rn.decimal);
	}
	return ins;
}

//Overloaded == operator
bool operator ==(const RomanNumeral& rn1, const RomanNumeral& rn2)
{
	return (rn1.get_decimal() == rn2.get_decimal());
}

//Overloaded != operator
bool operator !=(const RomanNumeral& rn1, const RomanNumeral& rn2)
{
	return (!(rn1.get_decimal() == rn2.get_decimal()));
}

//Definition of private member function to convert Integers into Roman Numbers
string RomanNumeral:: to_roman(int decimal)
{
	string s = "IVXLCDM", romanRange, romanDigit, romanValue = "";
	int digit, count;
	string number = to_string(decimal);
	int len = number.length();
	count = len-1;
	for (int d = 0; d < len; d++)
	{
		digit = number[d] - '0';
		if (digit == 0)
		{
			romanDigit = romanDigit + "";
			count--;
			continue;
		}
		romanRange = s.substr(count*2, 3);
		if(digit == 5)
		{
			romanDigit = romanRange[1];
		}
		else if(digit  > 5)
		{
			if (digit == 9)
			{
				romanDigit = romanRange[0];
				romanDigit+= romanRange[2];
			}
			else if(digit < 9)
			{
				romanDigit =  romanRange[1];
				int i = 0;
				while(i < digit - 5)
				{
					romanDigit =  romanDigit + romanRange[0];
					i++;
				}
			}
		}
		else if (digit < 5)
		{
			if (digit == 4)
			{
				romanDigit = romanRange[0];
				romanDigit += romanRange[1];
			}
			else if(digit < 4)
			{
				romanDigit = romanRange[0];
				int i = 0;
				while(i < digit - 1)
				{
					romanDigit =  romanDigit + romanRange[0];
					i++;
				}
			}
		}
		romanValue = romanValue + romanDigit;
		count--;
	}
	return romanValue;
}

//Definition of private member function to convert Roman Numbers into Integers
int RomanNumeral::to_decimal(string roman)
{
	int decimalValue = 0, digitLength;
	int len = roman.length(), temp = 0;
	int array[len];
	int M = 1000, D = 500, C = 100, L = 50, X = 10, V = 5, I = 1;
	for (int i = 0; i < len; i++)
	{
		switch(roman[i])
		{
			case 'M':
				array[i] = 1000;
				break;
			case 'D':
				array[i] = 500;
				break;
			case 'C':
				array[i] = 100;
				break;
			case 'L':
				array[i] = 50;
				break;
			case 'X':
				array[i] = 10;
				break;
			case 'V':
				array[i] = 5;
				break;
			case 'I':
				array[i] = 1;
				break;
		}
	}

	for (int i = 0; i < len; i++)
	{
		if (array[i] >= array[i+1] || i == len-1)
		{
			decimalValue += array[i];
		}
		else if (array[i] < array[i+1])
		{
			decimalValue -= array[i];
		}
	}
	return decimalValue;
}

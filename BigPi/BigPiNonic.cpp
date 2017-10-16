/*
 * BigPiNonic.cpp
 *
 *  Created on: Sep 21, 2017
 *      Author: Manogna Sindhusha Mujje
 */

#include <iostream>
#include <iomanip>
#include <mpir.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

const int MAX_ITERATIONS = 100;
const int PLACES         = 1000;        // desired decimal places
const int PRECISION      = PLACES + 1;  // +1 for the digit 3 before the decimal

const int BASE       = 10;  // base 10 numbers
const int BIT_COUNT  = 8;   // bits per machine word

const int BLOCK_SIZE = 10;                // print digits in blocks
const int LINE_SIZE  = 100;               // digits to print per line
const int LINE_COUNT = PLACES/LINE_SIZE;  // lines to print
const int GROUP_SIZE = 5;                 // line grouping size

/**
 * Compute the cube root of a positive integer.
 * @param x where to store the result.
 * @param a the number whose cube root to compute.
 */
void cube_root(mpf_t& x, const mpf_t a);
void cube_power(mpf_t& i3, const mpf_t& i);
void print(const mpf_t& pi);


/**
 * To compue the value of pi using Nonic Theorem
 */
int main()
{
    mpf_set_default_prec(BIT_COUNT * PRECISION);  // precision in bits

    int n = 0;
	int expo;

	//To declare Multiple-precision constants.
    mpf_t one;  mpf_init(one);
    mpf_t two;  mpf_init(two);
    	mpf_t three; mpf_init(three);
    	mpf_t nine; mpf_init(nine);
    	mpf_t twenty_seven; mpf_init(twenty_seven);


    	//Assigning constants to Multiple-precision constants.
    	mpf_set_str(one,  "1", BASE);
    mpf_set_str(three,  "3", BASE);
    	mpf_set_str(two,  "2", BASE);
    	mpf_set_str(nine,  "9", BASE);
    	mpf_set_str(twenty_seven,  "27", BASE);

    	//Initial variables

    	mpf_t a0 ;  mpf_init(a0);
    	mpf_t r0 ;  mpf_init(r0);
    	mpf_t s0 ;  mpf_init(s0);

     // Multiple-precision variables.

    	mpf_t tn ;  mpf_init(tn);
    	mpf_t un ;  mpf_init(un);
    	mpf_t vn ;  mpf_init(vn);
    	mpf_t wn ;  mpf_init(wn);
    	mpf_t an ;  mpf_init(an);
    	mpf_t sn ;  mpf_init(sn);
    	mpf_t rn ;  mpf_init(rn);
    	mpf_t a;  mpf_init(a);

    	//Temporary variables

    	mpf_t sqrt3 ;  mpf_init(sqrt3);
 	mpf_t cuber0 ;  mpf_init(cuber0);
    	mpf_t numr0 ;  mpf_init(numr0);
    	mpf_t subs0 ;  mpf_init(subs0);
    	mpf_t term1 ;  mpf_init(term1);
    	mpf_t term2 ;  mpf_init(term2);
    	mpf_t term3 ;  mpf_init(term3);
    	mpf_t rnsqr ;  mpf_init(rnsqr);
	mpf_t tmpsum1 ;  mpf_init(tmpsum1);
	mpf_t tmpsum2 ;  mpf_init(tmpsum2);
	mpf_t ninern ;  mpf_init(ninern);
	mpf_t prdun ;  mpf_init(prdun);
	mpf_t snterm; mpf_init(snterm);

    	//Compute a0 = 1/3
    	mpf_div(a0, one, three);


    	//Compute r0 = (3^(1/2) - 1)/2
    	mpf_sqrt(sqrt3, three);
    	mpf_sub(numr0,sqrt3 , one);
    	mpf_div(r0, numr0, two);

    	//Compute s0 = (1-r0^3)^1/3
    	cube_power(cuber0, r0);
    	mpf_sub(subs0, one , cuber0);
    	cube_root(s0, subs0);

  // Setting up the initial values to  an,rn,sn
    	mpf_set(an, a0);
	mpf_set(rn, r0);
	mpf_set(sn, s0);

	//Loop MAX_ITERATIONS times.
    	do
    	{
    		mpf_set(a, an);

    		//Compute tn = 1+2rn
    		mpf_mul(tn, rn,two);
    		mpf_add(tn, one, tn);

    		//Compute un = (9rn(1+rn+rn^2))^1/3
    		mpf_pow_ui(rnsqr, rn, 2);
    		mpf_add(tmpsum1, rnsqr, rn);
    		mpf_add(tmpsum2, one, tmpsum1);
    		mpf_mul(ninern, nine, rn);
    		mpf_mul(prdun, ninern, tmpsum2);
    		cube_root(un, prdun);

    		//Compute vn = tn^2 + tnun + un^2
    		mpf_pow_ui(vn, tn, 2);
    		mpf_mul(term2, tn, un);
    		mpf_pow_ui(term3, un, 2);
    		mpf_add(vn, term2, vn);
    		mpf_add(vn, term3, vn);


    		//Compute wn = 27(1+sn+sn^2)/vn
    		mpf_pow_ui(wn, sn, 2);
    		mpf_add(wn, wn, sn);
    		mpf_add(wn, wn, one);
    		mpf_mul(wn, wn, twenty_seven);
    		mpf_div(wn, wn, vn);


    		//Compute an = wnan + 3^(2n-1)(1-wn)
    		mpf_sub(term2, one, wn);
    		mpf_mul(term1, wn, an);
    		if(n==0) // As (2n-1) is signed int for n=0
		{
			mpf_div(term3, one, three);
		}
		else
		{
			expo = (2*n)-1;
			mpf_pow_ui(term3, three, expo);
		}
    		mpf_mul(term2, term2, term3);
    		mpf_add(an, term1, term2);


    		//Compute sn = (1-rn)^3/(tn+2un)vn
    		mpf_sub(term1, one, rn);
    		mpf_pow_ui(term1, term1, 3);
    		mpf_mul(term2, two, un);
    		mpf_add(term2, term2, tn);
    		mpf_mul(term2, term2, vn);
    		mpf_div(sn, term1, term2);

    		//Compute rn = (1-sn^3)^1/3
    		cube_power(snterm, sn);
    	    		mpf_sub(snterm, one, snterm);
    	    		cube_root(rn, snterm);

    		n++;
    	} while((n== 1 || mpf_eq(a,an, PRECISION) == 0 ) && (n < MAX_ITERATIONS));

    	mpf_t pi;
	mpf_init(pi);

	// Compute pi = 1/an
	mpf_div(pi, one, an);

	print(pi);

    	return 0;
}

// Function to power to 3
void cube_power(mpf_t& i3, const mpf_t& i)
{
    mpf_t i2;
    mpf_init(i2);

    mpf_mul(i2, i, i);
    mpf_mul(i3, i, i2);
}

// Function to determine cube root

void cube_root(mpf_t& x, const mpf_t a)
{
	//Declaring multi-precision variables
	mpf_t xn; mpf_init(xn);
	mpf_t num; mpf_init(num);
	mpf_t den; mpf_init(den);
	mpf_t res; mpf_init(res);
	mpf_t x3; mpf_init(x3);
	mpf_t two; mpf_init(two);
	mpf_t three; mpf_init(three);
	mpf_t twoa; mpf_init(twoa);
	mpf_t twox3; mpf_init(twox3);
	mpf_t al3; mpf_init(al3);

	//Declare multi-precision constants
	mpf_set_str(three,  "3", BASE);
	mpf_set_str(two,  "2", BASE);

	//Initializing values
	mpf_div(al3, a, three);

	mpf_set(xn, al3);

	// Implementing Halley's Theorem
	do
	{
		mpf_set(x, xn);
		mpf_mul(twoa, two, a);
		cube_power(x3, x);
		mpf_mul(twox3, two, x3);
		mpf_add(num, x3, twoa);
		mpf_add(den, twox3, a);
		mpf_div(res, num, den);
		mpf_mul (xn, x,res);

	}while(mpf_cmp(x,xn));

}
void print(const mpf_t& pi)
{
    mp_exp_t exp;  // exponent (not used)

    // Convert the multiple-precision number x to a C string.
    char *str = NULL;
	char *s = mpf_get_str(str, &exp, BASE, PRECISION, pi);
	char *p = s+1;  // skip the 3 before the decimal point

	cout << endl;
	cout << "3.";

	char block[BLOCK_SIZE + 1];  // 1 extra for the ending \0

	// Loop for each line.
	for (int i = 1; i <= LINE_COUNT; i++)
	{
		// Loop to print blocks of digits in each line.
		for (int j = 0; j < LINE_SIZE; j += BLOCK_SIZE)
		{
			strncpy(block, p+j, BLOCK_SIZE);
			block[BLOCK_SIZE] = '\0';
			cout << block << " ";
		}

		cout << endl << "  ";

		// Print a blank line for grouping.
		if (i%GROUP_SIZE == 0) cout << endl << "  ";

		p += LINE_SIZE;
	}

	free(s);
}




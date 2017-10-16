/*
 * RomanNumeral.h
 *
 *  Created on: Sep 27, 2017
 *      Author: Manogna Sindhusha Mujje
 */

#ifndef ROMANNUMERAL_H_
#define ROMANNUMERAL_H_
#include <string>

using namespace std;

class RomanNumeral
{
public:
    /**
     * Default constructor.
     */
    RomanNumeral();

    // Constructors
    RomanNumeral(int n);
    RomanNumeral(string s);

    //Setter functions
    void set_decimal(int n);
	void set_roman(string s);

	//Getter functions
    int get_decimal() const;
    string get_roman() const;

    //Declaration of friend functions
    friend string operator +(const RomanNumeral& rn1, const RomanNumeral& rn2);
    friend string operator -(const RomanNumeral& rn1, const RomanNumeral& rn2);
    friend string operator *(const RomanNumeral& rn1, const RomanNumeral& rn2);
    friend string operator /(const RomanNumeral& rn1, const RomanNumeral& rn2);
    friend bool operator ==(const RomanNumeral& rn1, const RomanNumeral& rn2);
    friend bool operator !=(const RomanNumeral& rn1, const RomanNumeral& rn2);
    friend ostream& operator <<(ostream& outs, RomanNumeral& rn);
    friend istream& operator >>(istream& ins, RomanNumeral& rn);

private:

    //Member Variables
    string roman;
    int decimal;

    //Member functions
    string to_roman(int decimal);
    int to_decimal(string roman);
};
#endif /* ROMANNUMERAL_H_ */

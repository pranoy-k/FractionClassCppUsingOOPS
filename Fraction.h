/*

    File: Fraction.h

    Author: Pranoy K

    Date: 02/02/2018

    Description: Defining a Fraction Class 

*/

/**

INcluding the header files 

**/

#ifndef _FRACTION_H_
#define _FRACTION_H_

/*--------------*/
/* DEFINES */
/*--------------*/

/* -- (none) -- */

/*--------------*/
/* INCLUDES */
/*--------------*/

#include <iostream>
#include <cmath>
#include <string>
#include <exception>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <utility>
#include <limits.h>


using namespace std;

extern unordered_map<string,int> operator_map;
extern unordered_map<int, string> number_map;
/*
API for Fraction Class
Operator overloading supported for input/output
and various binary and arithmetic operations
*/
class Fraction
{

private: 
   int numerator;
   int denominator;
   int gcd(int, int);

public:
   Fraction();
   Fraction(int num, int den);
   Fraction operator+ (Fraction );
   Fraction operator- (Fraction );
   Fraction operator* (Fraction );
   Fraction operator/ (Fraction );
   bool operator== (Fraction );
   bool operator!= (Fraction );
   bool operator< (Fraction );
   bool operator> (Fraction );
   bool operator<= (Fraction );
   bool operator>= (Fraction );
   string returnFractionAsString ();
   bool validFractionInput(string);
   void convertStringToFraction(string);
   

};

ostream& operator<<(ostream& os, Fraction& m);
istream& operator>>(istream& is, Fraction& m);

#endif
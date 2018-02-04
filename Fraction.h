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
pair<int,int> receiveInput(int num);

class Fraction
{

public: 
   int numerator;
   int denominator;
   int gcd(int, int);


   Fraction();
   Fraction(int num, int den);
   Fraction operator+ (Fraction b);
   Fraction operator- (Fraction b);
   Fraction operator* (Fraction b);
   Fraction operator/ (Fraction b);
   bool operator== (Fraction b);
   bool operator!= (Fraction b);
   bool operator< (Fraction b);
   bool operator> (Fraction b);
   bool operator<= (Fraction b);
   bool operator>= (Fraction b);
   
   friend ostream& operator<<(ostream& os, const Fraction& m);

};

#endif
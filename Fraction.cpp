/*
 File: Fraction.cpp
 
 Author: Pranoy Kovuri
 Date  : 2/3/2018
 
 */
#include "Fraction.h"

unordered_map< string, int> operator_map
                      {{"+",1},{"-",2}, 
                      {"*",3},{"/",4}, 
                      {"==",5},{"!=",6}, 
                      {">",7},{"<",8}, 
                      {">=",9},{"<=",10}
                       } ;

pair<int,int> receiveInput(int n)
{
      int num, den;
      cout << endl << "Enter "<< n <<" number";
      cout << endl << "Enter the Numerator:: ";
      cin >> num;
      while (!cin.good())
      {
         cin.clear();
         cin.ignore(INT_MAX, '\n');
         cout << endl << "Enter a valid Integer.. Try Again";
         cout << endl << "Enter the Numerator:: ";
         cin >> num;
      }
      cout << "Enter the Denominator:: ";
      cin >> den;
      while (!cin.good())
      {
         cin.clear();
         cin.ignore(INT_MAX, '\n');
         cout << endl << "Enter a valid Integer.. Try Again";
         cout << endl << "Enter the Denominator:: ";
         cin >> den;
      }

      return make_pair(num,den);
}


int Fraction::gcd(int a , int b)
{
   if (a == 0 || b == 0)
      return 0;
   if (a == b)
      return a;
   if (a > b)
      return gcd(a-b, b);
   return gcd(a, b-a);
}

Fraction::Fraction()
{
   this->numerator = 0;
   this->denominator = 1;
}

Fraction::Fraction(int num, int den) 
{
   if(den == 0)
   {
      throw runtime_error("\nWrong Input!!!!!!!!!\n\nTry Again\n");
   }
   if(num != 0)
   {
      this->numerator = num/gcd(abs(num),abs(den));
      this->denominator = den/gcd(abs(num),abs(den));
      if(den < 0)
      {
         this->numerator*=-1;
         this->denominator*=-1;
      }
   }
    else
   {
      this->numerator = 0;
      this->denominator = 1;
   }
}

Fraction Fraction::operator+ (Fraction b)
{

   int numerator = this->numerator*b.denominator + b.numerator*this->denominator;
   int denominator = this->denominator*b.denominator;
   Fraction result(numerator, denominator);

   return result;
}

Fraction Fraction::operator- (Fraction b)
{

   int numerator = this->numerator*b.denominator - b.numerator*this->denominator;
   int denominator = this->denominator*b.denominator;
   Fraction result(numerator, denominator);
   
   return result;
}
Fraction Fraction::operator* (Fraction b)
{

   int numerator = this->numerator*b.numerator;
   int denominator = this->denominator*b.denominator;
   Fraction result(numerator, denominator);
   
   return result;
}
Fraction Fraction::operator/ (Fraction b)
{

   int numerator = this->numerator*b.denominator;
   int denominator = this->denominator*b.numerator;
   Fraction result(numerator, denominator);
   
   return result;
}

bool Fraction::operator== (Fraction b)
{
   return ((this->numerator == b.numerator) && (this->denominator == b.denominator));
}

bool Fraction::operator!= (Fraction b)
{
   return ((this->numerator != b.numerator) || (this->denominator != b.denominator));
}

bool Fraction::operator< (Fraction b)
{
   float result = (this->numerator*b.denominator) - (this->denominator*b.numerator);
   return result < 0;
}

bool Fraction::operator> (Fraction b)
{
   float result = (this->numerator*b.denominator) - (this->denominator*b.numerator);
   return result > 0;
}

bool Fraction::operator<= (Fraction b)
{
   float result = (this->numerator*b.denominator) - (this->denominator*b.numerator);
   return result <= 0;
}

bool Fraction::operator>= (Fraction b)
{
   float result = (this->numerator*b.denominator) - (this->denominator*b.numerator);
   return result >= 0;
}

ostream& operator<<(ostream& os, const Fraction& m) {

   os << m.numerator << "/" << m.denominator ;
   return os;
}


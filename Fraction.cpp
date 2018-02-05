/*
 File: Fraction.cpp
 
 Author: Pranoy Kovuri
 Date  : 2/3/2018
 
 */
#include "Fraction.h"

/*
Mapping for different Operands to number for switch case
*/
unordered_map< string, int> operator_map
                      {{"+",1},{"-",2}, 
                      {"*",3},{"/",4}, 
                      {"==",5},{"!=",6}, 
                      {">",7},{"<",8}, 
                      {">=",9},{"<=",10}
                       } ;
/*
Mapping from number to Strings
*/
unordered_map<int, string> number_map
                      {{1,"First"},
                       {2,"Second"}
                      } ;

/*
Private function for calculating GCD for expressing 
numerator/denominator in simplest form
*/
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

/*
Constructor with default values
*/
Fraction::Fraction()
{
   this->numerator = 0;
   this->denominator = 1;
}
/*Constructor with arguments*/
Fraction::Fraction(int num, int den) 
{

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

/*Operator overloading for adding two fractions*/
Fraction Fraction::operator+ (Fraction b)
{

   int numerator = this->numerator*b.denominator + b.numerator*this->denominator;
   int denominator = this->denominator*b.denominator;
   Fraction result(numerator, denominator);

   return result;
}

/*Operator overloading for subracting two fractions*/
Fraction Fraction::operator- (Fraction b)
{

   int numerator = this->numerator*b.denominator - b.numerator*this->denominator;
   int denominator = this->denominator*b.denominator;
   Fraction result(numerator, denominator);
   
   return result;
}

/*Operator overloading for multiplying two fractions*/
Fraction Fraction::operator* (Fraction b)
{

   int numerator = this->numerator*b.numerator;
   int denominator = this->denominator*b.denominator;
   Fraction result(numerator, denominator);
   
   return result;
}

/*Operator overloading for dividing two fractions*/
Fraction Fraction::operator/ (Fraction b)
{

   int numerator = this->numerator*b.denominator;
   int denominator = this->denominator*b.numerator;
   Fraction result(numerator, denominator);
   
   return result;
}

/*Operator overloading for comparing two fractions*/
bool Fraction::operator== (Fraction b)
{
   return ((this->numerator == b.numerator) && (this->denominator == b.denominator));
}

/*Operator overloading for comparing two fractions*/
bool Fraction::operator!= (Fraction b)
{
   return ((this->numerator != b.numerator) || (this->denominator != b.denominator));
}

/*Operator overloading for comparing two fractions*/
bool Fraction::operator< (Fraction b)
{
   float result = (this->numerator*b.denominator) - (this->denominator*b.numerator);
   return result < 0;
}

/*Operator overloading for comparing two fractions*/
bool Fraction::operator> (Fraction b)
{
   float result = (this->numerator*b.denominator) - (this->denominator*b.numerator);
   return result > 0;
}

/*Operator overloading for comparing two fractions*/
bool Fraction::operator<= (Fraction b)
{
   float result = (this->numerator*b.denominator) - (this->denominator*b.numerator);
   return result <= 0;
}

/*Operator overloading for comparing two fractions*/
bool Fraction::operator>= (Fraction b)
{
   float result = (this->numerator*b.denominator) - (this->denominator*b.numerator);
   return result >= 0;
}

/*Function for displaying fraction as a string*/
string Fraction::returnFractionAsString ()
{
   string temp = to_string(this->numerator) + "/" + to_string(this->denominator);
   return temp;
}

/*Function for testing valid fraction input*/
bool Fraction::validFractionInput(string str)
{
   size_t pos = str.find("/");
   if (pos==string::npos)
      return false;

   string first = str.substr(0, pos);
   string second = str.substr(pos + 1);

    for(int i = 0; i < first.size(); i++)
    {
      if(!isdigit(first[i]) && first[i] != '-')
         return false;
    }
    for(int i = 0; i < second.size(); i++)
    {
      if(!isdigit(second[i]) && second[i] != '-')
         return false;
    }
    return true;
}

/*Function for converting String To Fraction*/
void Fraction::convertStringToFraction(string str)
{
   size_t pos = str.find("/");

   int num = atoi(str.substr(0, pos).c_str());
   int den =  atoi(str.substr(pos + 1).c_str());

   if(den == 0)
   
   {
      throw runtime_error("Enter Valid Fraction!\nPlease enter a fraction of type p/q, where p and q are integers\nKeep in mind denominator cannot be zero.");
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

   return;
}

/*Operator overloading for Outputing fraction*/
ostream& operator<<(ostream& os, Fraction& m) 
{
   os << m.returnFractionAsString() ;
   return os;
}

/*Operator overloading for Inputing fraction*/
istream& operator>>(istream& is, Fraction& m)
{
   string inp;
   is >> inp;

   if(!m.validFractionInput(inp))
   
   {
      throw runtime_error("\nEnter Valid Fraction!\nPlease enter a fraction of type p/q, where p and q are integers\nKeep in mind denominator cannot be zero.");
   }

   m.convertStringToFraction(inp);

   return is;

}


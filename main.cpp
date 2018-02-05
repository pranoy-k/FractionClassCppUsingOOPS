#include <iostream>
#include "Fraction.h"


using namespace std;

int main()
{

   bool continueWithAnswer = false;
   Fraction a, b, c;
   bool t;
   string op;
   string boolS;
   char contin;
   bool receiveInput = true;

   while(1) 
   {
      cout<<"\n-------------------------------------------------------------\n";
      cout << endl << "What fractions do you want to operate on?" << endl;

      if(!continueWithAnswer)
      {
         
         cout << endl << "Enter "<< number_map[1] <<" number";
         receiveInput = true;
         while(receiveInput)
         {
            cout << endl << "Enter the Number in the form a/b ::  ";
            receiveInput = false;
            try
            {
               cin >> a;
            }
            catch (runtime_error e)
            {
               cout << e.what() << endl;
               receiveInput = true;
            }
         }
      }
      else
         a = c;
      continueWithAnswer = false;

      cout << "The First Fraction is a/b : " << a << endl;
      receiveInput = true;

      cout << endl << "Enter "<< number_map[2] <<" number";
      receiveInput = true;
      while(receiveInput)
      {
         cout << endl << "Enter the Number in the form a/b ::  ";
         receiveInput = false;
         try
         {
            cin >> b;
         }
         catch (runtime_error e)
         {
            cout << e.what() << endl;
            receiveInput = true;
         }
      }

      cout << "The Second Fraction is b : " << b << endl;

      
      cout << endl << "Operation to perform include (+ - * / == != > < >= <=) \nSelect one of these :: ";
      cin >> op;

      int oper = operator_map[op];

      switch (oper) {
         case 1:
            c = a + b;
            break;
         case 2:
            c = a - b;
            break;
         case 3:
            c = a * b;
            break;
         case 4:
            c = a / b;
            break;
         case 5:
            t = a == b;
            break;
         case 6:
            t = a != b;
            break;
         case 7:
            t = a > b;
            break;
         case 8:
            t = a < b;
            break;
         case 9:
            t = a >= b;
            break;
         case 10:
            t = a <= b;
            break;

          default:
              cout << "Unknown operation!" << endl;
            }

      if(oper <= 4 && oper >=1)
         cout << endl << a << " " << op << " " << b << " = " << c << endl;
      boolS = t?"True":"False";
      if(oper >= 5 && oper <= 10)
         cout << endl << a << " " << op << " " << b << " is " << boolS << endl;
      
      cout << endl << "Do you wish to continue? (Y or N):: " ;
      
      cin >> contin;
      if(contin == 'Y' || contin == 'y')
      {
         if(oper <= 4 && oper >=1 )
         {
            cout << endl << "Do you wish to continue operating with the Answer? (Y or N):: ";
            cin>>contin;
            if(contin == 'Y' || contin == 'y')
               continueWithAnswer = true;
            else if (contin == 'N' || contin == 'n')
               continueWithAnswer = false;
            else
            {
               continueWithAnswer = false;
               cout<< endl << "Invalid input, continuing with new input" << endl;
            }
         }
      }
      else if (contin == 'N' || contin == 'n')
         break;
      else
      {
         cout<< endl << "Invalid input, continuing anyway" << endl;
         continueWithAnswer = false;
      }
   
   }
   
   return 0;

}


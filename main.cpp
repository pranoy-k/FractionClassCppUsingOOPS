#include <iostream>
#include "Fraction.h"


using namespace std;

int main()
{
   while(1) 
   {
      cout<<"\n-------------------------------------------------------------\n";
      cout << endl << "What fractions do you want to operate on?" << endl;
      try
      {

      pair<int,int> firstNumber = receiveInput(1);


      Fraction a(firstNumber.first, firstNumber.second);
      cout << "The Fraction you entered is a : " << a << endl;

      pair<int,int> secondNumber = receiveInput(2);

      Fraction b(secondNumber.first, secondNumber.second);
      cout << "The Fraction you entered is b : " << b << endl;

      Fraction c;
      bool t;
      
      cout << endl << "Operation to perform include (+ - * / == != > < >= <=) \nSelect one of these :: ";
      
      string op;
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
      string boolS = t?"True":"False";
      if(oper >= 5 && oper <= 10)
         cout << endl << a << " " << op << " " << b << " is " << boolS << endl;
      
      cout << endl << "Do you wish to continue (Y or N):: " ;
      char contin;
      cin >> contin;
      if(contin == 'Y' || contin == 'y')
         continue;
      else if (contin == 'N' || contin == 'n')
         break;
      else
         cout<< endl << "Invalid input, continuing anyway" << endl;
   }
   catch (runtime_error e) {
        cout << e.what() << endl;
    }
   }
   
   return 0;

}
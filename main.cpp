#include <iostream>
#include "Fraction.h"


using namespace std;

pair<int,int> receiveInput(int num);

int main()
{

   pair<int,int> firstNumber, secondNumber;
   bool continueWithAnswer = false;
   Fraction a, b, c;
   bool t;
   string op;
   string boolS;
   char contin;

   while(1) 
   {
      cout<<"\n-------------------------------------------------------------\n";
      cout << endl << "What fractions do you want to operate on?" << endl;
      try
      {

         if(!continueWithAnswer)
            firstNumber = receiveInput(1);
         else
            firstNumber = c.getFraction();

         a = Fraction (firstNumber.first, firstNumber.second);
         cout << "The First Fraction is a : " << a << endl;

         secondNumber = receiveInput(2);

         b = Fraction (secondNumber.first, secondNumber.second);
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
                  cout << endl << "Do you wish to continue with the Answer? (Y or N):: ";
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
   catch (runtime_error e) {
        cout << e.what() << endl;
    }
   }
   
   return 0;

}



pair<int,int> receiveInput(int n)
{
   int num, den;
   cout << endl << "Enter "<< number_map[n] <<" number";
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
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

void input(int &creditCardBalance, int &interestRate, int &minimumPaymentPercentage) {
   //int creditCardBalance, interestRate, minimumPaymentPercentage;
   ifstream myfile;
   myfile.open("lab6.txt");
   myfile >> creditCardBalance;
   myfile >> interestRate;
   myfile >> minimumPaymentPercentage;
}

void calculate(int creditCardBalance2, int interestRate2, int minimumPaymentPercentage2) {
   double minimumPayment = creditCardBalance2 * minimumPaymentPercentage2;
   double interestPaid = creditCardBalance2 * 30 * interestRate2 / 360;
   while (creditCardBalance2 != 0) {
      //Have to figure out how to loop this and display them neatly
      creditCardBalance2 - minimumPayment;
      minimumPayment = (creditCardBalance2 - minimumPayment);
      interestPaid = (creditCardBalance2 - minimumPayment) * 30 * interestRate2 / 360;

   }
   if (minimumPayment < 15)
      minimumPayment = 15;

}

void output1() {}
void output2() {}
void output3() {}


int main() {
   int creditCardBalance1, interestRate1, minimumPaymentPercentage1;
   input(creditCardBalance1, interestRate1, minimumPaymentPercentage1);
   calculate(creditCardBalance1, interestRate1, minimumPaymentPercentage1);

   cout << creditCardBalance1 << endl;
   cout << interestRate1 << endl;
   cout << minimumPaymentPercentage1 << endl;
   return 0;
}


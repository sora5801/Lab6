#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

void input(double &creditCardBalance, double &interestRate, double &minimumPaymentPercentage) {
   //int creditCardBalance, interestRate, minimumPaymentPercentage;
   ifstream myfile;
   myfile.open("lab6.txt");
   myfile >> creditCardBalance;
   myfile >> interestRate;
   myfile >> minimumPaymentPercentage;

}

//void calculate(int creditCardBalance2, int interestRate2, int minimumPaymentPercentage2) {
// while (creditCardBalance2 != 0) {
//Have to figure out how to loop this and display them neatly
//  double minimumPayment = creditCardBalance2 * minimumPaymentPercentage2;
// double interestPaid = creditCardBalance2 * 30 * interestRate2 / 360;
//  creditCardBalance2 = creditCardBalance2 - minimumPayment;
//interestPaid = (creditCardBalance2 - minimumPayment) * 30 * interestRate2 / 360;
// if (minimumPayment < 15)
//minimumPayment = 15;
// }
//  cout << creditCardBalance2 <<endl;

//}

void output1() {
   int month;
   for (month = 1; month <= 60; month++) {
      cout << month << "  " << endl;
   }
}
//void output2() {}
//void output3() {}


int main() {
   double creditCardBalance1;
   double interestRate1;
   double minimumPaymentPercentage1;
   input(creditCardBalance1, interestRate1, minimumPaymentPercentage1);
   //calculate(creditCardBalance1, interestRate1, minimumPaymentPercentage1);
   //cout << creditCardBalance1 <<endl;

   while (creditCardBalance1 > 0) {
      //Have to figure out how to loop this and display them neatly

      double minimumPayment = creditCardBalance1 * (minimumPaymentPercentage1 * 0.01);
      double interestPaid = (creditCardBalance1 * interestRate1 * 0.01) / 12;
      double principalPaid = minimumPayment - interestPaid;


      if (minimumPayment < 15.0) {
         minimumPayment = 15.0;
         principalPaid = minimumPayment - interestPaid;

      }

      if (creditCardBalance1 < minimumPayment)
         creditCardBalance1 = principalPaid;

      creditCardBalance1 = creditCardBalance1 - principalPaid;

      cout << setprecision(2) << fixed;
      cout << creditCardBalance1 << " " << interestPaid << "  " << minimumPayment << endl;


   }



   return 0;
}

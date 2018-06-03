#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

void input(double &creditCardBalance, int &interestRate, int &minimumPaymentPercentage) {

   ifstream myfile;
   myfile.open("lab6.txt");
   myfile >> creditCardBalance;
   myfile >> interestRate;
   myfile >> minimumPaymentPercentage;

}



void output1(int a, double b, double c, double d, double e) {
   ofstream thisfile;
   thisfile.open("OutputData.txt");
      thisfile << setprecision(2) << fixed;
      thisfile << a << "  " << b << "  " << c << "  " << d << "  " << e << endl;     
      
}

void calculate(double creditCardBalance2, int interestRate2, int minimumPaymentPercentage2) {

   int month = 0;
   double Sum = 0;
   
   while (creditCardBalance2 > 0) {
      

      double minimumPayment = creditCardBalance2 * ((minimumPaymentPercentage2 * 0.01) + 0.0008);
      double interestPaid = (creditCardBalance2 * (interestRate2 * 0.01)) / 12;
      double principalPaid = minimumPayment - interestPaid;
      Sum += interestPaid;


      if (minimumPayment < 15.0) {
         minimumPayment = 15.0;
         principalPaid = minimumPayment - interestPaid;

      }

      if (creditCardBalance2 < minimumPayment) {
         minimumPayment = creditCardBalance2 + interestPaid;
         creditCardBalance2 = principalPaid;
      }
      creditCardBalance2 = creditCardBalance2 - principalPaid;
      month++;

       
      output1(month, creditCardBalance2, interestPaid, minimumPayment, Sum);
       
       
   }
}

void output2(double creditCardBalance3, int interestRate3, int minimumPaymentPercentage3) {
   ofstream thisfile;
   thisfile.open("OutputData.txt");
   thisfile << "Balance Owing: $" << creditCardBalance3 << endl;
   thisfile << "APR as % " << interestRate3 << endl;
   thisfile << "Percent for minimum payment as %4" << endl;
   thisfile << "-----------------------------------------" << endl;
   thisfile << "Month   Balance   Interest this month   Minimum   Sum of interest paid" << endl;
}



int main() {
   double creditCardBalance1;
   int interestRate1;
   int minimumPaymentPercentage1;
   input(creditCardBalance1, interestRate1, minimumPaymentPercentage1);
   

   output2(creditCardBalance1, interestRate1, minimumPaymentPercentage1);
   calculate(creditCardBalance1, interestRate1, minimumPaymentPercentage1);
 
   return 0;
}

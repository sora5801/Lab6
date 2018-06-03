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



void output1(ofstream &thisfile, int a, double b, double c, double d, double e) {
   if (thisfile.is_open()) {
    thisfile << setprecision(2) << fixed;
    thisfile << a << "  " << b << "  " << c << "  " << d << "  " << e << "\n";
    cout << a << "  " << b << "  " << c << "  " << d << "  " << e << "\n";
}
}

void calculate(ofstream &thisfile, double creditCardBalance2, int interestRate2, int minimumPaymentPercentage2) {

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

    //  cout << month << creditCardBalance2 << interestPaid << minimumPayment << Sum << endl;
     output1(thisfile, month, creditCardBalance2, interestPaid, minimumPayment, Sum);
      //cout << month << creditCardBalance2 << interestPaid << minimumPayment << Sum << endl;
       

   }
}

void output2( ofstream &thisfile, double creditCardBalance3, int interestRate3, int minimumPaymentPercentage3) {
 //  ofstream thisfile;
 //  thisfile.open("OutputData.txt");
   if ( thisfile.is_open())
   {
      thisfile << "Balance Owing: $" << creditCardBalance3 << endl;
      thisfile << "APR as % " << interestRate3 << endl;
      thisfile << "Percent for minimum payment as %4" << endl;
      thisfile << "-----------------------------------------" << endl;
      thisfile << "Month   Balance   Interest this month   Minimum   Sum of interest paid" << endl;
   }
}



int main() {
   ofstream thisfile;
   thisfile.open("OutputData.txt");
   double creditCardBalance1;
   int interestRate1;
   int minimumPaymentPercentage1;
   input(creditCardBalance1, interestRate1, minimumPaymentPercentage1);
   

   output2(thisfile, creditCardBalance1, interestRate1, minimumPaymentPercentage1);
   
   calculate(thisfile, creditCardBalance1, interestRate1, minimumPaymentPercentage1);
   thisfile.close();
   return 0;
}

/*****************************************************************************/
//  Filename:      Lab6.cpp
//
//  Author:        Matthew Fu
//
//  Date:          2018.05.31
//
//
//  Description:  
//
//
/*****************************************************************************/
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

//I declare the function prototypes here.
void input(double &, int &, int &);
void output1(ofstream &, int, double, double, double, double);
void calculate(ofstream &, double, int, int);
void output2(ofstream &, double, int, int);
 
/*****************************************************************************/
//
// Function:   int main()
//
// Parameters:  None
//
// Outputs:    None
//
// Returns:    0
//
// Author:     Matthew Fu
//
// Date:       2018.31.05
//
//
// Description: 
// 
//
/*****************************************************************************/
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

/*****************************************************************************/
//
// Function:   
//
// Parameters:  None
//
// Outputs:    None
//
// Returns:    0
//
// Author:     Matthew Fu
//
// Date:       2018.31.05
//
//
// Description: 
//
/*****************************************************************************/
void input(double &creditCardBalance, int &interestRate, int &minimumPaymentPercentage) {

   ifstream myfile;
   myfile.open("lab6.txt");
   if (myfile.fail()) {
      cout << "Error opening file.\n";
   }
   else {
      myfile >> creditCardBalance;
      myfile >> interestRate;
      myfile >> minimumPaymentPercentage;
   }
}

/*****************************************************************************/
//
// Function:   
//
// Parameters:  None
//
// Outputs:    None
//
// Returns:    0
//
// Author:     Matthew Fu
//
// Date:       2018.31.05
//
//
// Description: 
// 
//
/*****************************************************************************/
void output1(ofstream &thisfile, int a, double b, double c, double d, double e) {
   int f = 13;
   if (a >= 10) {
      f = f - 1;
      thisfile << setprecision(2) << fixed;
      thisfile << a << setw(f) << b << setw(f + 1) << c << setw(f + 2) << d << setw(f + 3) << e << "\n";
   }
   else {
      thisfile << setprecision(2) << fixed;
      thisfile << a << setw(f) << b << setw(f) << c << setw(f + 1) << d << setw(f + 2) << e << "\n";
   }

}

/*****************************************************************************/
//
// Function:   void calculate(ofstream &thisfile, double creditCardBalance2, int interestRate2, int minimumPaymentPercentage2)
//
// Parameters:  None
//
// Outputs:    None
//
// Returns:    0
//
// Author:     Matthew Fu
//
// Date:       2018.31.05
//
//
// Description: 
// 
//
/*****************************************************************************/
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

      output1(thisfile, month, creditCardBalance2, interestPaid, minimumPayment, Sum);
      


   }
}


/*****************************************************************************/
//
// Function: void output2(ofstream &thisfile, double creditCardBalance3, int interestRate3, int minimumPaymentPercentage3)  
//
// Parameters:  None
//
// Outputs:    None
//
// Returns:    0
//
// Author:     Matthew Fu
//
// Date:       2018.31.05
//
//
// Description: 
// 
//
/*****************************************************************************/
void output2(ofstream &thisfile, double creditCardBalance3, int interestRate3, int minimumPaymentPercentage3) {
   if (thisfile.is_open())
   {
      thisfile << setw(27) << setprecision(2) << fixed << "Balance Owing: $" << creditCardBalance3 << endl;
      thisfile << setw(20) << "APR as % " << interestRate3 << endl;
      thisfile << setw(44) << "Percent for minimum payment as %4" << endl;
      thisfile << setw(48) << "-----------------------------------------" << endl;
      thisfile << "Month   Balance   Interest this    Minimum   Sum of interest " << endl;
      thisfile << setw(26) << "month" << setw(29) << "paid" << endl << endl;
   }
}

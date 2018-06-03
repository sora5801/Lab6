/*****************************************************************************/
//  Filename:      Lab5.cpp
//
//  Author:        Matthew Fu
//
//  Date:          2018.05.31
//
//
//  Description:  This program calculates the monthly cost of a house given
//                the selling price, annual rate of interest, and number of
//                years for the loan. After calculating them, it outputs the values
//                in a neat format in a text file. 
//
//
/*****************************************************************************/
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;


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
// Description: This is the main function. It declares variables for the selling price,
//              annual rate of interest, and the number of years for the loan. Then it
//              passes them into the input function and then passes them to the 
//              calculation function where the output function is.
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
// Description: This is the main function. It declares variables for the selling price,
//              annual rate of interest, and the number of years for the loan. Then it
//              passes them into the input function and then passes them to the 
//              calculation function where the output function is.
// 
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
// Description: This is the main function. It declares variables for the selling price,
//              annual rate of interest, and the number of years for the loan. Then it
//              passes them into the input function and then passes them to the 
//              calculation function where the output function is.
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
// Description: This is the main function. It declares variables for the selling price,
//              annual rate of interest, and the number of years for the loan. Then it
//              passes them into the input function and then passes them to the 
//              calculation function where the output function is.
// 
//
/*****************************************************************************/
void output2(ofstream &thisfile, double creditCardBalance3, int interestRate3, int minimumPaymentPercentage3) {
   //  ofstream thisfile;
   //  thisfile.open("OutputData.txt");
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

/*****************************************************************************/
//  Filename:      Lab6.cpp
//
//  Author:        Matthew Fu
//
//  Date:          2018.12.06
//
//
//  Description: This program takes the credit card balance, interest rate
//               on the credit card,
//
//
/*****************************************************************************/
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

//I declare the function prototypes here.
void input(ifstream &, double &, int &, int &);
void outputCalculation(ofstream &, int, double, double, double, double);
void calculate(ofstream &, double, int, int);
void outputHeader(ofstream &, double, int, int);

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
// Date:       2018.12.06
//
//
// Description:
//
//
/*****************************************************************************/
int main() {
   ifstream myfile;
   myfile.open("lab6.txt");

   double creditCardBalance;
   int interestRate;
   int minimumPaymentPercentage;

   input(myfile, creditCardBalance, interestRate, minimumPaymentPercentage);


   if (!myfile.fail()) {
      ofstream thisfile;
      thisfile.open("OutputData.txt");
      outputHeader(thisfile, creditCardBalance, interestRate, minimumPaymentPercentage);

      calculate(thisfile, creditCardBalance, interestRate, minimumPaymentPercentage);
      thisfile.close();
   }
   else {
      cout << "Error opening the file";
   }

   return 0;
}

/*****************************************************************************/
//
// Function: void input(ifstream &myfile, double &creditCardBalance, int &interestRate, int &minimumPaymentPercentage)
//
// Parameters:  None
//
// Outputs:    None
//
// Returns:    0
//
// Author:     Matthew Fu
//
// Date:       2018.12.06
//
//
// Description:
//
/*****************************************************************************/

void input(ifstream &myfile, double &creditCardBalance, int &interestRate, int &minimumPaymentPercentage) {
   myfile >> creditCardBalance;
   myfile >> interestRate;
   myfile >> minimumPaymentPercentage;
}

/*****************************************************************************/
//
// Function: void outputCalculation(ofstream &thisfile, int months, double creditCardBalance, double interestPaid, double minimumPayment, double sum)
//
// Parameters:  None
//
// Outputs:    None
//
// Returns:    0
//
// Author:     Matthew Fu
//
// Date:       2018.12.06
//
//
// Description:
//
//
/*****************************************************************************/
void outputCalculation(ofstream &thisfile, int months, double creditCardBalance, double interestPaid, double minimumPayment, double sum) {
   
   if (thisfile) {
      if (months >= 10) {
 
         thisfile << setprecision(2) << fixed;
         thisfile << months << setw(12) << creditCardBalance << setw(13) << interestPaid << setw(14) << minimumPayment << setw(15) << sum << "\n";
      }
      else {
         thisfile << setprecision(2) << fixed;
         thisfile << months << setw(13) << creditCardBalance << setw(13) << interestPaid << setw(14) << minimumPayment << setw(15) << sum << "\n";
      }
   }
}

/*****************************************************************************/
//
// Function:   void calculate(ofstream &thisfile, double creditCardBalance, int interestRate, int minimumPaymentPercentage)
//
// Parameters:  None
//
// Outputs:    None
//
// Returns:    0
//
// Author:     Matthew Fu
//
// Date:       2018.12.06
//
//
// Description:
//
//
/*****************************************************************************/
void calculate(ofstream &thisfile, double creditCardBalance, int interestRate, int minimumPaymentPercentage) {
   int month = 0;
   double sum = 0;

   while (creditCardBalance > 0) {
      double minimumPayment = creditCardBalance * ((minimumPaymentPercentage * 0.01) + 0.0008);
      double interestPaid = (creditCardBalance * (interestRate * 0.01)) / 12;
      double principalPaid = minimumPayment - interestPaid;
      sum += interestPaid;

      if (minimumPayment < 15.0) {
         minimumPayment = 15.0;
         principalPaid = minimumPayment - interestPaid;
      }

      if (creditCardBalance < minimumPayment) {
         minimumPayment = creditCardBalance + interestPaid;
         creditCardBalance = principalPaid;
      }
      creditCardBalance = creditCardBalance - principalPaid;
      month++;

      outputCalculation(thisfile, month, creditCardBalance, interestPaid, minimumPayment, sum);



   }
}


/*****************************************************************************/
//
// Function: void outputHeader(ofstream &thisfile, double creditCardBalance, int interestRate, int minimumPaymentPercentage)
//
// Parameters:  None
//
// Outputs:    None
//
// Returns:    0
//
// Author:     Matthew Fu
//
// Date:       2018.12.06
//
//
// Description: This function outputs the header of the payment schedule. It outputs
//              the starting credit card balance, interest rate, and the percent
//              of minimum payment in a neat, ordered manner.
//
//
/*****************************************************************************/
void outputHeader(ofstream &thisfile, double creditCardBalance, int interestRate, int minimumPaymentPercentage) {
   if (thisfile.is_open())
   {
      thisfile << setw(27) << setprecision(2) << fixed << "Balance Owing: $" << creditCardBalance << endl;
      thisfile << setw(20) << "APR as % " << interestRate << endl;
      thisfile << setw(44) << "Percent for minimum payment as % " << minimumPaymentPercentage << endl;
      thisfile << setw(48) << "-----------------------------------------" << endl;
      thisfile << "Month   Balance   Interest this    Minimum   Sum of interest " << endl;
      thisfile << setw(26) << "month" << setw(29) << "paid" << endl << endl;
   }
}

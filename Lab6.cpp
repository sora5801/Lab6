/*****************************************************************************/
//  Filename:      Lab6.cpp
//
//  Author:        Matthew Fu
//
//  Date:          2018.12.06
//
//
//  Description: This program takes the credit card balance, interest rate
//               on the credit card, and the minimum payment percentage from a text
//               file and output the number of months to pay off credit card balance,
//               the exact amount of minimum payment each month, the interest paid each
//               month, and the accumulated sum of the interest paid each month in a 
//               text file that is neatly formatted.
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
// Description: This function inputs a text file called "lab6.txt",
//               declares the variables for the credit card balance,interest rate, 
//              and the minimum payment percentage, pass their address
//              to the input function, then checks if lab6 exists or not. If it does,
//              then it calls the outputHeader function and the calculate function. If not.
//              then it cout error opening the file.
//
//
/*****************************************************************************/
int main() {
   ifstream myfile;
   myfile.open("lab6.txt");

   //The declared variables. I declared creditCardBalance as a double so as to not
   //lose data after the operations involved. Credit card balance is in dollars,
   //and interest rate and minimum payment percentage is in percentage.

   double creditCardBalance;
   int interestRate;
   int minimumPaymentPercentage;
   
   //I first call the input function after I declared my variables. This will store
   //the values from the text file into the variables if the text file exists.
   input(myfile, creditCardBalance, interestRate, minimumPaymentPercentage);

   //This is to test if the input text file exist or not. 
   if (!myfile.fail()) {
      ofstream thisfile;
      thisfile.open("OutputData.txt");

      //If the text file exists, then I first call the outputHeader function to display a
      //header into a text file.
      outputHeader(thisfile, creditCardBalance, interestRate, minimumPaymentPercentage);

      //Then I call the calculate function
      calculate(thisfile, creditCardBalance, interestRate, minimumPaymentPercentage);
      thisfile.close();
   }
   else {
      //If the lab6 file does not exist, an error will be displayed.
      cout << "Error opening the file" <<endl;
   }

   return 0;
}

/*****************************************************************************/
//
// Function: void input(ifstream &myfile, double &creditCardBalanceAddress, int &interestRateAddress, 
//                      int &minimumPaymentPercentageAddress)
//
// Parameters:  ifstream &myfile - the reference for the input stream.
//              double &creditCardBalanceAddress - the reference for the credit card balance
//              int &interestRateAddress - the reference for the interest rate
//              int &minimumPaymentPercentageAddress - the reference for the minimum payment percentage
//
// Outputs:    None
//
// Returns:    None
//
// Author:     Matthew Fu
//
// Date:       2018.12.06
//
//
// Description: This function passes the reference variables of in the input stream
//              myfile, the credit cart balance, interest rate, and the minimum payment 
//              percentage from int main, and stores the value from a text file into the respective
//              variable's address.
/*****************************************************************************/

void input(ifstream &myfile, double &creditCardBalanceAddress, int &interestRateAddress, 
   int &minimumPaymentPercentageAddress) {
   myfile >> creditCardBalanceAddress;
   myfile >> interestRateAddress;
   myfile >> minimumPaymentPercentageAddress;
}

/*****************************************************************************/
//
// Function: void outputCalculation(ofstream &thisfile, int monthsParameter, 
// double creditCardBalanceParameter, double interestPaidParameter, double minimumPaymentParameter, 
// double sumParameter)
//
// Parameters:  ofstream &thisfile - the output stream which I called thisfile.
//              int monthsParameter - the number of months to pay off the balance.
//              double creditCardBalanceParameter - the credit card balance at the end of each month
//              double interestPaidParameter - the interest paid each month. 
//              double minimumPaymentParameter - the minimum payment each month
//              double sumParameter - the sum of the interest paid.
//
// Outputs:    None
//
// Returns:    None
//
// Author:     Matthew Fu
//
// Date:       2018.12.06
//
//
// Description: This function outputs all the calculations of the months, credit card balance,
//              interest paid, minimum payment, and the total sum in a neat and ordered manner.
//              The various setwidths declared are to line the values up neatly.
//
//
/*****************************************************************************/
void outputCalculation(ofstream &thisfile, int monthsParameter, double creditCardBalanceParameter, 
   double interestPaidParameter, double minimumPaymentParameter, double sumParameter) {
   
      //I created a logic condition to check if the months is greater than 10, then the setwidth will be different.
      //This is so that the numbers will line up nicely. 
      if (monthsParameter >= 10) {
         thisfile << setprecision(2) << fixed;
         thisfile << monthsParameter << setw(12) << creditCardBalanceParameter << setw(13) << interestPaidParameter << 
         setw(14) << minimumPaymentParameter << setw(15) << sumParameter << "\n";
      }
      else {
         thisfile << setprecision(2) << fixed;
         thisfile << monthsParameter << setw(13) << creditCardBalanceParameter << setw(13) << interestPaidParameter << 
         setw(14) << minimumPaymentParameter << setw(15) << sumParameter << "\n";
      }
   
}

/*****************************************************************************/
//
// Function:   void calculate(ofstream &thisfile, double creditCardBalancePassedValue, 
//                       int interestRatePassedValue, int minimumPaymentPercentagePassedValue)
//
// Parameters:  ofstream &thisfile - the address of the output stream thisfile
//              double creditCardBalancePassedValue - the credit card balance value passed from int main()
//              int interestRatePassedValue - the interest rate value passed from int main()
//              int minimumPaymentPercentagePassedValue - the minimum payment percentage value passed from int main()
//
// Outputs:    None
//
// Returns:    None
//
// Author:     Matthew Fu
//
// Date:       2018.12.06
//
//
// Description: This function calculates all the values needed to be displayed. It
//              does so using a while loop and the loop iterates until the credit card 
//              balance is equal to zero. At each iteration, it calls the output function
//              so that each month's information gets put into the text file.
//
//
/*****************************************************************************/
void calculate(ofstream &thisfile, double creditCardBalancePassedValue, int interestRatePassedValue, 
   int minimumPaymentPercentagePassedValue) {
   //First I declare outside the while loop the variables for the amount of months and the
   //sum of interestPaid.
   int month = 0;
   double sum = 0;

   while (creditCardBalancePassedValue > 0) {
      //Then I declare the variables for minimum payment each month, interest paid, and the principal paid.
      //Each variable is the formula for their values. Each time the loop iterates, their values will change
      //until the credit card balance is zero.
      double minimumPayment = creditCardBalancePassedValue * ((minimumPaymentPercentagePassedValue * 0.01) + 0.0008);
      double interestPaid = (creditCardBalancePassedValue * (interestRatePassedValue * 0.01)) / 12;
      double principalPaid = minimumPayment - interestPaid;

      //The sum is the total interest paid. It accumulates after each month.
      sum += interestPaid;

      //This is a checking statement. If the minimum payment ever falls less than $15, then 
      //this will set it at $15.
      if (minimumPayment < 15.0) {
         minimumPayment = 15.0;
         principalPaid = minimumPayment - interestPaid;
      }

      //This statement is for the final line. If the credit card balance falls below
      //the minimum payment, then the final payment will simply be the remainder of the 
      //credit card balance.
      if (creditCardBalancePassedValue < minimumPayment) {
         minimumPayment = creditCardBalancePassedValue + interestPaid;
         creditCardBalancePassedValue = principalPaid;
      }

      //The credit card balance is subtracted each month by the principal paid.
      creditCardBalancePassedValue -= principalPaid;

      //This is to iterate each month
      month++;

      //Finally, I call the output function. This will display all the information for each iteration of the
      //loop
      outputCalculation(thisfile, month, creditCardBalancePassedValue, interestPaid, minimumPayment, sum);



   }
}


/*****************************************************************************/
//
// Function: void outputHeader(ofstream &thisfile, double creditCardBalance, 
//                              int interestRate, int minimumPaymentPercentageValue)
//
// Parameters:  ofstream &thisfile - the address to the output stream thisfile
//              double creditCardBalanceValue - the value of the credit card balance from main()
//              int interestRateValue - the value of the interest rate from main.
//              int minimumPaymentPercentageValue - the value of the minimum payment percentage from main()
//              
// Outputs:    None
//
// Returns:    
//
// Author:     Matthew Fu
//
// Date:       2018.12.06
//
//
// Description: This function outputs the header of the payment schedule. It outputs
//              the starting credit card balance, interest rate, and the percent
//              of minimum payment as well as the header of the calculated values
//              in a neat, ordered manner.
//
//
/*****************************************************************************/
void outputHeader(ofstream &thisfile, double creditCardBalanceValue, int interestRateValue, 
                  int minimumPaymentPercentageValue) {
   if (thisfile.is_open())
   {
      //The various setwidth are to output the headers neatly. 
      thisfile << setw(27) << setprecision(2) << fixed << "Balance Owing: $" << creditCardBalanceValue << endl;
      thisfile << setw(20) << "APR as % " << interestRateValue << endl;
      thisfile << setw(44) << "Percent for minimum payment as % " << minimumPaymentPercentageValue << endl;
      thisfile << setw(48) << "-----------------------------------------" << endl;
      thisfile << "Month   Balance   Interest this    Minimum   Sum of interest " << endl;
      thisfile << setw(26) << "month" << setw(29) << "paid" << endl << endl;
   }
}

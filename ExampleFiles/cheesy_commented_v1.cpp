/*
Name: John Koss
Date: 04/15/2021
Section: ITCS 2530 V0801 2021SS - C++ Programming 1

Cheesey.cpp:
A cheese container can hold 2.76 kg of cheese. Each evening, a fromager ships containers of cheese to a local grocery store. The cost of producing one container of cheese is $4.12, and the profit of each container of cheese is $1.45.

 Write a program that does the following:

	1) Prompts the user to enter the total amount of cheese produced each evening.
	2) Outputs the number of containers needed to hold the cheese. (Round your answer to the nearest integer.)
	3) Outputs the cost of producing the cheese.
	4) Outputs the profit for producing cheese.
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Consts
const float CONTAINER_SIZE = 2.76f;
const double COST = 4.12;
const double PROFIT = 1.45;
const int HEADERLEN = 75;

// All code is contained in "main".
int main() {

	// I used variables here so that I could calculate and 
	// adjust the size of the program introduction.
	string sTitle = " Welcome to my Cheesy Program ";
	int iTitleLen = static_cast<int>(sTitle.length()); // Quell compiler warning.
	
	// Calculate and then create a variable that
	// can be used to print 1/2 of the stars for
	// the program intro.
	int iFillLen = HEADERLEN - iTitleLen;
	int iFillLenHalf = iFillLen / 2;
	string strFill(iFillLenHalf,'*');

	cout << setfill('*');
	cout << setw(HEADERLEN) << "*" << endl;
	// static_cast to quell complier warning.
	cout << setw(static_cast<std::streamsize>(iTitleLen) + iFillLenHalf) << right << sTitle << strFill << endl;
	cout << setw(HEADERLEN) << "*" << endl << endl;

	// Reset fill.
	cout << setfill(' ');

	// Declare where needed and not at top of program.
	// Always initialize my variables - even if being overwriten.
	int iTotalChese = 0;
	cout << "Please enter the total number of kilograms of cheese produced: ";
	cin >> iTotalChese;
	cout << endl;

	// Quell compiler warning and always round up. 
	// My thinking is that there always needs to a container for the cheese, even 
	// if not 100% full. Is this correct? Can you sell a partial container?
	// TODO: Talk to customer to get clarification on this.
	int iTotalContainer = static_cast<int>(ceil(iTotalChese / CONTAINER_SIZE));
	string sOutput = "The number of containers to hold the cheese is: ";
	cout << sOutput << std::right << std::setw(HEADERLEN - sOutput.length()) << to_string(iTotalContainer) << endl;

	// The must have for 2 decimal places when printing a stream.
	cout << setprecision(2) << std::fixed;

	// Declare where needed and not at top of program.
	double dTotalCost = iTotalContainer * COST;
	sOutput = "The cost of producing " + to_string(iTotalContainer) + " container(s) of cheese is: $";
	cout << sOutput << std::right << std::setw(HEADERLEN - sOutput.length()) << dTotalCost << endl;

	// Declare where needed and not at top of program.
	double dTotalProfits = iTotalContainer * PROFIT;
	sOutput = "The profit from producing " + to_string(iTotalContainer) + " container(s) of cheese is: $";
	cout << sOutput << std::right << std::setw(HEADERLEN - sOutput.length()) << dTotalProfits << endl;
	
	system("PAUSE");
}

////////////////////////////////////////////////////////////////
// CODE THAT I TRIED BUT DID NOT END UP IN THE FINAL PROGRAM //

// string sOutput = "The number of containers to hold the cheese is: " + to_string(iTotalContainer); -> I couldn't get to_string() to compile
// int iTotalContainer = (iTotalChese / CONTAINER_SIZE) + 1; -> This always rounds up and I didn't think it was correct.

// First attempt. I didn't use this as it wasn't as flexible as it needed to be.
//***************************************************************************
//********************** Welcome to my Cheesy Program **********************
//***************************************************************************
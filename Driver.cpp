//***********************************************************************************
//  Driver.cpp
//  CSS 342 Program-6
//
//  Created by Fahad Alshehri on November 25, 2017.
//  This driver implements the LinkedList class.
//***********************************************************************************


#include <iostream>
#include "List.h"
using namespace std;


//-------------------------------------------------------------------------------------
// An entry point of the program
//-------------------------------------------------------------------------------------
int main()
{
	// First testing case
	// Initilizing the list
	List *offeredFallQuarterClasses = new List();

	// Initilizing the Objects we want to insert
	Object num1; 
	num1.data = 332;
	Object num2; 
	num2.data = 301;
	Object num3;
	num3.data = 342; 
	Object num4;
	num4.data = 360;
	Object num5;
	num5.data = 475;
	Object num6;
	num6.data = 377;
	Object num7;
	num7.data = 350;
	Object num8;
	num8.data = 430;
	Object num9;
	num9.data = 422;
	Object num10;
	num10.data = 370;
	Object num11;
	num11.data = 497;
	Object num12;
	num12.data = 480;
	Object num13;
	num13.data = 477;

	// Append the objects into the list
	cout << endl;
	cout << "-- CREATING AND APPENDING CLASSES TO LIST..." << endl;
	offeredFallQuarterClasses->append(num1);
	offeredFallQuarterClasses->append(num2);
	offeredFallQuarterClasses->append(num3);
	offeredFallQuarterClasses->append(num4);
	offeredFallQuarterClasses->append(num5);
	offeredFallQuarterClasses->append(num6);
	offeredFallQuarterClasses->append(num7);
	offeredFallQuarterClasses->append(num8);
	offeredFallQuarterClasses->append(num9);
	offeredFallQuarterClasses->append(num10);
	offeredFallQuarterClasses->append(num11);
	offeredFallQuarterClasses->append(num12);
	offeredFallQuarterClasses->append(num13);

	// Print the list
	cout << "-- PRINTING LIST OF CLASSES OFFERED FALL QUARTER:" << endl;
	offeredFallQuarterClasses->print();

	cout << endl;
	cout << "-- APPEND AND PRINTING FUNCTIONALITY: TESTED!" << endl;

	cout << "-------------------------------------" << endl;
	cout << "-- NOW REVERSING... (ITERATIVELY)" << endl;
	offeredFallQuarterClasses->reverseIterative(offeredFallQuarterClasses->getHead());
	cout << "-- PRINTING LIST OF CLASSES OFFERED FALL QUARTER:" << endl;
	offeredFallQuarterClasses->print();

	cout << "-------------------------------------" << endl;
	cout << "-- NOW REVERSING... (RECURSIVELY)" << endl;
	offeredFallQuarterClasses->reverseRecursive(offeredFallQuarterClasses->getHead());
	cout << "-- PRINTING LIST OF CLASSES OFFERED FALL QUARTER:" << endl;
	offeredFallQuarterClasses->print();
	cout << endl;
	cout << "-- REVERSE FUNCTIONALITY (ITERATIVE): TESTED!" << endl;
	cout << "-- REVERSE FUNCTIONALITY (RECURSIVE): TESTED!" << endl;


	// Second testing case
	// Initilizing the list
	List *evenNumbers = new List();

	// Initilizing the Objects we want to insert
	Object x1;
	x1.data = 2;
	Object x2;
	x2.data = 4;
	Object x3;
	x3.data = 6;
	Object x4;
	x4.data = 8;
	Object x5;
	x5.data = 10;
	Object x6;
	x6.data = 12;
	Object x7;
	x7.data = 14;
	Object x8;
	x8.data = 16;
	Object x9;
	x9.data = 18;
	Object x10;
	x10.data = 20;

	// Append the objects into the list
	cout << endl;
	cout << "-- CREATING AND APPENDING EVEN NUMBERS TO LIST..." << endl;
	evenNumbers->append(x1);
	evenNumbers->append(x2);
	evenNumbers->append(x3);
	evenNumbers->append(x4);
	evenNumbers->append(x5);
	evenNumbers->append(x6);
	evenNumbers->append(x7);
	evenNumbers->append(x8);
	evenNumbers->append(x9);
	evenNumbers->append(x10);

	cout << "-- PRINTING LIST OF EVEN NUMBERS (UP TO 20)" << endl;
	evenNumbers->print();

	cout << endl;
	cout << "-------------------------------------" << endl;
	cout << "-- CREATING A DEEP COPY OF EVEN NUMBERS.." << endl;
	List *copyOfEvenNumbers = new List(*evenNumbers);
	cout << "-- WHAT IS THE SIZE OF THIS DEEP COPY?" << endl;
	cout << copyOfEvenNumbers->size();
	cout << endl;
	cout << "-- DELETE POSITION 2 FROM OUR ORIGINAL EVEN NUMBERS LIST.." << endl;
	evenNumbers->Delete(2);
	evenNumbers->print();
	cout << endl;
	cout << "-- WHAT IS THE SIZE OF THE ORIGINAL EVEN NUMBERS LIST NOW?" << endl;
	cout << evenNumbers->size();
	cout << endl;
	cout << "-- DELETE POSITION 3 FROM OUR ORIGINAL EVEN NUMBERS LIST.." << endl;
	evenNumbers->Delete(3);
	evenNumbers->print();
	cout << "-- WHAT IS THE SIZE OF THE DEEP COPY? (SHOULD BE UNCHANGED, SO 10)" << endl;
	cout << copyOfEvenNumbers->size();
	cout << endl;
	cout << "-- DELETE FUNCTIONALITY: TESTED!" << endl;

	cout << "-------------------------------------" << endl;
	cout << "-- PRINTING THE DEEP COPY OF EVEN NUMBERS (SHOULD NOT HAVE 4 AND 8 REMOVED).." << endl;
	copyOfEvenNumbers->print();
	cout << endl;
	cout << "-- DEEP CONSTRUCTOR FUNCTIONALITY: TESTED!" << endl;

	cout << "-------------------------------------" << endl;
	cout << "-- IS THE DEEP COPY OF EVEN NUMBERS EMPTY?" << endl;
	if (copyOfEvenNumbers->isEmpty()) {
		cout << "YES." << endl;
	}
	else {
		cout << "NO." << endl;
	}
	cout << "-- WHAT IS THE SIZE OF THIS LIST?" << endl;
	cout << copyOfEvenNumbers->size();
	cout << endl;
	cout << "-- INSERT 100 AT POSITION 4 OF THE DEEP COPY.." << endl;
	Object one100;
	one100.data = 100;
	copyOfEvenNumbers->insert(one100, 4);
	copyOfEvenNumbers->print();
	cout << endl;

	cout << "-- WHICH POSITION IS 100 AT? (SHOULD BE 4)" << endl;
	cout << copyOfEvenNumbers->find(one100);
	cout << endl;
	cout << "-- FIND FUNCTIONALITY: TESTED!" << endl;
	cout << endl;
	cout << "-------------------------------------" << endl;
	cout << "-- CLEARING THE DEEP COPY OF EVEN NUMBERS (SHOULD NOT PRINT ANYTHING NOW).." << endl;
	copyOfEvenNumbers->clear();
	copyOfEvenNumbers->print();
	cout << endl;
	cout << "-- CLEAR FUNCTIONALITY: TESTED!" << endl;

	cout << "-------------------------------------" << endl;
	cout << "-- IS THE DEEP COPY OF EVEN NUMBERS EMPTY?" << endl;
	if (copyOfEvenNumbers->isEmpty()) {
		cout << "YES." << endl;
	}
	else {
		cout << "NO." << endl;
	}
	cout << "-- WHAT IS THE SIZE OF THIS LIST?" << endl;
	cout << copyOfEvenNumbers->size();
	cout << endl;
	cout << "-- IS EMPTY FUNCTIONALITY: TESTED!" << endl;
	cout << "-- SIZE FUNCTIONALITY: TESTED!" << endl;
	cout << endl;
	cout << "-------------------------------------" << endl;
	cout << "-- INSERT 2 AT THE HEAD OF THE DEEP COPY.." << endl;
	copyOfEvenNumbers->insert(x1, 1);
	copyOfEvenNumbers->print();
	cout << "-- INSERT FUNCTIONALITY: TESTED!" << endl;
	cout << endl;

	//deleting all of my linked-lists to clean up memory 
	cout << "------------------Calling Destructor -----------------" << endl;
	
	delete copyOfEvenNumbers;
	delete evenNumbers;
	delete offeredFallQuarterClasses;
	//should print destructor got called 3 times
	cout << "-- END OF TESTING --" << endl;
	
	
	cout << endl;
	return 0;
}
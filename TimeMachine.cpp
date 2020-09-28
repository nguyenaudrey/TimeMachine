/*
* Student: Audrey Nguyen
* Professor: Robery Dimpsey
* Assignment #1: TimeMachine.cpp
* Description: Driver for the TimeSpan class.
*/

#include <iostream>
#include "TimeSpan.h"
using namespace std;

/*
* Author: Audrey Nguyen
*/
int main() {
	
	// Testing constructors
	cout << "Testing Constructors" << endl;
	TimeSpan ts1, ts2(12345.6), ts3(-30, 500), ts4(2.5, 22, -36), 
		ts5(-5, 178.32, 444), ts6(0.0,0,0);
	cout << "Expected: Hours: 0, Minutes: 0, Seconds: 0" << endl;
	cout << "Actual:   " << ts1 << endl; 
	cout << "Expected: Hours: 3, Minutes: 25, Seconds: 46" << endl;
	cout << "Actual:   " << ts2 << endl; 
	cout << "Expected: Hours: 0, Minutes: -21, Seconds: -40" << endl;
	cout << "Actual:   " << ts3 << endl; 
	cout << "Expected: Hours: 2, Minutes: 51, Seconds: 24" << endl;
	cout << "Actual:   " << ts4 << endl; 
	cout << "Expected: Hours: -1, Minutes: -54, Seconds: -17" << endl;
	cout << "Actual:   " << ts5 << endl; 
	cout << "Expected: Hours: 0, Minutes: 0, Seconds: 0" << endl;
	cout << "Actual:   " << ts6 << endl; 
	cout<< endl;

	// Testing getters
	cout << "Testing getHours()" << endl;
	cout << "Expected: 3" << endl;
	cout << "Actual:   " << ts2.getHours() << endl;
	cout << "Expected: -1" << endl;
	cout << "Actual:   " << ts5.getHours() << endl;
	cout << "Expected: 0" << endl;
	cout << "Actual:   " << ts6.getHours() << endl;
	cout << endl;

	cout << "Testing getMinutes()" << endl;
	cout << "Expected: 25" << endl;
	cout << "Actual:   " << ts2.getMinutes() << endl;
	cout << "Expected: -54" << endl;
	cout << "Actual:   " << ts5.getMinutes() << endl;
	cout << "Expected: 0" << endl;
	cout << "Actual:   " << ts6.getMinutes() << endl;
	cout << endl;

	cout << "Testing getSeconds()" << endl;
	cout << "Expected: 46" << endl;
	cout << "Actual:   " << ts2.getSeconds() << endl;
	cout << "Expected: -17" << endl;
	cout << "Actual:   " << ts5.getSeconds() << endl;
	cout << "Expected: 0" << endl;
	cout << "Actual:   " << ts6.getSeconds() << endl;
	cout << endl;

	// Testing setters
	cout << "Testing setTime()" << endl;
	TimeSpan ts7(1, 45, 6), ts8(-1, -45, -6), ts9(-1, -45, -6), 
		ts10, ts11, ts12, ts13, ts14, ts15;
	ts7.setTime(-1, -38.9, 1270);
	ts8.setTime(0, 74, 340.82);
	ts9.setTime(0,0,0);
	
	cout << "Expected: Hours: -1, Minutes: -17, Seconds: -44" << endl;
	cout << "Actual:   " << ts7 << endl;
	cout << "Expected: Hours: 1, Minutes: 19, Seconds: 41" << endl;
	cout << "Actual:   " << ts8 << endl;
	cout << "Expected: Hours: 0, Minutes: 0, Seconds: 0" << endl;
	cout << "Actual:   " << ts9 << endl;
	cout << endl;

	// Testing + and - operators
	cout << "Testing +" << endl;
	ts10 = ts2 + ts4;
	ts11 = ts2 + ts3;
	ts12 = ts2 + ts1;
	cout << "Expected: Hours: 6, Minutes: 17, Seconds: 10" << endl;
	cout << "Actual:   " << ts10 << endl;
	cout << "Expected: Hours: 3, Minutes: 4, Seconds: 6" << endl;
	cout << "Actual:   " << ts11 << endl;
	cout << "Expected: Hours: 3, Minutes: 25, Seconds: 46" << endl;
	cout << "Actual:   " << ts12 << endl;
	cout << endl;

	cout << "Testing -" << endl;
	ts13 = ts2 - ts4;
	ts14 = ts2 - ts3;
	ts15 = ts2 - ts1;
	cout << "Expected: Hours: 0, Minutes: 34, Seconds: 22" << endl;
	cout << "Actual:   " << ts13 << endl;
	cout << "Expected: Hours: 3, Minutes: 47, Seconds: 26" << endl;
	cout << "Actual:   " << ts14 << endl;
	cout << "Expected: Hours: 3, Minutes: 25, Seconds: 46" << endl;
	cout << "Actual:   " << ts15 << endl;
	cout << endl;

	// Testing += and -= operators
	cout << "Testing +=" << endl;
	ts13 += ts2;
	ts14 += ts3;
	ts15 += ts4;
	cout << "Expected: Hours: 4, Minutes: 0, Seconds: 8" << endl;
	cout << "Actual:   " << ts13 << endl;
	cout << "Expected: Hours: 3, Minutes: 25, Seconds: 46" << endl;
	cout << "Actual:   " << ts14 << endl;
	cout << "Expected: Hours: 6, Minutes: 17, Seconds: 10" << endl;
	cout << "Actual:   " << ts15 << endl;
	cout << endl;

	cout << "Testing -=" << endl;
	ts10 -= ts2;
	ts11 -= ts4;
	ts12 -= ts3;
	cout << "Expected: Hours: 2, Minutes: 51, Seconds: 24" << endl;
	cout << "Actual:   " << ts10 << endl;
	cout << "Expected: Hours: 0, Minutes: 12, Seconds: 42" << endl;
	cout << "Actual:   " << ts11 << endl;
	cout << "Expected: Hours: 3, Minutes: 47, Seconds: 26" << endl;
	cout << "Actual:   " << ts12 << endl;
	cout << endl;
	

	// Testing unary negation
	cout << "Testing Unary Negation" << endl;
	TimeSpan pos1(3, 5, 2), neg1(-3, -5, -2);
	cout << "Expected: Hours: -3, Minutes: -5, Seconds: -2" << endl;
	cout << "Actual:   " << -pos1 << endl;
	cout << "Expected: Hours: 3, Minutes: 5, Seconds: 2" << endl;
	cout << "Actual:   " << -neg1 << endl;
	cout << "Expected: Hours: 0, Minutes: 0, Seconds: 0" << endl;
	cout << "Actual:   " << ts1 << endl;
	cout << endl;

	// Testing == and != operators
	cout << "Testing == Operator" << endl;
	cout << "Expected: 1" << endl;
	cout << "Actual:   " << (-pos1 == neg1) << endl;
	cout << "Expected: 0" << endl;
	cout << "Actual:   " << (-pos1 == pos1) << endl;
	cout << endl;
	cout << "Testing != Operator" << endl;
	cout << "Expected: 1" << endl;
	cout << "Actual:   " << (-neg1 != neg1) << endl;
	cout << "Expected: 0" << endl;
	cout << "Actual:   " << (-neg1 != pos1) << endl;
	cout << endl;

	//Testing << operator
	cout << "Testing << Operator" << endl;
	cout << "Expected: Hours: 1, Minutes: 2, Seconds: 3" << endl;
	TimeSpan outStreamTS(1, 2, 3);
	cout << "Actual:   " << outStreamTS << endl;
	cout << endl;

	// Testing >> operator
	cout << "Testing >> Operator" << endl;
	cout << "Enter: -2.4 36.2 -12.9";
	cout << endl;
	TimeSpan inStreamTS;
	cin >> inStreamTS;
	cout << "Expected: Hours: -1, Minutes: -48, Seconds: -1" << endl;
	cout << "Actual:   " << inStreamTS << endl;
	
	return 0;
}
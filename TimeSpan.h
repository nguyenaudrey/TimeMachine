/*
* Student: Audrey Nguyen
* Professor: Robery Dimpsey
* Assignment #1: TimeSpan.h
* Description: Header file for the TimeSpan class.
* It represents a duration of time in hours, minutes, and seconds.
*/

#pragma once
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

class TimeSpan
{

	public:
		// Constructors 
		TimeSpan();

		TimeSpan(double seconds);
		TimeSpan(double minutes, double seconds);
		TimeSpan(double hours, double minutes, double seconds);
		
		// Getters
		int getHours() const;
		int getMinutes() const;
		int getSeconds() const;

		// Setters
		bool setTime(double hours, double minutes, double seconds);
		
		// Operators
		TimeSpan operator-(const TimeSpan& ts) const;
		TimeSpan& operator-=(const TimeSpan& rat);

		TimeSpan operator+(const TimeSpan& ts) const;
		TimeSpan& operator+=(const TimeSpan& ts);

		TimeSpan operator-() const;

		bool operator==(const TimeSpan& ts) const;
		bool operator!=(const TimeSpan& ts) const;

		friend ostream& operator<<(ostream& outStream, const TimeSpan& ts);
		friend istream& operator>>(istream& inStream, TimeSpan& ts);

	private:
		int hours;
		int minutes;
		int seconds;
	
};
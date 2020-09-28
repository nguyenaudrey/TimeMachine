/*
* Student: Audrey Nguyen
* Professor: Robery Dimpsey
* Assignment #1: TimeSpan.cpp
* Description: cpp file for the TimeSpan class.
* It represents a duration of time in hours, minutes, and seconds.
*/

#include "TimeSpan.h"

/*
* Default constructor for TimeSpan
* Creates a TimeSpan object with 0 hours, 0 minutes, and 0 seconds
*/
TimeSpan::TimeSpan()
{
	setTime(0.0, 0.0, 0.0);
}

/*
* Creates a TimeSpan object with user defined amount of seconds
* Accepts a double representing seconds
*/
TimeSpan::TimeSpan(double seconds)
{
	setTime(0.0, 0.0, seconds);
}

/*
* Creates a TimeSpan object with user defined amount of minutes and seconds
* Accepts two doubles representing minutes and seconds
*/
TimeSpan::TimeSpan(double minutes, double seconds)
{
	setTime(0.0, minutes, seconds);
}

/*
* Creates a TimeSpan object with user defined amount of hours, minutes, and seconds
* Accepts three doubles representing hours, minutes, and seconds
*/
TimeSpan::TimeSpan(double hours, double minutes, double seconds)
{
	setTime(hours, minutes, seconds);
}

/*
* Gets the amount of hours in the TimeSpan represented by an integer
*/
int TimeSpan::getHours() const
{
	return hours;
}

/*
* Gets the amount of minutes in the TimeSpan represented by an integer
*/
int TimeSpan::getMinutes() const 
{
	return minutes;
}

/*
* Gets the amount of seconds in the TimeSpan represented by an integer
*/
int TimeSpan::getSeconds() const 
{
	return seconds;
}

/*
* Sets the time, represented by integers.
* Takes in 3 doubles representing hours, minutes, and seconds
* Returns true if successfully set the time
*/
bool TimeSpan::setTime(double hours, double minutes, double seconds)
{
	// Converts hours and minutes to seconds
	double totalMinutes = minutes + (hours * 60);
	double totalSeconds = seconds + (totalMinutes * 60);
	int tempH = 0;
	int tempM = 0;
	int tempS = round(totalSeconds);

	// Converts seconds to minutes
	if (tempS <= -60 || tempS >= 60) 
	{
		tempM = tempS / 60; 
		tempS -= (tempM * 60);
	}
	
	// Converts minutes to hours
	if (tempM <= -60 || tempM >= 60) 
	{
		tempH = tempM / 60;
		tempM -= (tempH * 60);
	}

	// Instantiates the variables
	this->hours = tempH;
	this->minutes = tempM;
	this->seconds = tempS;

	return true;
}

/*
* Overloads the + operator
*/
TimeSpan TimeSpan::operator+(const TimeSpan& ts) const
{
	TimeSpan result = *this;
	result += ts;
	return result;
}

/*
* Overloads the += operator
*/
TimeSpan& TimeSpan::operator+=(const TimeSpan& ts)
{
	int tempH = hours + ts.hours;
	int tempM = minutes + ts.minutes;
	int tempS = seconds + ts.seconds;
	setTime(tempH, tempM, tempS);
	return *this;
}

/*
* Overloads the - operator
*/
TimeSpan TimeSpan::operator-(const TimeSpan& ts) const
{
	TimeSpan result = *this;
	result -= ts;
	return result;
}

/*
* Overloads the -= operator
*/
TimeSpan& TimeSpan::operator-=(const TimeSpan& ts)
{
	int tempH = hours - ts.hours;
	int tempM = minutes - ts.minutes;
	int tempS = seconds - ts.seconds;
	setTime(tempH, tempM, tempS);
	return *this;
}

/*
* Overloads the unary negation operator
* Changes hours, minutes, and seconds to be the opposite sign
*/
TimeSpan TimeSpan::operator-() const
{
	TimeSpan temp;
	temp.hours = -hours;
	temp.minutes = -minutes;
	temp.seconds = -seconds;
	return temp;
}

/*
* Overloads the == operator
* Returns true if both TimeSpans have identical hours, minutes, and seconds
*/
bool TimeSpan::operator==(const TimeSpan& ts) const
{
	return((hours == ts.hours) && (minutes == ts.minutes) 
		&& (seconds == ts.seconds));
}

/*
* Overloads the != operator
* Returns false if both TimeSpans have identical hours, minutes, and seconds
*/
bool TimeSpan::operator!=(const TimeSpan& ts) const
{
	return((hours != ts.hours) && (minutes != ts.minutes)
		&& (seconds != ts.seconds));
}

/* 
* Overloads the << operator
* Returns an outstream in the format of "Hours: #, Minutes: #, and Seconds: #"
*/
ostream& operator<<(ostream& outStream, const TimeSpan& ts)
{
	outStream << "Hours: " << ts.hours << ", Minutes: " << ts.minutes << ", Seconds: " << ts.seconds;
	return outStream;
}

/*
* Overloads the >> operator
* Returns an istream with the hours, minutes, and seconds
*/
istream& operator>>(istream& inStream, TimeSpan& ts)
{
	double hours, minutes, seconds;
	inStream >> hours >> minutes >> seconds;
	ts.setTime(hours, minutes, seconds);
	return inStream;
}
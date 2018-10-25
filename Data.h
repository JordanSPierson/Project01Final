//
//Data.h
//.h file for the Data class
//Jordan Pierson
//COSC2030, Fall 2018



#pragma once

#ifndef _Data_H_
#define _Data_H_


#include<string>
using std::string;
using std::to_string;

// Prototype for the Data class, which is used to store data for each day and each week.
class Data
{
private:
	float sum,
		max,
		min;
	int sumOFCounter,
		count;

public:

	Data() : sum(0), sumOFCounter(0), max(0), min(1000000), count(0) {}
	//Functions that add or increment variables recorded. addSum also calls maxCheck and minCheck.
	void addSum(float input);
	void maxCheck(float input);
	void minCheck(float input);
	void inputNum(float input);
	//
	//Accessor Functions
	string returnSum(void);
	float returnMax(void);
	float returnMin(void);
	float returnCount(void);
};

#endif
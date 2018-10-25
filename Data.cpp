//
//Data.cpp
//Data class function definitions file
//Jordan Pierson
//COSC2030, Fall 2018


#include "Data.h"

// InputNum, calls other functions (addSum, maxCheck, and minCheck)  when a number is inputed 
void Data::inputNum(float input)
{
	//Bounds: lowest must be higher than 0, and the highest recorded blood sugar was 147.6 mmol/L

	//*Uncomment the code and comment the other 'if' statement to test the overflow without
	//entering numbers (<=150) up to a million:

	//if(input > 0)
	if (input > 0 && input <= 150)
	{
		addSum(input);
		maxCheck(input);
		minCheck(input);
	}
}

// addSum adds the number entered to the sum variable, checking for overflow of one million, and increasing sumOFCounter accordingly
// this function also increases the count variable
void Data::addSum(float input)
{
	
		//checks to see if the sum is going to overflow over one million
		if (sum + input >= 1000000)
		{
			//Sets day sum to new number & increments the day sum counter
			sum = sum + input - 1000000;
			sumOFCounter++;
		}
		else
		{
			sum = sum + input;
		}
		count++;
		maxCheck(input);
		minCheck(input);
	
}

// maxCheck checks to see if the current number entered is
// larger than the currently stored max. If it is max is 
// assigned the value of input
void Data::maxCheck(float input)
{
	if (input > max)
	{
		max = input;
	}
}

// minCheck checks to see if the current number entered is
// smaller than the currently stored min. If it is min is 
// assigned the value of input
void Data::minCheck(float input)
{
	if (input < min)
	{
		min = input;
	}
}

//Accessor Functions

string Data::returnSum()
{
	string sSum;
	if (sumOFCounter > 0)
	{
		sSum = to_string(sumOFCounter) + " x 10^6, + " + to_string(sum);
	}
	else
	{
		sSum = to_string(sum);
	}
	//find way of storing both the sum and sum overflow variables in string!	
	return sSum;

}

float Data::returnMax()
{
	return max;
}

float Data::returnMin()
{
	return min;
}

float Data::returnCount()
{
	return count;
}

//
//Project1Driver.cpp
//Blood Sugar Project Driver file
//Jordan Pierson
//COSC2030, Fall 2018

#include "Data.h"
#include<iostream>
#include <stdlib.h>
using std::cin;
using std::cout;
using std::endl;

int main()
{
	//This creates two arrays, one for days and one for weeks of type Data (the class)
	Data Days[14];
	Data Weeks[2];

	string input;

	// These are increments for both days and weeks
	int i(0),
		i2(0);
	// First section of the program, tells the user how to use the program
	cout << "---------------------------------------------"
		<< "\nDay: " << i + 1 << ", Week: " << i2 + 1
		<< "\nEnter blood sugar in mmol/L"
		<< "\nEnter D/Day for daily summaries"
		<< "\nEnter W/Week for a weekly summary (thus far)"
		<< "\nEnter 'N'/'Next' to go to the next day."
		<< "\nEnter 'E'/'Exit' to exit the program."
		<< "\n---------------------------------------------" << endl;

	// This while loop encompasses the code and doesn't end until either
	// a) the user increments to the 15th day; or
	// b) the user wants to exit.
	while (i <= 13 && i2 <= 1)
	{

		cin >> input;
		cout << endl;

		if (input == "Day" || input == "D" || input == "d")
		{
			//report daily summaries
			cout << "---------------------------------------------\n"
				<< "Daily Summaries for Day " << i + 1 << ":"
				<< "\nThe sum of all blood sugar readings for today: " << Days[i].returnSum()
				<< "\nThe maximum blood sugar reading recorded today: " << Days[i].returnMax() << " mmol/L"
				<< "\nThe minimum blood sugar reading recorded today: " << Days[i].returnMin() << " mmol/L"
				<< "\nThe number of valid blood sugar readings recorded today:" << Days[i].returnCount() << "\n"
				<< "---------------------------------------------" << endl;
		}

		if (input == "Week" || input == "W" || input == "w")
		{
			//Calculate Delta, store the first day of the biggest delta in fDay and the difference in lCount
			int fDay = 0;
			int lCount = 0;
			//There is probably a more efficient way of finding/storing the delta
			//This function checks to make sure that we don't end up with a negative difference 
			//by subtracting the lower valued count from the higher valued count regardless of day
			//Then if the conditions are met storing the day in fDay and the difference in lCount
			if (i2 == 0)
			{
				for (int ii = 0; ii < 7 && ii < i; ii++) // the and clause ensures that if you are only halfway through the week it won't count the following days as zero
				{
					if (Days[ii].returnCount() > Days[ii + 1].returnCount() && (Days[ii].returnCount() - Days[ii + 1].returnCount()) > lCount)
					{
						fDay = ii;
						lCount = (Days[ii].returnCount() - Days[ii + 1].returnCount());
					}
					else if (Days[ii].returnCount() < Days[ii + 1].returnCount() && (Days[ii + 1].returnCount() - Days[ii].returnCount()) > lCount)
					{
						fDay = ii;
						lCount = (Days[ii + 1].returnCount() - Days[ii].returnCount());
					}
				}
			}
			else if (i2 == 1)
			{
				for (int ii = 7; ii < 14 && ii < i; ii++)// the and clause ensures that if you are only halfway through the week it won't count the following days as zero
														// also the reasoning behind the change of starting ii and the conditions met being less than 14 specify that only 
														//week 2 data is taken into account.
				{
					if (Days[ii].returnCount() > Days[ii + 1].returnCount() && (Days[ii].returnCount() - Days[ii + 1].returnCount()) > lCount)
					{
						fDay = ii;
						lCount = (Days[ii].returnCount() - Days[ii + 1].returnCount());
					}
					else if (Days[ii].returnCount() < Days[ii + 1].returnCount() && (Days[ii + 1].returnCount() - Days[ii].returnCount()) > lCount)
					{
						fDay = ii;
						lCount = (Days[ii + 1].returnCount() - Days[ii].returnCount());
					}
				}
			}

			// Report weekly summaries
			cout << "\n" <<
				"---------------------------------------------\n"
				<< "Weekly summaries (thus far) for week " << i2 + 1 << ":"
				<< "\nThe sum of all blood sugar readings for this week: " << Weeks[i2].returnSum()
				<< "\nThe maximum blood sugar reading recorded this week: " << Weeks[i2].returnMax() << " mmol/L"
				<< "\nThe minimum blood sugar reading recorded this week: " << Weeks[i2].returnMin() << " mmol/L"
				<< "\nThe number of valid blood sugar readings recorded this week: " << Weeks[i2].returnCount() << endl;
			
			if (lCount > 0)
			{

				cout << "The days with the biggest day to day (count) delta for this week are: \n\t-Day " << fDay + 1 << ", and day " << fDay + 2
					<< ". With a delta of " << lCount << endl;
			}
			else
			{
				cout << "There was no delta for this week. Every day had the same count of valid numbers, \nor there hasn't been enough days entered yet to compute." << endl;
			}
			cout << "---------------------------------------------\n" << endl;

		}

		if (input == "Next" || input == "N" || input == "n")
		{
			if (i < 13)
			{
				// Increment the day
				i++;
				if (i == 7)
				{
					//Increment week if it is day 8
					i2++;
				}
				// Report day and week if it is week 1
				if (i2 == 0)
				{
					cout << "\n---------------------------------------------"
						<< "\nIt is now Day " << i + 1 << ", of week one"
						<< "\n---------------------------------------------"
						<< endl;
				}
				// Report day and week if it is week 2
				// minus 6 tells the day of that specific week.
				// Ex. if day is 10, thus [9] in days(i==9). 9 - 6 = Day 3 of week 2
				if (i2 == 1)
				{
					cout << "\n---------------------------------------------"
						<< "\nIt is now Day " << i - 6 << ", of week two " << " (Day " << i + 1 << " overall)"
						<< "\n---------------------------------------------"
						<< endl;
				}
			}
			else
			{
				// This code runs when 'n' is called at day 14.
				// It states the end of the program and reports weekly summaries, because why not?
				int fDay = 0;
				int lCount = 0;
				//Again, there is probably a more efficient way of finding/storing the delta
				for (int ii = 0; i <= 14; i++)
				{
					if (Days[ii].returnCount() > Days[ii + 1].returnCount() && (Days[ii].returnCount() - Days[ii + 1].returnCount()) > lCount)
					{
						fDay = ii;
						lCount = (Days[ii].returnCount() - Days[ii + 1].returnCount());
					}
					else if (Days[ii].returnCount() < Days[ii + 1].returnCount() && (Days[ii + 1].returnCount() - Days[ii].returnCount()) > lCount)
					{
						fDay = ii;
						lCount = (Days[ii + 1].returnCount() - Days[ii].returnCount());
					}
				}
				cout << "It is now the end of the two weeks! Printing week 2 summaries..." << endl;
				cout << "\n---------------------------------------------"
					<< "\nWeekly summaries for week " << i2 + 1 << ":"
					<< "\nThe sum of all blood sugar readings for this week: " << Weeks[i2].returnSum()
					<< "\nThe maximum blood sugar reading recorded this week: " << Weeks[i2].returnMax() << " mmol/L"
					<< "\nThe minimum blood sugar reading recorded this week: " << Weeks[i2].returnMin() << " mmol/L"
					<< "\nThe number of valid blood sugar readings recorded this week: " << Weeks[i2].returnCount()
					<< "\nThe days with the biggest day to day (count) delta for this week are: \n\t-Day " << fDay + 1 << ", and day " << fDay + 2
					<< ". With a delta of " << lCount << "\n"
					<< "\n---------------------------------------------\n\n" << endl;
				i++, i2++;
			}
		}

		if (input == "Exit" || input == "E" || input == "e")
		{
			// Exit sets i and i2 to the point where the while loop will end.
			i = 14;
			i2 = 2;
		}

		else
		{
			// else: this must be an actual input of blood sugar
			// this stores the value of the string as a number in float num
			// then uses it as arguments for the inputNum function for both the Days and Weeks arrays of of the Data class
			float num = ::atof(input.c_str());
			Days[i].inputNum(num);
			Weeks[i2].inputNum(num);
		}
	}
	system("pause");
	return 0;
}
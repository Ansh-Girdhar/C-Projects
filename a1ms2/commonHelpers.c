// #############################################################################################
//  Assignment: 1 
//  Milestone : 2
// #############################################################################################
//  Name   : Ansh girdhar
//  ID: 152552202
//  Email : agirdhar@myseneca.ca
//  Section : ZDD
// #############################################################################################
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include <time.h>

#include "commonHelpers.h"

int currentYear(void)
{
	time_t currentTime = time(NULL);
	return localtime(&currentTime)->tm_year + 1900;
}
// Function 2: clearStandardInputBuffer
void clearStandardInputBuffer(void)
{
	do
	{
		;
	} while (getchar() != '\n');
}
// Function 3: getInteger
int getInteger(void)
{
	int num = 0;
	char newline = 0;
	
	while (newline != '\n')
	{
		scanf("%d%c", &num, &newline);
		if (newline != '\n')
		{
			clearStandardInputBuffer();
			printf("ERROR: Value must be an integer: ");
		}
	}
	
	return num;
}
// Function 4: getPositiveInteger
int getPositiveInteger(void)
{
	
	int count = 1;
	int positivenum = 0;
	while (count)
	{
		
		positivenum = getInteger();
		
		if (positivenum <= 0)
		{
			printf("ERROR: Value must be a positive integer greater than zero: ");
		}
		
		else
		{
			count = 0;
		}
	}
	return positivenum;
}
// Function 5: getDouble
double getDouble(void)
{
	double double_num = 0.0;
	char newline = 0;
	
	do
	{
		scanf("%lf%c", &double_num, &newline);
		if (newline != '\n')
		{
			clearStandardInputBuffer();
			printf("ERROR: Value must be a double floating-point number: ");
		}
	} while (newline != '\n');
	
	
	return double_num;
}
// Function 6: getPositiveDouble
double getPositiveDouble(void)
{
	double positive_num = 0.0;
	
	int keepvalidating = 1;
	
	while (keepvalidating == 1)
	{
		
		positive_num = getDouble();
		
		if (positive_num > 0)
		{
			keepvalidating = 0;
		}
		
		else
		{
			printf("ERROR: Value must be a positive double floating-point number: ");
		}
	}
	return positive_num;
}
// Function 7: getIntFromRange
int getIntFromRange(int minimum, int maximum)
{
	int range = 0;
	int keep_validating = 1;
	while (keep_validating == 1)
	{
		range = getInteger();
		if (range < minimum || range > maximum)
		{
			printf("ERROR: Value must be between %d and %d inclusive: ", minimum, maximum);
		}
		else
		{
			keep_validating = 0;
		}
	}
	return range;
}
// Function 8: getCharOption
char getCharOption(const char checkString[])
{
	char charac = 0;
	int i = 0;
	int keepvalidating = 1;
	int count = 0;
	char line_check = 0;
	for (i = 0; checkString[i] != '\0'; i++)
	{
		count++;
	}
	while (keepvalidating)
	{
		scanf("%c%c", &charac, &line_check);
		if (line_check == '\n')
		{
			for (i = 0; i < count && keepvalidating; i++)
			{
				if (charac == checkString[i])
				{
					keepvalidating = 0;
				}
			}
			if (keepvalidating)
			{
				printf("ERROR: Character must be one of [%s]: ", checkString);
			}
		}
		else
		{
			printf("ERROR: Character must be one of [%s]: ", checkString);
			clearStandardInputBuffer();
		}
	}
	return charac;
}
// Function 9: getCString
void getCString(char charPointer[], int minstr, int maxstr)
{
	int i = 0, j = 0;
	int count = 0;
	int keepvalidating = 1;
	char inputCString[31];
	do
	{
		scanf("%31[^\n]", inputCString);
		clearStandardInputBuffer();
		count = 0;
		for (i = 0; inputCString[i] != '\0'; i++)
		{
			count++;
		}
		if (count < minstr && (minstr != maxstr))
		{
			printf("ERROR: String length must be between %d and %d chars: ", minstr, maxstr);
		}
		else if (count > maxstr && (minstr != maxstr))
		{
			printf("ERROR: String length must be no more than %d chars: ", maxstr);
		}
		else if ((count <minstr || count> maxstr)
			&& minstr == maxstr)
		{
			printf("ERROR: String length must be exactly %d chars: ",
				minstr);
		}
		else
		{
			for (j = 0; j < count + 1; j++)
			{
				charPointer[j] = inputCString[j];
			}
			keepvalidating = 0;
		}
	} while (keepvalidating);
}
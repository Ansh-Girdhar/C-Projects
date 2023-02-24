/*
	Assignment #1 Milestone #1
	==========================
	Name   : Ansh Girdhar
	ID     : 152552202
	Email  : agirdhar@myseneca.ca
	Section: ZDD
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include "commonHelpers.h"

int currentYear(void)
{
	time_t currentTime = time(NULL);
	return localtime(&currentTime)->tm_year + 1900;
}
void clearStandardInputBuffer(void)
{
	while (getchar() != '\n')
	{
		; // On purpose: do nothing 
	}
}
int getInteger(void)
{
	int number = 0;
	char newline = 0;
	do
	{
		scanf("%d%c", &number, &newline);
		if (newline != '\n')
		{
			clearStandardInputBuffer();
			printf("ERROR: Value must be an integer: ");
		}
	} while (newline != '\n');
	return number;
}

int getPositiveInteger(void)
{
	int value = 0;
	int validate = 1;
	do
	{
		value = getInteger();
		if (value <= 0)
		{
			printf("ERROR: Value must be a positive integer greater than zero: ");
		}
		else
		{
			validate = 0;
		}
	} while (validate == 1);
	return value;
}
double getDouble(void)
{
	double point = 0.0;
	char Newline = 0;
	do
	{
		scanf("%lf%c", &point, &Newline);
		if (Newline != '\n')
		{
			clearStandardInputBuffer();
			printf("ERROR: Value must be a double floating-point number: ");
		}
	} while (Newline != '\n');
	return point;
}
double getPositiveDouble(void)
{
	double pos_point = 0.0;
	int validate = 1;
	do
	{
		pos_point = getDouble();
		if (pos_point <= 0)
		{
			printf("ERROR: Value must be a positive double floating-point number: ");
		}
		else
		{
			validate = 0;
		}
	} while (validate == 1);
	return pos_point;
}
int getIntFromRange(int lowerBound, int upperBound)
{
	int Range = 0;
	int keepgoing = 1;
	do
	{
		Range = getInteger();
		if (Range < lowerBound || Range > upperBound)
		{
			printf("ERROR: Value must be between %d and %d inclusive: ", lowerBound, upperBound);
		}
		else
		{
			keepgoing = 0;
		}
	} while (keepgoing == 1);
	return Range;
}

char getCharOption(const char string[])
{
	char arrchar[10];
	int a = 0;
	int keepgoing = 1;
	int num = 0;
	for (a = 0; string[a] != '\0'; a++)
	{
		num++;
	}
	do
	{
		scanf("%s", arrchar);
		clearStandardInputBuffer();
		for (a = 0; a < num && keepgoing ; a++)
		{
			if (arrchar[0] == string[a] && arrchar[1] == '\0')
			{
				keepgoing = 0;
			}
		}
		
		if (keepgoing)
		{
			printf("ERROR: Character must be one of [%s]: ", string);
		}
	} while (keepgoing == 1);
	
	
	return arrchar[0];
}
void getCString(char* pointer, int minChar, int maxChar)
{
	int i = 0, j = 0;
	int count = 0;
	int keepvalidating = 1;
	char string[31];
	do
	{
		scanf("%30[^\n]", string);
		clearStandardInputBuffer();
		count = 0;
		for (i = 0; string[i] != '\0'; i++)
		{
			count++;
		}
		
		if (count < minChar && (minChar != maxChar))
		{
			
			printf("ERROR: String length must be between %d and %d chars: ", minChar, maxChar);
		
		}
		
		else if ((count <minChar || count>maxChar) && minChar == maxChar)
		{
			
			printf("ERROR: String length must be exactly %d chars: ", minChar);
		
		}
		
		else if (count > maxChar && (minChar != maxChar))
		{
			
			printf("ERROR: String length must be no more than %d chars: ", maxChar);
		
		}
		
		else
		{
			for (j = 0; j < count; j++)
			{
				pointer[j] = string[j];
			}
			pointer[j] = '\0';
			keepvalidating = 0;
		}
	} while (keepvalidating==1);
}
/*
    Name   : Ansh Girdhar
    ID     : 152552204
    Email  : agirdhar@myseneca.ca
    Section: ZDD
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>
#include"commonHelpers.h"

  // Uses the time.h library to obtain current year information
  // Get the current 4-digit year from the system
int currentYear(void)
{
    time_t currentTime = time(NULL);
    return localtime(&currentTime)->tm_year + 1900;
}

// Empty the standard input buffer
void clearStandardInputBuffer(void)
{
    while (getchar() != '\n')
    {
        ; // On purpose: do nothing
    }
}

int getInteger() {
    while (1) {
        int tempInt;
        char tempChar = 'x';
        
        scanf("%d%c", &tempInt, &tempChar);

        
        if (tempChar != '\n') {
            clearStandardInputBuffer();
            printf("ERROR: Value must be an integer: ");
          
        }
        else {
            return tempInt;
        }
    }
}

int getPositiveInteger()
{
    while (1) {
        int tempInt;
        char tempChar = 'x';
        
        scanf("%d%c", &tempInt, &tempChar);

        
        if (tempChar != '\n') {
            clearStandardInputBuffer();
            
            printf("ERROR: Value must be an integer: ");
        }
        else {
            
            if (tempInt > 0) {
                return tempInt;
            }
            else {
                printf("ERROR: Value must be a positive integer greater than zero: ");
                
            }
        }
    }
}

int getIntFromRange(int down, int up) {
    while (1) {
        int tempInt;
        char tempChar = 'x';
        scanf("%d%c", &tempInt, &tempChar);
        if (tempChar != '\n') {
            clearStandardInputBuffer();
            printf("ERROR: Value must be an integer: ");
        }
        else {
            if (tempInt >= down && tempInt <= up) {
                return tempInt;
            }
            else {
                printf("ERROR: Value must be between %d and %d inclusive: ", down, up);
            }
        }
    }
}

double getDouble() {
    while (1) {
        double value;
        char test = 'x';
        scanf("%lf%c", &value, &test);
        if (test != '\n') {
            clearStandardInputBuffer();
            printf("ERROR: Value must be a double floating-point number: ");
        }
        else {
            return value;
        }
    }
}

double getPositiveDouble() {
    while (1) {
        double value;
        char test = 'x';
        scanf("%lf%c", &value, &test);
        if (test != '\n') {
            clearStandardInputBuffer();
            printf("ERROR: Value must be a double floating-point number: ");
        }
        else {
            if (value > 0) {
                return value;
            }
            else {
                printf("ERROR: Value must be a positive double floating-point number: ");
            }
        }
    }
}

char getCharOption(char line[]) 
{
    while (1) 
    {
        char chr;
        char test;
        scanf("%c%c", &chr, &test);
        int keepvalidating = 0;
        int i = 0;

        if (test == '\n') { 
            while (1) {
                if (line[i] == '\0') break;

                if (line[i] == chr) {
                    keepvalidating = 1;
                    break;
                }
                i++;
            }
        }
        else {
            clearStandardInputBuffer();
        }
        if (keepvalidating == 0) {
            printf("ERROR: Character must be one of [%s]: ", line);
        }
        else if (keepvalidating == 1) {
            return chr;
        }
    }
    clearStandardInputBuffer();
}

void getCString(char* chrc, int lowerbound, int upperbound) {
    while (1) {
        char strin[1000];
        scanf("%[^\n]s", strin);

        int i = 0;
        while (strin[i] != '\0') {
            i++;
        }
        if (i >= lowerbound && i <= upperbound) {
            int j = 0;
            for (j = 0; j < i; j++) {
                chrc[j] = strin[j];
            }
            int k = 0;
            while (1) {
                if (k >= i) {
                    if (k <= upperbound) {
                        chrc[k] = '\0';
                    }
                }
                if (k > upperbound) {
                    break;
                }
                k++;
            }
            clearStandardInputBuffer();
            break;
        }
        else {
            if (lowerbound == upperbound) {
                printf("ERROR: String length must be exactly %d chars: ", upperbound);
            }
            else if (i > upperbound)
            {
                printf("ERROR: String length must be no more than %d chars: ", upperbound);
            }
            else {
                printf("ERROR: String length must be between %d and %d chars: ", lowerbound, upperbound);
            }
            clearStandardInputBuffer();
        }
    }
}
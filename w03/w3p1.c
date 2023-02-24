/*
	==================================================
	Workshop #3 (Part-1):
	==================================================
	Name   : Ansh Girdhar
	ID     : 152552202
	Email  : agirdhar@myseneca.ca
	Section: ZDD
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MIN_YEAR 2010
#define MAX_YEAR 2021
int main()
{
	const int JAN = 1;
	const int DEC = 12;
	int user_year = 0, user_month = 0;
	printf("General Well-being Log\n");
	printf("======================\n");
	
	do {
		printf("Set the year and month for the well-being log (YYYY MM): ");
		scanf("%d %d", &user_year, &user_month);
		if (user_year<MIN_YEAR || user_year>MAX_YEAR)
		{
			printf("   ERROR: The year must be between 2010 and 2021 inclusive\n");
			if (user_month < JAN || user_month > DEC)
				printf("   ERROR: Jan.(1) - Dec.(12)\n");
		}
		else if (user_month < JAN || user_month>DEC)
		{
			printf("   ERROR: Jan.(1) - Dec.(12)\n");
		}
	
		else
		{
			printf("\n*** Log date set! ***\n\n");

			switch (user_month)
			{
			case 1:
				printf("Log starting date: %d-JAN-01\n", user_year);
				break;
			case 2:
				printf("Log starting date: %d-FEB-01\n", user_year);
				break;
			case 3:
				printf("Log starting date: %d-MAR-01\n", user_year);
				break;
			case 4:
				printf("Log starting date: %d-APR-01\n", user_year);
				break;
			case 5:
				printf("Log starting date: %d-MAY-01\n", user_year);
				break;
			case 6:
				printf("Log starting date: %d-JUN-01\n", user_year);
				break;
			case 7:
				printf("Log starting date: %d-JUL-01\n", user_year);
				break;
			case 8:
				printf("Log starting date: %d-AUG-01\n", user_year);
				break;
			case 9:
				printf("Log starting date: %d-SEP-01\n", user_year);
				break;
			case 10:
				printf("Log starting date: %d-OCT-01\n", user_year);
				break;
			case 11:
				printf("Log starting date: %d-NOV-01\n", user_year);
				break;
			case 12:
				printf("Log starting date: %d-DEC-01\n", user_year);
				break;
			}
		}



	} while ((user_year < MIN_YEAR || user_year > MAX_YEAR) || (user_month < JAN || user_month > DEC ));
	
	    
		
			
		
	
	return 0;
}
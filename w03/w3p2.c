/*
	==================================================
	Workshop #3 (Part-2):
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
#define LOG_DAYS 3
int main()
{
	const int JAN = 1;
	const int DEC = 12;
	int user_year = 0, user_month = 0;
	int days = 1;
	double morning_rating, evening_rating, tot_mor_rat=0 , tot_eve_rat=0, ove_tot_rat = 0, avg_mor_rat=0, avg_eve_rat=0 , avg_ove_rat=0 ;
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

	} while ((user_year < MIN_YEAR || user_year > MAX_YEAR) || (user_month < JAN || user_month > DEC));
		

			printf("\n*** Log date set! ***\n");



			for (days = 1; days <= LOG_DAYS; days++)
			{


				switch (user_month)
				{
				case 1:
					printf("\n%d-JAN-", user_year);
					break;
				case 2:
					printf("\n%d-FEB-", user_year);
					break;
				case 3:
					printf("\n%d-MAR-", user_year);
					break;
				case 4:
					printf("\n%d-APR-", user_year);
					break;
				case 5:
					printf("\n%d-MAY-", user_year);
					break;
				case 6:
					printf("\n%d-JUN-", user_year);
					break;
				case 7:
					printf("\n%d-JUL-", user_year);
					break;
				case 8:
					printf("\n%d-AUG-", user_year);
					break;
				case 9:
					printf("\n%d-SEP-", user_year);
					break;
				case 10:
					printf("\n%d-OCT-", user_year);
					break;
				case 11:
					printf("\n%d-NOV-", user_year);
					break;
				case 12:
					printf("\n%d-DEC-", user_year);
					break;
				default:
					printf("\nInvalid month");
					break;
				}
				printf("%02d", days);

				do
				{
					printf("\n   Morning rating (0.0-5.0): ");
					scanf("%lf", &morning_rating);
					if (morning_rating < 0 || morning_rating > 5)
					{
						printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!");
					}
				} while (morning_rating < 0 || morning_rating > 5);

				tot_mor_rat += morning_rating;

				do
				{
					printf("   Evening rating (0.0-5.0): ");
					scanf("%lf", &evening_rating);
					if (evening_rating < 0 || evening_rating > 5)
					{
						printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
					}
				} while (evening_rating < 0 || evening_rating > 5);

				tot_eve_rat +=  evening_rating;
			}		
			printf("\nSummary\n");
			printf("=======\n");
			printf("Morning total rating: %.3lf", tot_mor_rat);
		    printf("\nEvening total rating: %.3lf", tot_eve_rat);
			printf("\n----------------------------");

			ove_tot_rat = tot_mor_rat + tot_eve_rat ;
			printf("\nOverall total rating: %.3lf", ove_tot_rat);
			avg_mor_rat = tot_mor_rat / LOG_DAYS;
			avg_eve_rat = tot_eve_rat / LOG_DAYS;
			printf("\n\nAverage morning rating:  %.1lf", avg_mor_rat);
			printf("\nAverage evening rating:  %.1lf", avg_eve_rat);
			printf("\n----------------------------");
			avg_ove_rat = (avg_mor_rat + avg_eve_rat) / 2;
			printf("\nAverage overall rating:  %.1lf\n", avg_ove_rat);
			
	





	return 0;
}
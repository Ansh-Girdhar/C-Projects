/*
	==================================================
	Workshop #4 (Part-1):
	==================================================
	Name   : Ansh Girdhar
	ID     : 152552204
	Email  : agirdhar@myseneca.ca
	Section: ZDD
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_ITEMS 10
int main()
{
	const double MIN_PAY = 500.00, MAX_PAY = 400000.00, MIN_COST = 100;
	double pay, Cost[10], amount, totalpay = 0.0;
	int wishlistitems, j, importance, Priority[10], menu, nprior, months, years;
	double prior1amount = 0, prior2amount = 0, prior3amount = 0;
	char options, Finance_Options[10], finance;
	printf("+--------------------------+\n");
	printf("+   Wish List Forecaster   |\n");
	printf("+--------------------------+\n\n");

	int keepgoing = 1;
	do
	{
		printf("Enter your monthly NET income: $");
		scanf("%lf", &pay);

		if (pay < MIN_PAY)
		{
			printf("ERROR: You must have a consistent monthly income of at least $500.00\n\n");
		}
		else if (pay > MAX_PAY)
		{
			printf("ERROR: Liar! I'll believe you if you enter a value no more than $400000.00\n\n");
		}
		else
		{
			keepgoing = 0;
		}

	} while (keepgoing == 1);

	printf("\n");

	do
	{
		printf("How many wish list items do you want to forecast?: ");
		scanf("%d", &wishlistitems);
		if (wishlistitems < 1 || wishlistitems>MAX_ITEMS) {
			printf("ERROR: List is restricted to between 1 and 10 items.\n\n");
		}

	} while (wishlistitems<1 || wishlistitems>MAX_ITEMS);

	printf("\n");

	for (j = 1; j <= wishlistitems; j++)
	{
		printf("Item-%d Details:\n", j);
		do
		{
			printf("   Item cost: $");
			scanf("%lf", &amount);
			if (amount < MIN_COST)
			{
				printf("      ERROR: Cost must be at least $100.00\n");
			}
			else
			{
				Cost[j] = amount;
			}
		} while (amount < MIN_COST);

		do
		{
			printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
			scanf("%d", &importance);
			if (importance < 1 || importance>3)
			{
				printf("      ERROR: Value must be between 1 and 3\n");
			}
			else {
				Priority[j] = importance;
			}
			if (importance == 1)
			{
				prior1amount += Cost[j];
			}
			else if (importance == 2)
			{
				prior2amount += Cost[j];
			}
			else if (importance == 3)
			{
				prior3amount += Cost[j];
			}
		} while (importance < 1 || importance >3);

		do
		{
			printf("   Does this item have financing options? [y/n]: ");
			scanf("%s", &options);
			if (!(options == 'n' || options == 'y'))
			{
				printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
			}
			else
			{
				Finance_Options[j] = options;
			}

			if (options == 'y')
			{
				finance = Finance_Options[j];
			}

		} while (!(options == 'n' || options == 'y'));
		printf("\n");
	}
	printf("Item Priority Financed        Cost\n");
	printf("---- -------- -------- -----------\n");

	for (j = 1; j <= wishlistitems; j++)
	{
		printf("%3d  %5d    %5c    %11.2lf\n", j, Priority[j], Finance_Options[j], Cost[j]);
		totalpay += Cost[j];
	}
	printf("---- -------- -------- -----------\n");
	printf("                      $%11.2lf\n\n", totalpay);


	do
	{
		printf("How do you want to forecast your wish list?\n");
		printf(" 1. All items (no filter)\n 2. By priority\n 0. Quit/Exit\nSelection: ");
		scanf("%d", &menu);
		if (!(menu == 1 || menu == 2 || menu == 0)) {
			printf("\nERROR: Invalid menu selection.\n");
		}

		if (menu == 1)
		{
			printf("\n====================================================\n");

			printf("Filter:   All items\n");
			printf("Amount:   $%1.2lf\n", totalpay);
			int totalpayperyear;
			totalpayperyear = pay * 12;
			years = totalpay / totalpayperyear;
			months = (int)totalpay % (int)totalpayperyear;
			months = (months / pay) + 1;
			printf("Forecast: %d years, %d months\n", years, months);
			for (j = 1; j <= wishlistitems; j++) {
				if (Finance_Options[j] == 'y') {
					finance = 1;
				}
			}
			if (finance == 1) {
				printf("NOTE: Financing options are available on some items.\n      You can likely reduce the estimated months.");
			}

			printf("\n====================================================\n");
		}

		else if (menu == 2)
		{
			do {
				printf("\nWhat priority do you want to filter by? [1-3]: ");
				scanf("%d", &nprior);
				if (nprior < 1 || nprior>3)
					printf("ERROR: Invalid menu selection.\n");
			} while (nprior < 1 || nprior>3);
			printf("\n====================================================\n");
			printf("Filter:   by priority (%d)\n", nprior);
			if (nprior == 1) {
				printf("Amount:   $%1.2lf\n", prior1amount);
				int totalpayperyear;
				totalpayperyear = pay * 12;
				years = prior1amount / totalpayperyear;
				months = (int)prior1amount % (int)totalpayperyear;
				months = (months / pay) + 1;
				printf("Forecast: %d years, %d months\n", years, months);
				for (j = 1; j <= wishlistitems; j++) {
					if (Finance_Options[j] == 'y') {
						finance = 1;
					}
				}
				if (finance == 1)
				{
					printf("NOTE: Financing options are available on some items.\n      You can likely reduce the estimated months.\n");
				}
			}
			else if (nprior == 2) {
				printf("Amount:   $%1.2lf\n", prior2amount);
				int totalpayperyear;
				totalpayperyear = pay * 12;
				years = prior2amount / totalpayperyear;
				months = (int)prior2amount % (int)totalpayperyear;
				months = (months / pay) + 1;
				printf("Forecast: %d years, %d months\n", years, months);

			}

			else if (nprior == 3) {
				printf("Amount:   $%1.2lf\n", prior3amount);
				int totalpayperyear;
				totalpayperyear = pay * 12;
				years = prior3amount / totalpayperyear;
				months = (int)prior3amount % (int)totalpayperyear;
				months = (months / pay) + 1;
				printf("Forecast: %d years, %d months\n", years, months);

				for (j = 1; j <= wishlistitems; j++) {
					if (Finance_Options[j] == 'y') {
						finance = 1;
					}
				}
				if (finance == 1)
				{
					printf("NOTE: Financing options are available on some items.\n      You can likely reduce the estimated months.\n");
				}
			}


			printf("====================================================\n");
		}

		printf("\n");
	} while (menu != 0);
	printf("Best of luck in all your future endeavours!\n");
	return 0;
}
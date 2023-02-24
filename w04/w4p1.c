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
#define max_items 10
#define min_items 1

int main()
{
	const double min_value = 500.00;
	const long double max_value = 400000.00;
	double monthly_income=0 ;
	int num_items=0;
	int items [max_items] = { 0 };
	double cost[max_items] = { 0.00 };
	int ncost = 0, nfinancing = 0 ,nitems=0 , npriority=0 ;
	int priority[max_items] = { 0 };
	char financing [max_items];
	int i , j   ;
	int important=0;
	double item_cost=0;
	char financing_option;
	double sum_of_cost = 0.0 ;
	
	



	printf("+--------------------------+\n");
	printf("+   Wish List Forecaster   |\n");
	printf("+--------------------------+");
	do
	{
		printf("\n\nEnter your monthly NET income: $");
		scanf( "%lf", &monthly_income);
		if (monthly_income < min_value)
			printf("ERROR: You must have a consistent monthly income of at least $500.00");
		else if (monthly_income > max_value)
			printf("ERROR: Liar! I'll believe you if you enter a value no more than $400000.00");

	} while (monthly_income < min_value || monthly_income > max_value);

	do
	{
		printf("\nHow many wish list items do you want to forecast?: ");
		scanf("%d", &num_items);
		if (num_items < min_items)
			printf("ERROR: List is restricted to between 1 and 10 items.\n");
		else if (num_items > max_items)
			printf("ERROR: List is restricted to between 1 and 10 items.\n");
	} while (num_items < min_items || num_items > max_items);

	for (i = 1; i <= num_items; i++)
	{
		printf("\nItem-%d Details:", i);
		items[nitems++] = i;
		do {
			printf("\n   Item cost: $");
			scanf("%lf", &item_cost);
			if (item_cost < 100)
				printf("      ERROR: Cost must be at least $100.00");
			else
				cost[ncost++] = item_cost;

		} while (item_cost < 100);

		do
		{
			printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
			scanf("%d", &important);
			if (important < 1 || important>3)
				printf("      ERROR: Value must be between 1 and 3\n");
			else
				priority[npriority++] = important;

		} while (important < 1 || important > 3);

		do
		{
			printf("   Does this item have financing options? [y/n]: ");
			scanf(" %c", &financing_option);
			if (financing_option == 'y' || financing_option == 'n')
			{
				financing[nfinancing++] = financing_option;


			}
			else
			{
				printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
			}

		} while (financing_option != 'y' && financing_option != 'n');

	}
		printf("\nItem Priority Financed        Cost");
		printf("\n---- -------- -------- -----------\n");
		for ( j=0 ; j<num_items ; j++ )
		{
		printf("%3d  %5d    %5c    %11.2lf\n", items[j], priority[j], financing[j], cost[j] );
			sum_of_cost += cost[j];
		} 
		printf("---- -------- -------- -----------\n");
		printf("                      $%11.2lf\n\n", sum_of_cost);
		printf("Best of luck in all your future endeavours!\n");
		
	
	
	return 0;

}
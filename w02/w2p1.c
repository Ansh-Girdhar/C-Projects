/*
	==================================================
	Workshop #2 (Part-1):
	==================================================
	Name   : Ansh Girdhar
	ID     : 152552204
	Email  : agirdhar@myseneca.ca
	Section: ZDD
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	double amount;
	printf("Change Maker Machine\n");
	printf("====================\n");
	printf("Enter dollars and cents amount to convert to coins: $");
	scanf("%lf", &amount);
	int toonies,loonies,quarters;
	double retoonies,reloonies,requarters;
	toonies   = amount / 2;
	retoonies = amount - (toonies*2);
	loonies   = amount - (toonies*2) ; 
	reloonies = amount - ((toonies * 2) + loonies);
	quarters  = (amount - ((toonies * 2) + loonies ) )/ 0.25;
	requarters = amount - ((toonies * 2) + loonies + (quarters * 0.25));
	printf("\n$2.00 Toonies  X %d (remaining: $%.2lf)\n", toonies,retoonies );
	printf("$1.00 Loonies  X %d (remaining: $%.2lf)\n", loonies, reloonies );
	printf("$0.25 Quarters X %d (remaining: $%.2lf)\n", quarters, requarters);
	printf("\nMachine error! Thank you for letting me keep $%.2lf!\n",requarters );
	return 0;
}
	


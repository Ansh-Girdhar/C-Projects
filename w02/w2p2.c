/*
	==================================================
	Workshop #2 (Part-2):
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
	double amount, fee,balance,rem ;
	printf("Change Maker Machine\n");
	printf("====================\n");
	printf("Enter dollars and cents amount to convert to coins: $");
	scanf("%lf", &amount);
	fee = amount * 0.05;
	balance = amount - fee;
	printf("Service fee (5.0 percent): %.2lf\n",fee);
	balance = amount - fee;
	printf("Balance to dispense: $%.2lf\n\n", balance);
	int toonies, loonies, quarters, dimes ,nickels, pennies;
	
	toonies = balance / 2;
	rem = balance - (toonies*2);
	printf("$2.00 Toonies  X %d (remaining: $%.2lf)\n", toonies, rem);

	loonies = rem ;
	rem = rem - loonies;
	printf("$1.00 Loonies  X %d (remaining: $%.2lf)\n", loonies, rem);

	rem *= 100;
	quarters = (int)rem / 25;
	rem = (int) rem  % 25;
	rem = rem / 100;
	printf("$0.25 Quarters X %d (remaining: $%.2lf)\n", quarters, rem);

	rem *= 100;
	dimes = (int)rem / 10;
	rem = (int)rem % 10;
	rem = rem / 100;
	printf("$0.10 Dimes    X %d (remaining: $%.2lf)\n", dimes, rem);

	rem *= 100;
	nickels = (int)rem / 5;
	rem = (int)rem % 5;
	rem = rem / 100;
	printf("$0.05 Nickels  X %d (remaining: $%.2lf)\n" ,nickels, rem);

	rem *= 100;
	pennies = (int)rem / 1;
	rem = (int)rem & 1;
	rem = rem / 100;
	printf("$0.01 Pennies  X %d (remaining: $%.2lf)\n\n", pennies, rem);
	printf("All coins dispensed!");
	
	return 0;
}



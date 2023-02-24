/*
    Name   : Ansh Girdhar
    ID     : 152552204
    Email  : agirdhar@myseneca.ca
    Section: ZDD
*/

#define ACCOUNT_TICKETING_UI_H_

#include"account.h"

void applicationStartup(struct Account accounts[], int size);
int menuLogin(const struct Account accounts[], int size);
void menuAgent(struct Account accounts[], int size, const struct Account* account);
int findAccountIndexByAcctNum(int accNoToFind, const struct Account accounts[], int size, int question);
void displayAllAccountDetailRecords(const struct Account accounts[], int size);
void pauseExecution(void);


void displayAccountDetailHeader();
void displayAccountDetailRecord(const struct Account* account);

int getModifyMenuActive();
void setModifyMenuActive(int number);

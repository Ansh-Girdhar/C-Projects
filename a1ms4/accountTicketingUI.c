/*
    Name   : Ansh Girdhar
    ID     : 152552204
    Email  : agirdhar@myseneca.ca
    Section: ZDD
*/

#include"accountTicketingUI.h"
#include<stdio.h>
#include "account.h"
#include"commonHelpers.h"


int index1 = -1;
int modifymenu = 0; 


void applicationStartup(struct Account accounts[], int size) {
 
    while (1)
    {
        if (index1 == -1) { // not logged in
            index1 = menuLogin(accounts, size);
    
        }
        
        else if (index1 == -2) {
            
            printf("\n==============================================\n"
                "Account Ticketing System - Terminated\n"
                "==============================================\n");
            break;
        }
        else {

            printf("\n");
            menuAgent(accounts, size, &accounts[index1]);
        }
    }
}


int menuLogin(const struct Account accounts[], int size) {
    printf("==============================================\n"
        "Account Ticketing System - Login\n"
        "==============================================\n"
        "1) Login to the system\n"
        "0) Exit application\n"
        "----------------------------------------------\n");
    printf("\n");
    printf("Selection: ");
    int choice = getIntFromRange(0, 1);
    printf("\n");
    if (choice == 0) {
        printf("Are you sure you want to exit? ([Y]es|[N]o): ");
        char c = getCharOption("yYnN");
        if (c == 'y' || c == 'Y') {
            return -2;  
           
        }
        else if (c == 'n' || c == 'N') {
            printf("\n");
            return -1;
        }
    }
    else if (choice == 1) { 
        index1 = findAccountIndexByAcctNum(0, accounts, size, 1);
        if (index1 != -1) {
            if (accounts[index1].accountType == 'C') {
                printf("ERROR:  Login failed!\n");
                printf("\n");
                pauseExecution();
                return -1;
            }
            return index1;
        }
        else {
            printf("ERROR:  Login failed!\n");
            printf("\n");
            pauseExecution();
            return -1;
        }
    }
    return -1;
}
void menuAgent(struct Account accounts[], int size, const struct Account* account) {
    while (1) {
        printf("AGENT: %s (%d)", account->person.personName, account->accountNumber);
        
        printf("\n==============================================\n"
            "Account Ticketing System - Agent Menu\n"
            "==============================================\n"
            "1) Add a new account\n"
            "2) Modify an existing account\n"
            "3) Remove an account\n"
            "4) List accounts: detailed view\n"
            "----------------------------------------------\n"
            "0) Logout\n\n"
            "Selection: ");

        
        int choice = getIntFromRange(0, 4);

        printf("\n");
        
        if (choice == 1) {
            
            int tmp = 0;
            int validating = 0;
            for (tmp = 0; tmp < size; tmp++) {
                if (accounts[tmp].accountNumber == 0) {
                    validating = 1;
                    break;
                }
            }
            if (validating == 0) {
                printf("ERROR: Account listing is FULL, call ITS Support!");
            }
            else {
                getAccount(&accounts[tmp]);
                printf("*** New account added! ***\n");
                printf("\n");
                pauseExecution();
            }
        }
        else if (choice == 2) {
            
            
            printf("Enter the account#: ");
            int accno = getPositiveInteger();
            int indexx = findAccountIndexByAcctNum(accno, accounts, size, 0);

            if (indexx != -1) {
              
                setModifyMenuActive(1);
              
                while (modifymenu == 1)
                {
                    updateAccount(&accounts[indexx]);
                }
            }
            else {
                
            }
        }
        else if (choice == 3) {
            
            printf("Enter the account#: ");
            int accountno = getPositiveInteger();

            if (account->accountNumber == accountno)
            { 
                printf("\nERROR: You can't remove your own account!\n\n");
                pauseExecution();
            }
            else 
            {
                int Index = findAccountIndexByAcctNum(accountno, accounts, size, 0);
                if (Index != -1) {
                    displayAccountDetailHeader();
                    displayAccountDetailRecord(&accounts[Index]);

                    printf("\nAre you sure you want to remove this record? ([Y]es|[N]o): ");
                    char opt = getCharOption("YynN");
                    if ( opt == 'y' || opt == 'Y') {
                      
                        accounts[Index].accountNumber = 0;
                        printf("\n*** Account Removed! ***\n\n");
                        pauseExecution();
                    }
                    else {
                      
                    }
                }
                else {
                }
            }
        }
        else if (choice == 4) {
            displayAllAccountDetailRecords(accounts, size);
            printf("\n");
            pauseExecution();
        }
        else if (choice == 0) {
            index1 = -1;
            printf("### LOGGED OUT ###\n\n");
            break;
        }
    }

}
int findAccountIndexByAcctNum(int accNoToFind, const struct Account accounts[], int size, int question) {
    if (question == 1) {
        printf("Enter your account#: ");
        int accno = getPositiveInteger();
        accNoToFind = accno;
    }

    int m = 0;
    int validate = 0;
    for (m = 0; m < size; m++) 
    {
        if (accNoToFind == accounts[m].accountNumber) {
            validate = 1;
            break;
        }
    }

    if (validate == 1) {
        return m;
    }
    else {
        return -1;
    }
}
void displayAllAccountDetailRecords(const struct Account accounts[], int size) {
    displayAccountDetailHeader();
    int index = 0;
    for (index = 0; index < size; index++) {
        if (accounts[index].accountNumber != 0) {
            displayAccountDetailRecord(&accounts[index]);
        }
    }
}

void displayAccountDetailHeader() {
    printf("Acct# Acct.Type Full Name       Birth Income      Country    Login      Password\n");
    printf("----- --------- --------------- ----- ----------- ---------- ---------- --------\n");
}
void displayAccountDetailRecord(const struct Account* account) {
    printf("%05d ", account->accountNumber);
    (account->accountType == 'A') ? printf("%-9s ", "AGENT ") : printf("%-9s ", "CUSTOMER ");
    printf("%-15s ", account->person.personName);
    printf("%5d ", account->person.birthYear);
    printf("%11.2lf ", account->person.householdIncome);
    printf("%-10s ", account->person.country);

    if (account->userLogin.userLoginName[0] != 0) {
        printf("%-10s ", account->userLogin.userLoginName);
        int i = 0;
        for (i = 0; i < 8; i++) {
            if ((i + 1) % 2 == 0) {
                printf("*");
            }
            else {
                printf("%c", account->userLogin.password[i]);
            }
        }
    }
    else {
        printf("%-10s ", "");
        printf("%-8s", "");
    }

    printf("\n");
}



void pauseExecution(void)
{
    printf("<< ENTER key to Continue... >>");
    clearStandardInputBuffer();
    putchar('\n');
}

int getModifyMenuActive() {
    return modifymenu;
}
void setModifyMenuActive(int number) {
    modifymenu = number;
}
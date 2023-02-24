/*
    ==================================================
    Workshop #5 (Part-2):
    ==================================================
    Name   : Ansh Girdhar
    ID     : 152552204
    Email  : agirdhar@myseneca.ca
    Section: ZDD
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define maxlenght 70
#define minlenght 10
#define minlives 1
#define maxlives 10
#define index 5
#define MAX 15
#define MIN 3

typedef struct {
    int totallives;
    char player1;
    int totaltreasure;
    int moves[maxlenght];

}playerInfo;

typedef struct {
    int movenum;
    int pathLength;
    int bombs[maxlenght];
    int treasures[maxlenght];
}gameInfo;


int main() {
    playerInfo player1 = { 0, '\0' , 0 , {0} };
    gameInfo game = { 0 , 0 , {0} , {0} };
    int history[maxlenght] = { 0 };
    int i, j, newmoves = 0, keepalidating = 1;
    printf("================================\n");
    printf("         Treasure Hunt!         \n");
    printf("================================\n\n");
    printf("PLAYER Configuration\n");
    printf("--------------------\n");
    printf("Enter a single character to represent the player: ");
    scanf(" %c", &player1.player1);
    do {
        printf("Set the number of lives: ");
        scanf("%d", &player1.totallives);
        if (player1.totallives > maxlives || player1.totallives < minlives)
            printf("     Must be between %d and %d!\n", minlives, maxlives);
    } while (player1.totallives <minlives || player1.totallives > maxlives);
    printf("Player configuration set-up is complete\n\n");

    printf("GAME Configuration\n");
    printf("------------------\n");

    while (game.pathLength < minlenght || game.pathLength > maxlenght || game.pathLength % index != 0) {
        printf("Set the path length (a multiple of %d between %d-%d): ", index, minlenght, maxlenght);
        scanf("%d", &game.pathLength);
        if (game.pathLength > maxlenght || game.pathLength < minlenght || game.pathLength % 5 != 0)
            printf("     Must be a multiple of %d and between %d-%d!!!\n", index, minlenght, maxlenght);
    }

    while (game.movenum < MIN || game.movenum > MAX) {
        printf("Set the limit for number of moves allowed: ");
        scanf("%d", &game.movenum);
        if (game.movenum < MIN || game.movenum> MAX) {
            printf("    Value must be between %d and %d\n", MIN, MAX);
        }
    }
    int multcount[index] = { 1 ,0 ,0 ,1 ,1 };
    printf("\nBOMB Placement\n");
    printf("--------------\n");

    printf("Enter the bomb positions in sets of 5 where a value\nof 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n(Example:");
    for (i = 0; i < index; i++) {
        printf("%2d", multcount[i]);
    }
    printf(") NOTE: there are 20 to set!\n");
    for (i = 0; i < game.pathLength / index; i++) {
        printf("   Positions [%2d-%2d]: ", i * index + 1, i * index + 5);
        for (j = 0; j < index; j++)
            scanf("%d", &game.bombs[i * index + j]);
    }
    printf("BOMB placement set\n\n");
    printf("TREASURE Placement\n");
    printf("------------------\n");
    printf("Enter the treasure placements in sets of 5 where a value\nof 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n(Example:");
    for (i = 0; i < index; i++) {
        printf("%2d", multcount[i]);
    }
    printf(") NOTE: there are 20 to set!\n");
    for (i = 0; i < game.pathLength / index; i++) {
        printf("   Positions [%2d-%2d]: ", i * index + 1, i * index + 5);
        for (j = 0; j < index; j++)
            scanf("%d", &game.treasures[i * index + j]);
    }
    printf("TREASURE placement set\n\n");
    printf("GAME configuration set-up is complete...\n\n");
    printf("------------------------------------\n");
    printf("TREASURE HUNT Configuration Settings\n");
    printf("------------------------------------\n");
    printf("Player:\n");
    printf("   Symbol     : %c\n", player1.player1);
    printf("   Lives      : %d\n", player1.totallives);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n\n");
    printf("Game:\n");
    printf("   Path Length: %d\n", game.pathLength);
    printf("   Bombs      : ");
    for (i = 0; i < game.pathLength; i++) {

        printf("%d", game.bombs[i]);
    }
    printf("\n");
    printf("   Treasure   : ");
    for (i = 0; i < game.pathLength; i++) {
        printf("%d", game.treasures[i]);
    }
    printf("\n\n====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================\n\n");

    char secondLine[maxlenght] = "";
    printf("  ");
    for (i = 0; i < game.pathLength; i++) {
        secondLine[i] = '-';
        printf("-");
    }
    printf("\n");
    printf("  ");

    for (i = 1; i <= game.pathLength; i++) {
        if (i % 10 == 0)
            printf("%d", (i / 10));
        else
            printf("|");
    }
    printf("\n");
    printf("  ");

    for (i = 1; i <= game.pathLength; i++) {

        printf("%d", (i % 10));
    }
    printf("\n");

    printf("+---------------------------------------------------+\n");
    printf("  Lives:  %d  | Treasures:  %d  |  Moves Remaining: %d\n", player1.totallives, player1.totaltreasure, game.movenum);
    printf("+---------------------------------------------------+\n");

    while (keepalidating) {
        do {
            printf("Next Move [1-%d]: ", game.pathLength);
            scanf("%d", &newmoves);
            if (newmoves > game.pathLength || 1 > newmoves)
                printf("  Out of Range!!!\n");
        } while (newmoves > game.pathLength || 1 > newmoves);
        if (history[newmoves - 1] == 1) {
            printf("\n===============> Dope! You've been here before!\n\n");
            printf("  ");
            for (i = 1; i <= game.pathLength; i++) {
                if (i == newmoves) {
                    printf("%c", player1.player1);
                }
                else printf(" ");
            }

            printf("\n");
            printf("  ");
            for (i = 1; i <= game.pathLength; i++) {
                printf("%c", secondLine[i - 1]);
            }
        }
        else {
            if (game.bombs[newmoves - 1] == 0 && game.treasures[newmoves - 1] == 0) {
                printf("\n===============> [.] ...Nothing found here... [.]\n\n");
            }
            if (game.bombs[newmoves - 1] == 1 && game.treasures[newmoves - 1] == 0) {
                printf("\n===============> [!] !!! BOOOOOM !!! [!]\n\n");
                if (player1.totallives == 1) {
                    printf("No more LIVES remaining!\n\n");
                }
            }
            if (game.bombs[newmoves - 1] == 0 && game.treasures[newmoves - 1] == 1) {
                printf("\n===============> [$] $$$ Found Treasure! $$$ [$]\n\n");
            }
            if (game.bombs[newmoves - 1] == 1 && game.treasures[newmoves - 1] == 1) {
                printf("\n===============> [&] !!! BOOOOOM !!! [&]\n");
                printf("===============> [&] $$$ Life Insurance Payout!!! [&]\n\n");
                if (player1.totallives == 1) {
                    printf("No more LIVES remaining!\n\n");
                }
            }
            game.movenum--;
            history[newmoves - 1] = 1;

            printf("  ");
            for (i = 1; i <= game.pathLength; i++) {
                if (i == newmoves) {
                    printf("%c", player1.player1);
                }
                else printf(" ");
            }
            if (game.bombs[newmoves - 1] == 0 && game.treasures[newmoves - 1] == 0) {
                printf("\n");
                printf("  ");
                for (i = 1; i <= game.pathLength; i++) {
                    if (i == newmoves) {
                        printf(".");
                        secondLine[newmoves - 1] = '.';
                    }
                    else printf("%c", secondLine[i - 1]);
                }
            }
            if (game.bombs[newmoves - 1] == 1 && game.treasures[newmoves - 1] == 0) {
                player1.totallives--;

                printf("\n");
                printf("  ");
                for (i = 1; i <= game.pathLength; i++) {
                    if (i == newmoves) {
                        printf("!");
                        secondLine[newmoves - 1] = '!';
                    }
                    else printf("%c", secondLine[i - 1]);
                }
            }
            if (game.bombs[newmoves - 1] == 0 && game.treasures[newmoves - 1] == 1) {
                player1.totaltreasure += 1;
                printf("\n");
                printf("  ");
                for (i = 1; i <= game.pathLength; i++) {
                    if (i == newmoves) {
                        printf("$");
                        secondLine[newmoves - 1] = '$';
                    }
                    else printf("%c", secondLine[i - 1]);
                }
            }
            if (game.bombs[newmoves - 1] == 1 && game.treasures[newmoves - 1] == 1) {
                player1.totallives--;
                player1.totaltreasure += 1;
                printf("\n");
                printf("  ");
                for (i = 1; i <= game.pathLength; i++) {
                    if (i == newmoves) {
                        printf("&");
                        secondLine[newmoves - 1] = '&';
                    }
                    else printf("%c", secondLine[i - 1]);
                }
            }
        }
        printf("\n");
        printf("  ");
        for (i = 1; i <= game.pathLength; i++) {
            if (i % 10 == 0)
                printf("%d", (i / 10));
            else
                printf("|");
        }

        printf("\n");
        printf("  ");
        for (i = 1; i <= game.pathLength; i++)
            printf("%d", (i % 10));

        printf("\n+---------------------------------------------------+\n");
        printf("  Lives:  %d  | Treasures:  %d  |  Moves Remaining:  %d\n", player1.totallives, player1.totaltreasure, game.movenum);
        printf("+---------------------------------------------------+\n");

        if (player1.totallives == 0) {
            printf("\n##################\n");
            printf("#   Game over!   #\n");
            printf("##################\n\n");
            printf("You should play again and try to beat your score!\n");
            keepalidating = 0;
        }

    }
    return 0;
}



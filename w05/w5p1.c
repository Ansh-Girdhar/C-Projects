/*
	==================================================
	Workshop #5 (Part-1):
	==================================================
	Name   : Ansh Girdhar
	ID     : 152552204
	Email  : agirdhar@myseneca.ca
	Section: ZDD
*/
//
#define _CRT_SECURE_NO_WARNINGS
#define maximum 70

#include<stdio.h>
struct PlayerInfo
{
	int lifelines;
	char player;
	int treasures;
	int historyset[maximum];
};
struct GameInfo
{
	int moves;
	int pathlenght;
	int bombs[maximum];
	int treasures[maximum];
};

int main()
{
	struct PlayerInfo playerinfo;
	
	printf("================================\n");
	printf("         Treasure Hunt!         \n");
	printf("================================\n\n");
	printf("PLAYER Configuration\n");
	printf("--------------------\n");
	printf("Enter a single character to represent the player: ");
	scanf(" %c", &playerinfo.player);
	do
	{
		printf("Set the number of lives: ");
		scanf("%d", &playerinfo.lifelines);
		if (playerinfo.lifelines < 1 || playerinfo.lifelines > 10)
			printf("     Must be between 1 and 10!\n");
	} while (playerinfo.lifelines < 1 || playerinfo.lifelines > 10);
	printf("Player configuration set-up is complete\n\n");
	printf("GAME Configuration\n");
	printf("------------------\n");
	struct GameInfo gameinfo;
	do
	{
		printf("Set the path length (a multiple of 5 between 10-70): ");
		scanf("%d", &gameinfo.pathlenght);
		if ((gameinfo.pathlenght < 10 || gameinfo.pathlenght >70) || !(gameinfo.pathlenght % 5 == 0))
			printf("     Must be a multiple of 5 and between 10-70!!!\n");
	} while((gameinfo.pathlenght < 10 || gameinfo.pathlenght >70) || !(gameinfo.pathlenght % 5 == 0));
	int path;
	path = (75 *gameinfo.pathlenght)/100;
	do
	{
		printf("Set the limit for number of moves allowed: ");
		scanf("%d", &gameinfo.moves);
		if (gameinfo.moves < playerinfo.lifelines || gameinfo.moves > path)
			printf("    Value must be between %d and %d\n", playerinfo.lifelines , path );
	} while (gameinfo.moves < playerinfo.lifelines || gameinfo.moves > path);
	printf("\nBOMB Placement\n");
	printf("--------------\n");
	printf("Enter the bomb positions in sets of 5 where a value\n");
	printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
	printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", gameinfo.pathlenght);
	int i, j;
	for (i = 0; i < gameinfo.pathlenght; i= i + 5)
	{
		printf("   Positions [%2d-%2d]: ", i+1 , i+5 );
			for (j = i; j < i + 5; j++)
			{
				scanf("%d", &gameinfo.bombs[j]);
			}
	}
	
	printf("BOMB placement set\n\n");
	printf("TREASURE Placement\n");
	printf("------------------\n");
	printf("Enter the treasure placements in sets of 5 where a value\n");
	printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.");
	printf("\n(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", gameinfo.pathlenght);
	int k, l;
	for (k = 0; k < gameinfo.pathlenght; k = k + 5)
	{
		printf("   Positions [%2d-%2d]: ", k + 1, k + 5);
		for (l = k; l < k+5 ; l++)
		{
			scanf("%d", &gameinfo.treasures[l]);
		}
	}
	printf("TREASURE placement set\n\n");
	printf("GAME configuration set-up is complete...\n\n");
	printf("------------------------------------\n");
	printf("TREASURE HUNT Configuration Settings\n");
	printf("------------------------------------\n");
	printf("Player:\n");
	printf("   Symbol     : %c\n", playerinfo.player);
	printf("   Lives      : %d\n", playerinfo.lifelines);
	printf("   Treasure   : [ready for gameplay]\n");
	printf("   History    : [ready for gameplay]\n\n");
	printf("Game:\n");
	printf("   Path Length: %d\n", gameinfo.pathlenght);
	printf("   Bombs      : ");
	for (j = 0; j < gameinfo.pathlenght; j++)
	{
		printf( "%d", gameinfo.bombs[j]);
	}
	printf("\n   Treasure   : ");
	for (l=0 ; l < gameinfo.pathlenght ; l++ )
	{
		printf("%d", gameinfo.treasures[l]);
	}
	printf("\n\n====================================\n");
	printf("~ Get ready to play TREASURE HUNT! ~\n");
	printf("====================================\n");


	return 0;

}

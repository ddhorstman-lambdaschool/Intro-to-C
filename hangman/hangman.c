#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int strikes = 0;
char *word;
char HANG_STATES[7][10 * 9] =
	{
		"             +         +----     +----     +----     +----     +----     +----     +----  ",
		"             |         |         |   O     |   O     |   O     |   O     |   O     |   O  ",
		"             |         |         |         |   +     | --+     | --+--   | --+--   | --+--",
		"             |         |         |         |   |     |   |     |   |     |   |     |   |  ",
		"             |         |         |         |         |         |         |  /      |  / \\ ",
		"             |         |         |         |         |         |         |         |      ",
		"/*****\\   /*****\\   /*****\\   /*****\\   /*****\\   /*****\\   /*****\\   /*****\\   /*****\\   "};
void display_hang(int strikes)
{
	int end_idx = (strikes+1)*10;
	int i;
	for (int j = 0; j < 7; j++)
	{
		for (i = strikes * 10; i < end_idx; i++)
			printf("%c", HANG_STATES[j][i]);
		printf("\n");
	}
}
int main(int argc, char *argv[])
{
	word = (char *) malloc(sizeof(*argv[1]));
	strcpy(word,argv[1]);
	while (1)
	{
		printf("%s\n",word);
		scanf("%d", &strikes);
		display_hang(strikes);
		if (strikes == 8)
			break;
	}
	free(word);
	return 0;
}
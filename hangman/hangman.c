#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int strikes = 0;
char *word;
char *guessed;
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
	int i, end_idx = (strikes + 1) * 10;
	for (int j = 0; j < 7; j++)
	{
		for (i = strikes * 10; i < end_idx; i++)
			printf("%c", HANG_STATES[j][i]);
		printf("\n");
	}
}
void init(char *in_word)
{
	word = (char *)malloc(sizeof(*in_word));
	guessed = (char *)malloc(sizeof(*in_word));
	strcpy(word, in_word);
	int i, max = strlen(word);
	//it's necessary to store strlen in an int rather than use it directly
	//in the for loop
	for (i = 0; i < max; i++){
		guessed[i] = '_';
	}
	guessed[i] = '\0';
}
int main(int argc, char *argv[])
{
	init(argv[1]);
	while (1)
	{
		printf("%s\n", guessed);
		scanf("%d", &strikes);
		display_hang(strikes);
		if (strikes == 8)
			break;
	}
	free(word);
	free(guessed);
	return 0;
}
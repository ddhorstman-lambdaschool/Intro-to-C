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
	int len = strlen(in_word);
	word = (char *)malloc(len + 1);
	guessed = (char *)malloc(len + 1);
	memset(word, '\0', len + 1);
	strcpy(word, in_word);
	memset(guessed, '_', len);
	*(guessed + len) = '\0';
}
int main(int argc, char *argv[])
{
	init(argv[1]);
	while (1)
	{
		printf("%s\n", word);
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
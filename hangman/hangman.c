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
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
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
int chkguess(char *guess)
{
	char g = guess[0];
	int correct = 0;
	for (int i = 0; i < strlen(word); i++)
		if (g == word[i])
		{
			correct = 1;
			guessed[i] = g;
		}
	return correct;
}
int main(int argc, char *argv[])
{
	char guess[50];
	init(argv[1]);
	while (1)
	{	
		display_hang(strikes);
		printf("Your word: %s\n", guessed);
		printf("Make a guess: ");
		scanf("%s", &guess);
		strikes += !chkguess(guess);
		if (strikes == 8)
			break;
	}
	free(word);
	free(guessed);
	return 0;
}
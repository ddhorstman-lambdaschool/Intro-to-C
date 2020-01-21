#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
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
void lower(char *str)
{
	for (int i = 0; str[i]; i++)
		str[i] = tolower(str[i]);
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
	lower(word);
	lower(guessed);
}
int chkguess(char *guess)
{
	lower(guess);
	if (strstr(guess, word))
		return -1;

	char g = guess[0];
	int correct = 0;
	for (int i = 0; i < strlen(word); i++)
		if (g == word[i])
		{
			correct++;
			guessed[i] = g;
		}
	return correct;
}
void end_game(int outcome)
{
	if (outcome == 0)
	{
		display_hang(strikes);
		printf("You lose!\nYour word:  %s\nYour guess: %s\n\n", word, guessed);
	}
	if (outcome == 1)
	{
		printf("You win!\n");
	}
	free(word);
	free(guessed);
}
int main(int argc, char *argv[])
{
	char guess[50];
	init(argv[1]);
	int guess_status;
	while (1)
	{
		display_hang(strikes);
		printf("Your word: %s\n", guessed);
		printf("Make a guess: ");
		scanf("%s", &guess);
		guess_status = chkguess(guess);
		if (guess_status == -1)
		{
			end_game(1);
			break;
		}
		else if (guess_status == 0)
			strikes++;
		if (strikes == 8)
		{
			end_game(0);
			break;
		}
	}
	return 0;
}

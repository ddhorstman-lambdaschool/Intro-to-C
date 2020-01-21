#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int strikes = 0;
char *word, *guessed, *wrong_guesses;
char HANG_STATES[7][10 * 9] =
	{
		"             +         +----     +----     +----     +----     +----     +----     +----  ",
		"             |         |         |   O     |   O     |   O     |   O     |   O     |   O  ",
		"             |         |         |         |   +     | --+     | --+--   | --+--   | --+--",
		"             |         |         |         |   |     |   |     |   |     |   |     |   |  ",
		"             |         |         |         |         |         |         |  /      |  / \\ ",
		"             |         |         |         |         |         |         |         |      ",
		"/*****\\   /*****\\   /*****\\   /*****\\   /*****\\   /*****\\   /*****\\   /*****\\   /*****\\   "};

/** Display the correct hangman for the given number of strikes.
 * @param strikes How many incorrect guesses have been made
 */
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

/** Convert a string to lowercase.
 * @param str The string to alter.
 */
void lower(char *str)
{
	for (int i = 0; str[i]; i++)
		str[i] = tolower(str[i]);
}
/** Initialize the hangman program.
 * @param in_word The word to be guessed (from command-line arguments).
 */
void init(char *in_word)
{
	int len = strlen(in_word);

	//Copy input word into word variable, adding null terminator
	word = (char *)malloc(len + 1);
	strcpy(word, in_word);
	word[len] = '\0';

	//Create guessed variable of appropriate length to reveal correctly
	//guessed letters in the word
	guessed = (char *)malloc(len + 1);
	memset(guessed, '_', len);
	guessed[len] = '\0';

	//Create wrong_guesses to store incorrectly-guessed letters
	wrong_guesses = (char *)malloc(26 + 1);
	memset(wrong_guesses, ' ', 26);
	wrong_guesses[26] = '\0';

	//Ensure word is lowercase (for simplicity)
	lower(word);
}
/** Check a guess taken from the console.
 * @param guess The guess typed in (treated as a string).
 * Single-letter and full-word guesses are both acceptable.
 * 
 * @return -1 if the guess wins the game, 0 for an incorrect guess, and 1 for a correct
 * but not game-winning guess.
 */
int chkguess(char *guess)
{
	//Ensure the guess is all lowercase
	lower(guess);

	//If you guessed the whole word, win the game
	if (strstr(guess, word))
		return -1;

	//Extract the first letter of input for single-letter guesses
	char g = guess[0];
	int correct = 0;

	//Look through the word, and reveal any instance of a correctly-guessed letter
	for (int i = 0; i < strlen(word); i++)
		if (g == word[i])
		{
			correct = 1;
			guessed[i] = g;
		}

	//If the guess is now complete, win the game
	if (strstr(guessed, word))
		return -1;

	//If this guess was incorrect, add it to the list of wrong guesses	
	if (!correct)
		wrong_guesses[strikes * 2] = g;

	return correct;
}
/** Finish the game of Hangman.
 * @param outcome 0 for a loss, 1 for a win.
 */
void end(int outcome)
{
	display_hang(strikes);

	//Loss
	if (outcome == 0)
		printf("You lose!\nYour word:  %s\nYour guess: %s\n\n", word, guessed);

	//Win
	if (outcome == 1)
		printf("You win!\nYour word was %s\n\n", word);

	//No memory leaks here!
	free(word);
	free(guessed);
	free(wrong_guesses);
}

int main(int argc, char *argv[])
{
	char guess[50];
	int guess_status;

	//Quit if no word was supplied in the command-line
	if (!argv[1])
	{
		printf("Usage: ./hangman word_to_guess\n");
		return 1;
	}

	//Initialize the game
	init(argv[1]);

	while (1)
	{
		//Display game "board" and info
		display_hang(strikes);
		printf("Your word: %s\n", guessed);
		printf("Doesn't contain: %s\n", wrong_guesses);
		printf("Make a guess: ");

		//Accept guess from command-line and check it
		scanf("%s", &guess);
		guess_status = chkguess(guess);

		//Win the game
		if (guess_status == -1)
		{
			end(1);
			break;
		}

		//Add a strike for an incorrect guess
		else if (guess_status == 0)
		{
			strikes++;
		}

		//Lose the game
		if (strikes == 8)
		{
			end(0);
			break;
		}
	}
	return 0;
}

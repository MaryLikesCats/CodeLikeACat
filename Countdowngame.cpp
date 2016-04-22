// Countdowngame.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include "stdlib.h"
#include "string.h"
#include "time.h"

char getLetters(char letter);
int countCharacters(char *string, char c);
int getOption();
int checkWord();
int getLongestWord();
int getAllWords();

int numWords = 0;
char dictionary[80000][20];

void main(void)
{
	FILE *fptr;
	char fileName[] = "C:\\webster.txt";
	int option = 0;
	int i = 0;
	char typeLetter = 0;
	char selectLetter[10];

	fptr = fopen(fileName, "r");

	if (fptr == NULL)
	{
		printf("File could not be opened !!\n");
		return;
	}
	else
	{
		while (!feof(fptr))
		{

			fscanf(fptr, "%s\n", dictionary[numWords]);
			numWords++;
		}
		fclose(fptr);
	}

	printf("%ld words in the dictionary\n", numWords);

	while (i < 9) 
	{
		selectLetter[i] = 'x';

		fflush(stdin);
		printf("Would you like a vowel or a consonant?\nEnter 'v' for a vowel or 'c' for a constanat\n");
		fflush(stdin);
		scanf("\n%c", &typeLetter);
		fflush(stdin);


		selectLetter[i] = getLetters(typeLetter);
		printf("\n");
		if (selectLetter[i] != 'x')
		{
			for (int j = 0; j < i + 1; j++)
			{
				printf("%c", selectLetter[j]);
				if (i != j)
				{
					printf("_");
				}
			}
			printf("\n");
			i++;
		}


	}




	option = getOption();
	while (option != 0)
	{
		if (option == 1) checkWord();
		if (option == 2) getLongestWord();
		if (option == 3) getAllWords();
		if (option == 0) return;
		option = getOption();
	}
}

int getOption()
{
	int option = 0;

	puts("Options: 1 = Enter your word, 2 = Reveal longest word, 3 = find all possible answers, 0=quit\n");
	fflush(stdin);
	scanf("%d", &option);
	return option;
}

int checkWord()
{
	int i = 0;
	char usersWord[20];

	puts("Enter word to check");
	fflush(stdin);
	scanf("%s", usersWord);

	for (i = 0; i < numWords; i++)
	{
		if (!strcmp(usersWord, dictionary[i]))
		{
			puts("Well Done! Your word is correct!");
			return 1;
		}
	}
	puts("Sorry, not a valid word!");
	return 0;
}

int getAllWords()
{
	char temp[20];
	int numMatches = 0;
	int highestMatch = 0;
	int i = 0, j = 0, len = 0;
	int tempCount = 0, wordCount = 0;

	puts("Enter letters you have");

	scanf("%s", temp);

	puts("\nAll Possible Answers:\n*****************************");

	for (i = 0; i < numWords; i++)
	{
		numMatches = 0;
		len = strlen(dictionary[i]);

		for (j = 0; j < len; j++)
		{
			tempCount = 0;
			wordCount = 0;
			tempCount = countCharacters(temp, dictionary[i][j]);
			wordCount = countCharacters(dictionary[i], dictionary[i][j]);

			if ((tempCount > 0) && (tempCount == wordCount))
			{
				numMatches = numMatches + 1;
			}
			else
			{
				numMatches = 0;
				break;
			}
		}

		if (numMatches == len)
		{
			printf("%s\n", dictionary[i]);
		}
	}



	return numMatches;
}

int getLongestWord()
{
	char bestAnswer[20];
	int numMatches = 0;
	int highestMatch = 0;
	int i = 0, j = 0, len = 0;
	char temp[20];
	int tempCount = 0, wordCount = 0;

	puts("Enter the letters that were generated");

	scanf("%s", temp);

	for (i = 0; i < numWords; i++)
	{
		numMatches = 0;
		len = strlen(dictionary[i]);

		for (j = 0; j < len; j++)
		{
			tempCount = 0;
			wordCount = 0;
			tempCount = countCharacters(temp, dictionary[i][j]);
			wordCount = countCharacters(dictionary[i], dictionary[i][j]);

			if ((tempCount > 0) && (tempCount == wordCount))
			{
				numMatches = numMatches + 1;
			}
			else
			{
				numMatches = 0;
				break;
			}
		}

		if (numMatches > highestMatch)
		{
			strcpy(bestAnswer, dictionary[i]);
			highestMatch = numMatches;
		}
	}

	printf("Best Answer for \"%s\" is \"%s\"  [%d]\n", temp, bestAnswer, highestMatch);

	return numMatches;
}


int countCharacters(char *string, char c)
{
	int i = 0, count = 0, len = 0;
	len = strlen(string);
	for (i = 0; i < len; i++)
	{
		if (string[i] == c) count++;
	}
	return count;
}



char getLetters(char letter)
{

	char select = 0;

	if (letter == 'v')
	{
		int num = rand() % 5;

		if (num == 1)
		{
			select = 'A';
		}
		else if (num == 2)
		{
			select = 'E';
		}
		else if (num == 3)
		{
			select = 'I';
		}
		else if (num == 4)
		{
			select = 'O';
		}
		else
		{
			select = 'U';
		}
	}



	else if (letter == 'c')
	{
		int num = rand() % 21;

		if (num == 1)
		{
			select = 'B';
		}
		else if (num == 2)
		{
			select = 'C';
		}
		else if (num == 3)
		{
			select = 'D';
		}
		else if (num == 4)
		{
			select = 'F';
		}
		else if (num == 5)
		{
			select = 'G';
		}
		else if (num == 6)
		{
			select = 'H';
		}
		else if (num == 7)
		{
			select = 'J';
		}
		else if (num == 8)
		{
			select = 'K';
		}
		else if (num == 9)
		{
			select = 'L';
		}
		else if (num == 10)
		{
			select = 'M';
		}
		else if (num == 11)
		{
			select = 'N';
		}
		else if (num == 12)
		{
			select = 'P';
		}
		else if (num == 13)
		{
			select = 'Q';
		}
		else if (num == 14)
		{
			select = 'R';
		}
		else if (num == 15)
		{
			select = 'S';
		}
		else if (num == 16)
		{
			select = 'T';
		}
		else if (num == 17)
		{
			select = 'V';
		}
		else if (num == 18)
		{
			select = 'W';
		}
		else if (num == 19)
		{
			select = 'X';
		}
		else if (num == 20)
		{
			select = 'Y';
		}
		else {
			select = 'Z';
		}


	}
	else {
		printf("You didn't pick 'v' or 'c'!\n");

		select = 'x';
	}
	return select;
}

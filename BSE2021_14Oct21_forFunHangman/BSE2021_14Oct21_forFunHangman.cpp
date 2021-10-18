#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
using namespace std;

//function prototype
string randWord();
void welcomeMessage();
void guessMessage(int chances);
int drawWinGame();
void drawStartGame();
void drawLoseFirstlife();
void drawLoseSecondlife();
void drawLoseThirdlife();
void drawLoseFourthlife();
void drawLoseFifthlife();
void drawLoseSixthlife();
void drawLoseGame();
void underline();

int main()
{
	//NOTES TO SELF: Understanding how Vectors work (vectors grow and shrink where needed. Arrays can't do that)

	//## This section calls the randWord function to get a random word from the library, then assigns the return value (the random word) to a variable called guessWord
	string guessWord = randWord(); 
	cout << randWord(); //for debugging
	cout << guessWord; //for debugging
	int guessWordSize = guessWord.size(); //checks the size of the returned random word

	//## This section pushes each char in guessWord to a vector called answerArray
	vector<char> answerArray; //defining a vector called answerArray
	for (int i = 0; i < guessWordSize; i++)
	{
		answerArray.push_back(toupper(guessWord[i]));  //each char in the rand word is now an element in the answerArray vector
		cout << answerArray[i]; //for debugging
	}

	welcomeMessage();

	//## This section creates and displays the "_" for all the chars in the random word
	vector<string> guessArray; //defining a vector called guessArray
	//converts chars in guessArray to _ if char, skip if empty char
	for (int i = 0; i < guessWordSize; i++)
	{
		if (isblank(answerArray[i]))
		{
			guessArray.push_back("  ");
			
		}
		else
		{
			guessArray.push_back("_ ");
		}
		cout << guessArray[i];
	}
	
	int chancesLeft = 7; //gives user 7 chances
	//initialising variables to track if letters are guessed in the round, and if the user has found all of the letters
	int lettersLeftToGuess = guessWordSize;
	int lettersNotGuessedInRound = 0;
	int lettersGuessedinRound = 0;

	char inputLetter;

	while (chancesLeft > 0)
	{
		guessMessage(chancesLeft);
		cout << "\nGuess a letter: \n";
		cin >> inputLetter;
		cout << "\n\n\n";
		inputLetter = toupper(inputLetter); //converts all user input to uppercase

		//cycles through the entire random word and compares the input letter with each char in the answerArray
		for (int i = 0; i < guessWordSize; i++)
		{
			//This section helps guessArray display letters that have been guessed
			//if the user input matches, change corresponding char-string in guessArray to the inputLetter
			if (inputLetter == answerArray[i])
			{
				guessArray[i] = inputLetter; 
				lettersGuessedinRound += 1;
			}
			cout << guessArray[i];
		}
		
		//cout << "\nLetters guessed in round = " << lettersGuessedinRound; //for debugging
		if (lettersGuessedinRound == 0)
		{
			chancesLeft -= 1;
			if (chancesLeft != 0)
			{
				cout << "\n\nTry harder. There is no " << inputLetter << " here.\n\n";
			}
		}
		else
		{
			cout << "\n\nCorrect, " << inputLetter << " is one of the letters!\n\n";
			lettersLeftToGuess -= lettersGuessedinRound;
			//checks if there are any letters left to guess
			if (lettersLeftToGuess == 0)
			{
				return drawWinGame(); 
			}

		}
		//cout << "\nLetters left to guess = " << lettersLeftToGuess; //for debugging
		//cout << "\nChances left = " << chancesLeft << endl; //for debugging
		//cout << lettersLeftToGuess << endl; //for debugging

		lettersGuessedinRound = 0; //resets letters guessed to 0 for next round
	}
	drawLoseGame();
	

}

//Welcome message
void welcomeMessage()
{
	underline();
	cout << "WELCOME TO THE NOOSE - Guess the word below\n";
	underline();
	cout << "Hint: TV series\n\n\n";
}

//Messages for guessing and displaying hangman
void guessMessage(int chances)
{
	if (chances == 7)
	{
		drawStartGame();
		underline();
	}
	else if (chances == 6)
	{
		underline();
		drawLoseFirstlife();
		underline();
	}
	else if (chances == 5)
	{
		underline();
		drawLoseSecondlife();
		underline();
	}
	else if (chances == 4)
	{
		underline();
		drawLoseThirdlife();
		underline();
	}
	else if (chances == 3)
	{
		underline();
		drawLoseFourthlife();
		underline();
	}
	else if (chances == 2)
	{
		underline();
		drawLoseFifthlife();
		underline();
	}
	else if (chances == 1)
	{
		underline();
		drawLoseSixthlife();
		underline();
	}
	
}

//function that draws a line when called
void underline()
{
	cout << "\n******************************************************** \n";

}


//functions that draw wins and losses. Need to refine
int drawWinGame()
{
	cout << "\nYOU WIN!!";
	cout << "\n";
	cout << "      O\n";
	cout << "     \\|/\n";
	cout << "      |\n";
	cout << "     / \\\n";
	cout << "       \n";
	cout << "\nYOU WALK FREE";
	return 1;
}

void drawStartGame()
{
	cout << "\n";
	cout << "   ____\n";
	cout << "  |    |\n";
	cout << "  |     \n";
	cout << "  |     \n";
	cout << "  |     \n";
	cout << "  |     \n";
	cout << "  |     \n";
	cout << "  |     \n";
	cout << " ----     \n";
}
void drawLoseFirstlife()
{
	cout << "\n";
	cout << "   ____\n";
	cout << "  |    |\n";
	cout << "  |    O\n";
	cout << "  |     \n";
	cout << "  |     \n";
	cout << "  |     \n";
	cout << "  |     \n";
	cout << "  |     \n";
	cout << " ----     \n";
}
void drawLoseSecondlife()
{
	cout << "\n";
	cout << "   ____\n";
	cout << "  |    |\n";
	cout << "  |    O\n";
	cout << "  |    |\n";
	cout << "  |     \n";
	cout << "  |     \n";
	cout << "  |     \n";
	cout << "  |     \n";
	cout << " ----     \n";
}
void drawLoseThirdlife()
{
	cout << "\n";
	cout << "   ____\n";
	cout << "  |    |\n";
	cout << "  |    O\n";
	cout << "  |   \\|\n";
	cout << "  |     \n";
	cout << "  |     \n";
	cout << "  |     \n";
	cout << "  |     \n";
	cout << " ----     \n";
}
void drawLoseFourthlife()
{
	cout << "\n";
	cout << "   ____\n";
	cout << "  |    |\n";
	cout << "  |    O\n";
	cout << "  |   \\|/\n";
	cout << "  |     \n";
	cout << "  |     \n";
	cout << "  |     \n";
	cout << "  |     \n";
	cout << " ----     \n";
}
void drawLoseFifthlife()
{
	cout << "\n";
	cout << "   ____\n";
	cout << "  |    |\n";
	cout << "  |    O\n";
	cout << "  |   \\|/\n";
	cout << "  |    |\n";
	cout << "  |     \n";
	cout << "  |     \n";
	cout << "  |     \n";
	cout << " ----     \n";
}
void drawLoseSixthlife()
{
	cout << "\n";
	cout << "   ____\n";
	cout << "  |    |\n";
	cout << "  |    O\n";
	cout << "  |   \\|/\n";
	cout << "  |    |\n";
	cout << "  |   /\n";
	cout << "  |     \n";
	cout << "  |     \n";
	cout << " ----     \n";
}

void drawLoseGame()
{
	cout << "\nYOU FAILED.\n";
	cout << "   ____\n";
	cout << "  |    |\n";
	cout << "  |   /|\\\n";
	cout << "  |    |\n";
	cout << "  |   /|\\\n";
	cout << "  |    O\n";
	cout << "  |     \n";
	cout << "  |     \n";
	cout << " ----     \n";
	cout << "\nDIE NOW\n";
}

//This function pulls a random word from a "list"
string randWord()
{
	//Creating a container holding titles from TV Series
	vector<string> tvSeries =
	{
		"Attack On Titan",
		"Mr Robot",
		"Claymore",
		"Desperate Housewives",
		"House"
	};

	//initialising random seed
	srand(time(NULL));
	int i;
	i = rand() % tvSeries.size() + 0;
	/*cout << i;*/ //for debugging
	
	return tvSeries[i];

}

#include "stdafx.h"
#include "FBullCowGame.h"

FBullCowGame::FBullCowGame() { Reset(); };

int32 FBullCowGame::GetMaxTries()const{return MyMaxTries;}
int32 FBullCowGame::GetCurrentTry()const{return MyCurrentTry;}
bool FBullCowGame::IsGameWon() const
{
	return false;
}

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	const FString HIDDEN_WORD = "Kacke";
	MyHiddenWord = HIDDEN_WORD;
	MyMaxTries = MAX_TRIES;
	MyCurrentTry = 1;	
	return;
}

bool FBullCowGame::CheckGuessValitity(FString)
{
	return false;
}

// bring einen validen Versuch zurück, zählt Versuche
FBullCowCount FBullCowGame::SubmitGuess(FString Tip)
{
	// hochzählen der Versuche
	MyCurrentTry++;
	// Setup einer Returnvariablen
	FBullCowCount BullCowCount;
	// loop durch alle Buchstaben im Versuch
	// vergleicht alle Buchstaben mit dem geheimen Wort
	int32 HiddenWordLength = MyHiddenWord.length();
	for (int32 i = 0; i < HiddenWordLength; i++)
	{
		for (int32 j = 0; j < HiddenWordLength; j++)
		{
			if
				(Tip[i] == MyHiddenWord[i])
				if (i == j)
				{
					BullCowCount.Bulls++;
				}
				else 
				{
					//zähle Cows hoch
					BullCowCount.Cows++;
				}
				
			{

			}
		}
	}
	return BullCowCount;
}

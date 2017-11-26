#include "stdafx.h"
#include "FBullCowGame.h"

FBullCowGame::FBullCowGame() { Reset(); };

int32 FBullCowGame::GetMaxTries()const{return MyMaxTries;}
int32 FBullCowGame::GetCurrentTry()const{return MyCurrentTry;}
int32 FBullCowGame::GetHiddenWordLength() const {return MyHiddenWord.length();}
bool FBullCowGame::IsGameWon() const
{
	return false;
}

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	const FString HIDDEN_WORD = "Fernseher";
	MyHiddenWord = HIDDEN_WORD;
	MyMaxTries = MAX_TRIES;
	MyCurrentTry = 1;	
	return;
}

EGuessStatus FBullCowGame::CheckGuessValitity(FString) const
{
	
	if (false) // wenn Wortlänge falsch ist
	{
		return EGuessStatus::Wrong_Length;
	}
	else if (false) // wenn kein Isogramm
	{
		return EGuessStatus::No_Isogramm;
	}
	else if (false)
	{
		return EGuessStatus::Not_Lowercase;
	}
	else
	{
		return EGuessStatus::OK;
	}
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
		for (int32 j = 0; j < HiddenWordLength; j++) {
			// wenn Buchstabe übereinstimmt jedoch nicht die Position
			//wenn Buchstabe und Position übereinstimmt
			if (Tip[i] == MyHiddenWord[j]) //erstmal schauen ob welche übereinstimmen
			{
				if (i == j) // wenn Posi übereinstimmt Bulls
				{
					BullCowCount.Bulls++;
				}
				else // ansonsten Cows
				{
					BullCowCount.Cows++;
				}
			}
		}
	}
	return BullCowCount;
}

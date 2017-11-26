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
	
	if (false) // wenn Wortl�nge falsch ist
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

// bring einen validen Versuch zur�ck, z�hlt Versuche
FBullCowCount FBullCowGame::SubmitGuess(FString Tip)
{
	// hochz�hlen der Versuche
	MyCurrentTry++;
	// Setup einer Returnvariablen
	FBullCowCount BullCowCount;
	// loop durch alle Buchstaben im Versuch
	// vergleicht alle Buchstaben mit dem geheimen Wort
	int32 HiddenWordLength = MyHiddenWord.length();
	for (int32 i = 0; i < HiddenWordLength; i++) 
	{	
		for (int32 j = 0; j < HiddenWordLength; j++) {
			// wenn Buchstabe �bereinstimmt jedoch nicht die Position
			//wenn Buchstabe und Position �bereinstimmt
			if (Tip[i] == MyHiddenWord[j]) //erstmal schauen ob welche �bereinstimmen
			{
				if (i == j) // wenn Posi �bereinstimmt Bulls
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

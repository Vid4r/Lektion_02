#include "stdafx.h"
#include "FBullCowGame.h"
#include <locale>
#include <algorithm>

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
		//wenn Buchstabe und Position �bereinstimmt
		if (Tip[i] == MyHiddenWord[i])
			{
				BullCowCount.Bulls++;
			}	
			for (int32 j = 0; j < HiddenWordLength; j++) 
		  // wenn Buchstabe �bereinstimmt jedoch nicht die Position
				 if (i != j && (Tip[j] == MyHiddenWord[i]))

					{
						//z�hle Cows hoch
						BullCowCount.Cows++;
					}	
	}
	return BullCowCount;
}

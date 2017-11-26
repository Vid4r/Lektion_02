#pragma once
#include <string>

using FString = std::string;
using int32 = int;


// alle Variablen sind mit 0 initialisiert
struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

class FBullCowGame
{
public:
	FBullCowGame();// Constructor
	
	int32 GetMaxTries()const;
	int32 GetCurrentTry()const;
	int32 GetHiddenWordLength() const;
	bool IsGameWon()const;
	bool CheckGuessValitity(FString) const;//ToDo einen besseren R�ckgabewert finden

	void Reset(); // ToDo
	// Methode BullCowCount Z�hlt Bulls und Cows erh�ht die Anzahl der Versuche vorrausgesetzt der Versuch war g�ltig
	FBullCowCount SubmitGuess(FString);
private:
	// werden im Constructor initialisiert
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
	
};
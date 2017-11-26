#pragma once
#include <string>

using FString = std::string;
using int32 = int;

enum class EGuessStatus
{
	OK,
	No_Isogramm,
	Wrong_Length,
	Not_Lowercase
};

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
	EGuessStatus CheckGuessValitity(FString) const;

	void Reset(); // ToDo
	// Methode BullCowCount Zählt Bulls und Cows erhöht die Anzahl der Versuche vorrausgesetzt der Versuch war gültig
	FBullCowCount SubmitGuess(FString);
private:
	// werden im Constructor initialisiert
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
	
};
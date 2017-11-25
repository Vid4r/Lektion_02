#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
void PlayGame();
string GetString();
bool AskToPlayAgain();

//Einstiegspunkt in die Applikation

int main ()
{
	bool bPlayAgain = false;
	do
	{ 
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	} while (bPlayAgain);
	return 0;
}

void PrintIntro() {
	//Vorstellung des Spieles
	constexpr int WORLD_LENGTH = 5;
	cout << "Willkommen zu Bulls und Cows, ein lustiges Wortspiel\n";
	cout << "kannst du das Isogramm aus " << WORLD_LENGTH;
	cout << " Buchstaben erraten??\n";
	cout << endl;
	return;
}
void PlayGame()
{
	//Loop entsprechend der Anzahl der Wiederholungen
	constexpr int ANZAHL_DER_WIEDERHOLUNGEN = 5;
	for (int i = 1; i <= ANZAHL_DER_WIEDERHOLUNGEN; i++)
	{
		string Versuch = GetString();
		cout << "Dein Tip war: " << Versuch << endl;
		cout << endl;
	};
}
string GetString()
{   //Lassen Spiel deer raten
	cout << "Gib hier bitte deinen Tip an\n";
	string Tip = "";
	getline(cin, Tip);
	return Tip;
}
bool AskToPlayAgain()
{
	cout << "Moechtest du nochmal spielen? (J/N)\n";
	string Antwort = "";
	getline(cin, Antwort);
	switch (Antwort[0])
	{
	case 'j':
	case 'J':
		return true;
	default:
		return false;
	}	
}



#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>

#include "day4.h"
#include "profiles.h"
#include "day_playing.h"

using namespace std;

void Day4::Day4Check()
{
	if (Game::input == "LENGTH")
	{
		if (condAtt[2] > 15)
		{
			cout << "Good job, LENGTH does not meet the requirements";
			Game::checkedAtt += Game::input + " ";
			Game::performance += 1;
			Game::canPass = true;
			Sleep(1000);
		}
		else
		{
			cout << "Check failed, LENGTH matches";
			Game::performance -= 1;
			Sleep(1000);
		}
	}
	else if (Game::input == "WEIGHT")
	{
		if (condAtt[4] > 150)
		{
			cout << "Good job, WEIGHT does not meet the requirements";
			Game::checkedAtt += Game::input + " ";
			Game::performance += 1;
			Game::canPass = true;
			Sleep(1000);
		}
		else
		{
			cout << "Check failed, WEIGHT matches requirements";
			Game::performance -= 1;
			Sleep(1000);
		}
	}
}

void Day4::Day4Pass()
{
	cout << "PROCESSING CONTAINER...\n";
	Sleep(800);
	if (condAtt[2] <= 15 && condAtt[4] <= 150)
	{
		Game::canPass = true;
	}
}

//ENDING
void Day4::Day4Ending()
{
	if (Game::specialEnding == true)
	{
		string fileOutput;
		ifstream fileToRead("specialEnding.txt");
		if (fileToRead.fail()) { cout << "File not found"; } //Outputs "File not found" if file does not exist
		while (getline(fileToRead, fileOutput))
		{
			cout << fileOutput << "\n";
			Sleep(900);
		}
		fileToRead.close();
		exit(0);
	}
}
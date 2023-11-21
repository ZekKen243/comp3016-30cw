#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <Windows.h>

#include "profiles.h"
#include "day_start.h"
#include "day_playing.h"

#include "day1.h"
#include "day2.h"
#include "day3.h"
#include "day4.h"

using namespace std;
string Game::input;
string arrayCond[4];
int Game::quota = 0;
int Game::performance = 0;
int Game::warnings = 0;
bool Game::canPass = false;
bool Game::specialEnding = false;

//Prepare the conditions to be checked depending on day
void Game::ConfirmConditions()
{
	Conditions condObj;

	//Determining conditions to be checked depending on day
	switch (Day::day)
	{
	case 1:
		arrayCond[0] = condObj.condition1 = "BATCH";
		arrayCond[1] = condObj.condition2 = "WEIGHT";
		break;
	case 2:
		arrayCond[0] = condObj.condition1 = "BATCH";
		arrayCond[1] = condObj.condition2 = "WEIGHT";
		break;
	case 3:
		arrayCond[0] = condObj.condition1 = "WIDTH";
		arrayCond[1] = condObj.condition2 = "WEIGHT";
		break;
	case 4:
		arrayCond[0] = condObj.condition1 = "LENGTH";
		arrayCond[1] = condObj.condition2 = "WEIGHT";
		break;
	}
}

//Receive user input
void Game::GetUserInput()
{
	cout << "Enter all attributes that crosses the restrictions, then enter PASS to finish.\n";
	cout << "Otherwise enter PASS without entering anything to pass the container.\n\n";
	cout << "Discrepancies noted: " << checkedAtt << "\n\n";
	cin >> input;
	transform(input.begin(), input.end(), input.begin(), ::toupper); //Using transform() as toupper() only works with char

	string* begin = arrayCond;
	string* end = arrayCond + 3;

	if (input == "PASS")
	{
		CheckPass();
		checkedAtt = "";
		Profile::GenerateProfile();
		system("CLS");
	}
	else if (find(begin, end, input) != end)
	{
		Sleep(1000);
		CompareCond();
	}
	else
	{
		cout << "Wrong input/attribute!\n\n";
		Sleep(1000);
		system("CLS");
	}

}

void Game::CompareCond()
{
	switch (Day::day)
	{
	case 1:
		Day1::Day1Check();
		system("CLS");
		break;
	case 2:
		Day2::Day2Check();
		system("CLS");
		break;
	case 3:
		Day3::Day3Check();
		system("CLS");
		break;
	case 4:
		Day4::Day4Check();
		system("CLS");
		break;
	}
}

void Game::CheckPass()
{
	switch (Day::day)
	{
	case 1:
		Day1::Day1Pass();
		break;
	case 2:
		Day2::Day2Pass();
		break;
	case 3:
		Day3::Day3Pass();
		break;
	case 4:
		Day4::Day4Pass();
		break;
	}

	if (canPass == false)
	{
		cout << "YOU HAVE LET A CRATE WITH DISCREPANCY THROUGH, +1 WARNING\n";
		Sleep(1000);
		warnings++;
		if (Day::day == 4)
		{
			specialEnding = true;
		}
	}
	else
	{
		Game::quota++;
	}
	Game::canPass = false;
	
}

void Game::CheckWarnings()
{
	if (warnings >= 5)
	{
		cout << "You have accumulated 5 warnings in total.\n";
		cout << "The company has decided they need to let you go...\n";
		cout << "As they are only looking for those who can do their tasks flawlessly.\n\n";
		cout << "GAME OVER.\n";
		exit(0);
	}
}

void Game::Ending()
{
	if (Day::day == 5)
	{
		string fileOutput;
		ifstream fileToRead("ending.txt");
		if (fileToRead.fail()) { cout << "File not found"; } //Outputs "File not found" if file does not exist
		while (getline(fileToRead, fileOutput))
		{
			cout << fileOutput << "\n";
			Sleep(900);
		}
		fileToRead.close();
		system("Pause");
	}
}


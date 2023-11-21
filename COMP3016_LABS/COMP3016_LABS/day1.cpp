#include <iostream>
#include <Windows.h>

#include "day1.h"
#include "profiles.h"
#include "day_playing.h"

using namespace std;
string Game::checkedAtt;

void Day1::Day1Check()
{
	if (Game::input == "BATCH")
	{
		if (condAtt[0] > 66)
		{
			cout << "Good job, BATCH does not meet the requirements";
			Game::checkedAtt += Game::input + " ";
			Game::performance += 1;
			Game::canPass = true;
			Sleep(1000);
		}
		else
		{
			cout << "Check failed, BATCH matches";
			Game::performance -= 1;
			Sleep(1000);
		}
	}
	else if (Game::input == "WEIGHT")
	{
		if (condAtt[4] > 100)
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

void Day1::Day1Pass()
{
	cout << "PROCESSING CONTAINER...\n";
	Sleep(800);
	if (condAtt[0] <= 66 && condAtt[4] < 100)
	{
		Game::canPass = true;
	}
}
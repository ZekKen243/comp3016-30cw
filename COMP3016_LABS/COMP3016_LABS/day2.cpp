#include <iostream>
#include <Windows.h>

#include "day2.h"
#include "profiles.h"
#include "day_playing.h"

using namespace std;

void Day2::Day2Check()
{
	if (Game::input == "BATCH")
	{
		if (char(condAtt[0]) != 'C')
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
		if (condAtt[4] < 150)
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

void Day2::Day2Pass()
{
	cout << "PROCESSING CONTAINER...\n";
	Sleep(800);
	if (condAtt[0] == 67 && condAtt[4] > 150)
	{
		Game::canPass = true;
	}
}
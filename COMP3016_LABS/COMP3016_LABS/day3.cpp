#include <iostream>
#include <Windows.h>

#include "day3.h"
#include "profiles.h"
#include "day_playing.h"

using namespace std;

void Day3::Day3Check()
{
	if (Game::input == "WIDTH")
	{
		if (condAtt[1] < 10 )
		{
			cout << "Good job, WIDTH does not meet the requirements";
			Game::checkedAtt += Game::input + " ";
			Game::performance += 1;
			Game::canPass = true;
			Sleep(1000);
		}
		else
		{
			cout << "Check failed, WIDTH matches";
			Game::performance -= 1;
			Sleep(1000);
		}
	}
	else if (Game::input == "WEIGHT")
	{
		if (condAtt[4] < 100)
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

void Day3::Day3Pass()
{
	cout << "PROCESSING CONTAINER...\n";
	Sleep(800);
	if (condAtt[1] >= 10 && condAtt[4] >= 100)
	{
		Game::canPass = true;
	}
}
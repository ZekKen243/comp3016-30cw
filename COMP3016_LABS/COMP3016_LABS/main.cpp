#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

#include "main.h"
#include "day_start.h"
#include "profiles.h"
#include "day_playing.h"
#include "day4.h"

using namespace std;
char menuInput;

int main()
{
	//Main game loop
	GameMenu();
	while (Day::day < 5) {
		//Generate story depending on day
		Day::StartingDay();
		Day::DayStory();
		system("pause");
		system("CLS");
		Profile::GenerateProfile();
		while (Game::input != "PASS" || Game::quota != 5) //Main loop will keep executing until quota is reached
		{
			cout << "Current quota: " << Game::quota << "/5\n";
			cout << "Performance points: " << Game::performance << "\n";
			cout << "Warnings: " << Game::warnings <<  "/5\n" "\n\n";
			Day::GetRequirements();
			Profile::ShowProfile();
			Game::ConfirmConditions();
			Game::GetUserInput();
		}
		Day4::Day4Ending();
		Game::CheckWarnings();
		Game::quota = 0;
		Day::day += 1;
		Game::Ending();
	};
}

//Create game menu
void GameMenu()
{
	cout <<
		"   +-------------------+\n"
		"  /|    CONTAINED     /|\n"
		" / |                 / |\n"
		"*--+----------------*  |\n"
		"|  |                |  |\n"
		"|  | [G] Play game  |  |\n"
		"|  +----------------+--+\n"
		"| /  [Q] Quit game  |  /\n"
		"|/                  | /\n"
		"*-------------------*\n"
		;
	
	cin >> menuInput;
	menuInput = toupper(menuInput); //Upper case the input
	if (menuInput == 'G')
	{
		cout << "Starting game...";
		Sleep(500);
		system("CLS");
	}
	else if (menuInput == 'Q')
	{
		cout << "Closing game...";
		exit(0);
	}
	else
	{
		system("CLS");
		GameMenu(); //Loop back to menu if input is not G or Q
	}
}

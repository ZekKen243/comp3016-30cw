#include <iostream>
#include <string>
#include <fstream>
#include <windows.h> //For Sleep()

#include "day_start.h"

using namespace std;
int Day::day = 1;

void Day::StartingDay()
{
	cout << "Day " << day << " is starting...\n\n";
	Sleep(1000);
}

void Day::DayStory()
{
	Story dayObj;
	dayObj.getStory = "day" + to_string(day) + ".txt"; //Prepares a string for relevant txt file to read depending on day

	//Reading day file
	string fileOutput;
	ifstream fileToRead(dayObj.getStory);
	if (fileToRead.fail()) { cout << "File not found"; } //Outputs "File not found" if file does not exist
	while (getline(fileToRead, fileOutput))
	{
		cout << fileOutput << "\n";
		Sleep(900);
	}
	fileToRead.close();
}

//Getting the requirements file for a certain day
void Day::GetRequirements()
{
	cout << "REQUIREMENTS: \n\n";
	StoryReq reqObj;
	reqObj.getReq = "day" + to_string(day) + "Requirements.txt";

	string fileOutput;
	ifstream fileToRead(reqObj.getReq);
	if (fileToRead.fail()) { cout << "File not found"; }
	while (getline(fileToRead, fileOutput))
	{
		cout << fileOutput << "\n";
	}
	fileToRead.close();
}

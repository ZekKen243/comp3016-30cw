#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

#include "profiles.h"

using namespace std;
int condAtt[5];

//Generates a random profile, and stores it into a text file
void Profile::GenerateProfile()
{
	srand(time(NULL)); //Generates new random seed for random values
	CreateProfile pf1;
	pf1.batch = 65 + rand() % 3;
	pf1.width = rand() % 20 + 1;
	pf1.length = rand() % 20 + 1;
	pf1.height = rand() % 5 + 1;
	pf1.weight = rand() % 300 + 1;

	//Stores generated values into an array for later use
	condAtt[0] = { (int)pf1.batch };
	condAtt[1] = { pf1.width };
	condAtt[2] = { pf1.length };
	condAtt[3] = { pf1.height };
	condAtt[4] = { pf1.weight };

	//Writes profile from randomly generated values into txt file
	ofstream pfFile("profileGen.txt");
	if (pfFile.fail()) { cout << "File not found"; }
	pfFile <<
		"PROFILE\n"
		"===================\n"
		<< pf1.batch << " - BATCH\n"
		<< pf1.width << "m - WIDTH\n"
		<< pf1.length << "m - LENGTH\n"
		<< pf1.height << "m - HEIGHT\n"
		<< pf1.weight << "kg - WEIGHT\n"
		"===================\n\n"
		;
	pfFile.close();
}

//Displays profile
void Profile::ShowProfile()
{
	//Reading profiles file
	string fileOutput;
	ifstream fileToRead("profileGen.txt");
	if (fileToRead.fail()) { cout << "File not found"; } //Outputs "File not found" if file does not exist
	while (getline(fileToRead, fileOutput))
	{
		cout << fileOutput << "\n";
	}
	fileToRead.close();
}

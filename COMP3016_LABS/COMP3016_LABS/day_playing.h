#pragma once
#include <iostream>

using namespace std;

namespace Game
{
	extern string input;
	extern string checkedAtt;
	extern int quota;
	extern int performance;
	extern int warnings;
	extern bool specialEnding;
	extern bool canPass;
	void ConfirmConditions();
	void GetUserInput();
	void CompareCond();
	void CheckPass();
	void CheckWarnings();
	void Ending();

	class Conditions
	{
	public:
		string condition1;
		string condition2;
		string condition3;
		string condition4;
	};
	
}
#pragma once
#include <iostream>

using namespace std;

namespace Day
{
	void StartingDay();
	extern int day;
	class Story
	{
	public:
		string dayStory;
		string getStory;
	};
	void DayStory();
	class StoryReq
	{
	public:
		string dayReq;
		string getReq;
	};
	void GetRequirements();
}

#pragma once
#include <iostream>

extern int condAtt[5];

namespace Profile
{
	class CreateProfile
	{
	public:
		char batch;
		int width;
		int length;
		int height;
		int weight;
	};
	void GenerateProfile();
	void ShowProfile();
}
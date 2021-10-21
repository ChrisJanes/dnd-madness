#pragma once

#include <vector>

namespace DieRoller 
{
	struct DiceTokens
	{
		int count{ 0 };
		int face{ 2 };
		int modifier{ 0 };
		int best{ 0 };
	};

	void input_handler(std::vector<DiceTokens>& tokens);
}
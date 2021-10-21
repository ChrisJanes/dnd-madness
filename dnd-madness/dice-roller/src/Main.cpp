#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "../headers/Dice.h"
#include "../headers/UserInput.h"

using namespace DieRoller;

int main() 
{
	std::cout << "dice roller, part of dnd madness\n\n";

	std::cout << "enter the value of dice you want rolled in the format xdy\n"
		<< "where x is the number of dice and y is the number of sides.\n"
		<< "e.g. 1d10 for one 10 sided die or 2d20 for two twenty sided dice.\n"
		<< "or q to quit\n";

	while (true)
	{
		std::vector<int> tokens;

		try
		{
			// do we move this functionality out to Dice instead?
			input_handler(tokens);
		}
		catch (std::exception&)
		{
			// for now, if input_handler throws an exception, we just bail completely
			std::cout << "invalid input provided\n";
			continue;
		}

		if (tokens[0] == -1) break;

		if (tokens.size() < 2)
		{
			std::cout << "error handling input, please try again.\n";
			continue;
		}

		Dice dice;

		// getting here means we've got at least 2 integers stored in tokens.
		// in the short term, we'll only handle the first 2
		// TODO: Allow for different faced die in one roll
		dice.AddDice(tokens[0], tokens[1], tokens[2], tokens[3]);			

		std::vector<DiceRoll> rolls = dice.RollAll();

		for (DiceRoll roll : rolls)
		{
			std::string modsymbol = roll.mod > 0 ? "+" : "";
			std::string modifier = roll.mod != 0 ? modsymbol + std::to_string(roll.mod) : "";
			std::cout << roll.results.size() << "d" << roll.faces << modifier << " roll total: " << roll.total << '\n';
			for (int result : roll.results)
			{
				std::cout << 'd' << roll.faces << ": " << result << '\n';
			}
		}
	}

	return 0;
}
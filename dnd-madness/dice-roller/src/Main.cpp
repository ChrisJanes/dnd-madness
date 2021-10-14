#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "../headers/Dice.h"
#include "../headers/UserInput.h"

int main() {
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
			input_handler(tokens);
		}
		catch (std::exception&)
		{
			// for now, if input_handler throws an exception, we just bail completely
			std::cout << "invalid input provided\n";
			return -1;
		}

		if (tokens[0] == -1) break;

		Dice dice;

		for (int i = 0; i < tokens[0]; ++i)
			dice.AddDie(tokens[1]);

		// getting here means we've got at least 2 integers stored in tokens.
		// in the short term, we'll only handle the first 2
		std::cout << "rolling " << tokens[0] << " d" << tokens[1] << '\n';

		dice.RollAll();
	}

	return 0;
}
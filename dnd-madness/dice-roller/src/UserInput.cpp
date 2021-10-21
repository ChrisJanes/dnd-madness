#include "../headers/UserInput.h"

#include <iostream>
#include <string>
#include <algorithm>

namespace DieRoller
{

	void input_handler(std::vector<int>& tokens)
	{
		std::string input;

		// handle user input
		std::cout << '>';
		std::getline(std::cin, input);

		if (input == "q")
		{
			tokens.push_back(-1);
			return;
		}

		// convert to lower case, just in case we get 1D10 (or whatever)
		// this iterates over each character in the input string and runs
		// std::tolower against it.
		std::transform(input.begin(), input.end(), input.begin(),
			[](unsigned char c) {return std::tolower(c); });

		// we want to break apart the input string to try 
		// and identify the component parts of it
		// the first number is the number of dice to roll
		// then we have a d, followed by the number of sides on the dice
		// "2d6", "1d10" etc. 
		// TODO: handle input that specifies several different dice "1d10 2d10"

		// split the string at the d, if there is no d, we've got bad input.
		const char delimiter = 'd';
		const char split = ' ';
		size_t pos = 0;

		// this loop may be redundant - but we'll refactor it later
		while ((pos = input.find(delimiter)) != std::string::npos) {
			std::string token = input.substr(0, pos);

			// if the token has no size, there was no number present
			// so we're probably dealing with a straight "dy" input
			// and so we can set the number value to 1.
			if (token.size() > 0)
			{
				// std::stoi lets us convert a string to an integer
				// if it doesn't get an integer, it throws an exception
				// we handle that in main (for now)
				tokens.push_back(std::stoi(token));
			}
			else
			{
				tokens.push_back(1);
			}
			// we erase everything up to and including the "d"
			input.erase(0, pos + 1);
		}

		// check for a modifier - at this point, we might have
		// something like "12+4" or "6-2"
		const char plus = '+';
		const char sub = '-';
		int modifier = 0;
		std::string mod;

		// this makes the assumption that there is nothing after the modifier text
		// which is definitely bad form as we're becoming more
		// explicit with regards to how we allow a user to input values.
		if ((pos = input.find(plus)) != std::string::npos)
		{
			mod = input.substr(pos + 1, input.size());
			modifier = std::atoi(mod.c_str());
			//input.erase(pos, input.size());
		}

		if ((pos = input.find(sub)) != std::string::npos)
		{
			mod = input.substr(pos + 1, input.size());
			modifier = -std::atoi(mod.c_str());
			//input.erase(pos, input.size());
		}

		const char bestSymbol = 'b';

		int best = 0;

		if ((pos = input.find(bestSymbol)) != std::string::npos)
		{
			best = std::atoi(input.substr(pos + 1, input.size()).c_str());
			if (best > tokens[0])
				best = tokens[0] - 1;
		}

		// the final part of the input (after the final d) is left behind, so we grab it here.
		tokens.push_back(std::stoi(input));

		tokens.push_back(modifier);
		tokens.push_back(best);
	}
}
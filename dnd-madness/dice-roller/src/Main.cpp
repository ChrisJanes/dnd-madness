#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

void input_handler(std::vector<int> &tokens)
{
	std::string input;

	// handle user input
	std::cout << '>';
	std::cin >> input;

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
	// TODO: handle input that just specifies a single die with "d10"
	// TODO: handle input that specifies several different dice "1d10 2d10"
	// TODO: handle input that adds modifiers to dice rolls "d10+3"
	// TODO: handle partiel results (keep best x) "4d10b3"

	// split the string at the d, if there is no d, we've got bad input.
	char delimiter = 'd';
	size_t pos = 0;

	// this loop may be redundant - but we'll refactor it later
	while ((pos = input.find(delimiter)) != std::string::npos) {
		std::string token = input.substr(0, pos);
		// std::stoi lets us convert a string to an integer
		// if it doesn't get an integer, it throws an exception
		// we handle that in main (for now)
		tokens.push_back(std::stoi(token));
		// we erase everything up to and including the "d"
		input.erase(0, pos + 1);
	}

	// the final part of the input (after the final d) is left behind, so we grab it here.
	tokens.push_back(std::stoi(input));
}

int main() {
	std::cout << "dice roller, part of dnd madness\n\n";

	std::vector<int> tokens;

	try
	{
		std::cout << "enter the value of dice you want rolled in the format xdy\n"
			<< "where x is the number of dice and y is the number of sides.\n"
			<< "e.g. 1d10 for one 10 sided die or 2d20 for two twenty sided dice.\n";
		input_handler(tokens);
	}
	catch(std::exception &e)
	{
		// for now, if input_handler throws an exception, we just bail completely
		std::cout << "invalid input provided\n";
		return -1;
	}

	// getting here means we've got at least 2 integers stored in tokens.
	// in the short term, we'll only handle the first 2
	std::cout << "rolling " << tokens[0] << " d" << tokens[1] << '\n';

	// seed rand so we get relatively random values back out
	srand(time(NULL));

	for (int i = 0; i < tokens[0]; ++i)
	{
		// use rand() to generate a random number - using the mod operator lets us restrict the max result to the dice value
		std::cout << "die " << i + 1 << " rolls: " << rand() % tokens[1] << '\n';
	}

	return 0;
}
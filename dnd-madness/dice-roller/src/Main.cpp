#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
	std::cout << "dice roller, part of dnd madness\n";

	std::string input;

	// handle user input
	std::cin >> input;

	// convert to lower case, just in case we get 1D10 (or whatever)
	std::transform(input.begin(), input.end(), input.begin(),
		[](unsigned char c) {return std::tolower(c); });

	// we want to break apart the input string to try 
	// and identify the component parts of it
	// the first number is the number of dice to roll
	// then we have a d, followed by the number of sides on the dice
	// "2d6", "1d10" etc. 
	// TODO: handle input that just specifies a single die with "d10"

	// split the string at the d, if there is no d, we've got bad input.
	char delimiter = 'd';
	size_t pos = 0;
	std::vector<int> tokens;

	// this loop may be redundant - but we'll refactor it later
	while ((pos = input.find(delimiter)) != std::string::npos) {
		std::string token = input.substr(0, pos);
		// std::stoi lets us convert a string to an integer
		// if it doesn't get an integer, it throws an exception
		// we should handle that.
		tokens.push_back(std::stoi(token));
		// we erase everything up to and including the "d"
		input.erase(0, pos + 1);
	}

	// the final part of the input (after the final d) is left behind, so we grab it here.
	tokens.push_back(std::stoi(input));

	std::cout << tokens[0] << ' ' << tokens[1];

	return 0;
}
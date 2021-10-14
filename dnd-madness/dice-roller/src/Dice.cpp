#include "../headers/Dice.h"

int Die::Roll() {
	// generate a number by calling the distribution and passing it the mersenne generator
	// because the range is inclusive and runs from 1 to max_number, we don't need to worry about
	// adding any extra values here other than the modifier.
	return dist(mt) + modifier;
}

void Dice::AddDie(int max, int mod) {
	// you can't roll a 0 sided dice, so stop that from happening.
	if (max == 0) max = 1;
	dice.push_back(Die(max, mod));
}

void Dice::RollAll() {
	for (Die die : dice)
	{
		std::cout << die.Roll() << '\n';
	}
}
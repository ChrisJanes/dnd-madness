#include "../headers/Dice.h"

namespace DieRoller
{
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

	std::vector<int>  Dice::RollAll() {
		std::vector<int> results;
		for (Die die : dice)
		{
			results.push_back(die.Roll());
		}

		return results;
	}

	std::vector<int> Dice::RollSpecific(int faceLimit)
	{
		std::vector<int> results;
		for (Die die : dice)
		{
			if (die.GetSides() == faceLimit)
				results.push_back(die.Roll());
		}

		return results;
	}
}
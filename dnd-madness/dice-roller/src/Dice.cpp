#include "../headers/Dice.h"

namespace DieRoller
{
	int const Die::Roll() {
		// generate a number by calling the distribution and passing it the mersenne generator
		// because the range is inclusive and runs from 1 to max_number, we don't need to worry about
		// adding any extra values here other than the modifier.
		return dist(mt);
	}

	void Dice::AddDice(int count, int max, int mod) {
		// you can't roll a 0 sided dice, so stop that from happening.
		if (max == 0) max = 2;
		DiceSet set;
		for (int i = 0; i < count; ++i)
			set.dice.push_back(Die(max));
		
		set.modifier = mod;
		dice.push_back(set);
	}

	std::vector<DiceRoll>  Dice::RollAll() {
		std::vector<DiceRoll> rolls;
		for (DiceSet diceSet : dice)
		{
			DiceRoll roll;

			roll.mod = diceSet.modifier;

			for (Die die : diceSet.dice)
			{
				roll.results.push_back({ die.Roll()});
				roll.faces = die.GetSides();
			}

			for (int i = 0; i < roll.results.size(); ++i)
			{
				roll.total += roll.results[i];
			}

			roll.total += diceSet.modifier;

			rolls.push_back(roll);
		}

		return rolls;
	}

	std::vector<DiceRoll> Dice::RollSpecific(int faceLimit)
	{
		std::vector<DiceRoll> rolls;
		for (DiceSet diceSet : dice)
		{
			DiceRoll roll;
			for (Die die : diceSet.dice)
			{
				if (die.GetSides() == faceLimit)
					roll.results.push_back({ die.Roll() });
			}

			for (int i = 0; i < roll.results.size(); ++i)
			{
				roll.total += roll.results[i];
			}

			roll.total += diceSet.modifier;
		}

		return rolls;
	}
}
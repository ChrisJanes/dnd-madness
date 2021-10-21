#include "../headers/Dice.h"

namespace DieRoller
{
	int const Die::Roll() {
		// generate a number by calling the distribution and passing it the mersenne generator
		// because the range is inclusive and runs from 1 to max_number, we don't need to worry about
		// adding any extra values here other than the modifier.
		return dist(mt);
	}

	void Dice::AddDice(int count, int max, int mod, int best) {
		// you can't roll a 0 sided dice, so stop that from happening.
		if (max == 0) max = 2;

		DiceSet set;

		for (int i = 0; i < count; ++i)
			set.dice.push_back(Die(max));
		
		// this might be an error that should be caught
		// at the input stage - but if the best
		// is higher than the number of dice, restrict it.
		if (best >= count)
			best = count - 1;

		set.best = best;
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

			// remove the "worst" results if a best is set.
			if (diceSet.best > 0)
			{
				std::vector<int> sorted(roll.results.size());
				std::partial_sort_copy(roll.results.begin(), roll.results.end(), sorted.begin(), sorted.end(), std::greater<int>());
				int leave = diceSet.dice.size() - diceSet.best;
				sorted.erase(sorted.end() - leave, sorted.end());
				roll.results = sorted;
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
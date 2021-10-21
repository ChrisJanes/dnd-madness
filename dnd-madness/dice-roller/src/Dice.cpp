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

		set.best = best;
		set.modifier = mod;
		dice.push_back(set);
	}

	std::vector<DiceRoll>  Dice::RollAll() {
		std::vector<DiceRoll> rolls;
		// iterate all the dice held in the collection
		for (DiceSet diceSet : dice)
		{
			DiceRoll roll;

			roll.mod = diceSet.modifier;

			// roll each die and store the result
			for (Die die : diceSet.dice)
			{
				roll.results.push_back({ die.Roll()});

				// this is a little redundant, as it sets this value for every die rolled but it only needs to be set once per set
				roll.faces = die.GetSides();
			}

			// remove the "worst" results if a best is set.
			if (diceSet.best > 0)
			{
				std::vector<int> sorted(roll.results.size());
				// partial_sort_copy lets us sort the results vector without modifying it by copying 
				// the resulting sorted values into a new vector, here - sorted.
				// it sorts in ascending order by default, so we have to tell it to use the greater comparator.
				std::partial_sort_copy(roll.results.begin(), roll.results.end(), sorted.begin(), sorted.end(), std::greater<int>());
				
				// figure out how many results to leave behind
				int leave = diceSet.dice.size() - diceSet.best;
				sorted.erase(sorted.end() - leave, sorted.end());
				// replace the list of results with what's left of the sorted values
				roll.results = sorted;
			}

			// tot up the overall result of the set
			for (size_t i = 0; i < roll.results.size(); ++i)
			{
				roll.total += roll.results[i];
			}

			roll.total += diceSet.modifier;

			rolls.push_back(roll);
		}

		return rolls;
	}
}
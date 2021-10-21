#pragma once

#include <iostream>
#include <vector>
#include <random>

namespace DieRoller
{
	struct DiceRoll {
		std::vector<int> results;
		int faces{ 2 };
		int total{ 0 };
		int mod{ 0 };
		int best{ 0 };
	};

	class Die;

	struct DiceSet {
		std::vector<Die> dice;
		int modifier;
		int best;
	};

	// Die represents a single die - it stores the 
	// face value and any associated modifiers.
	class Die
	{
	public:
		Die(int max) : max_number(max) {
			// we seed the mersenne twister with random data from the OS / hardware through random_device.
			mt = std::mt19937((std::random_device())());
			// then we set the min and max values for the distribution
			dist.param(std::uniform_int_distribution<>::param_type(1, max_number));
		}

		int const Roll();
		int GetSides() const { return max_number; };

	private:

		int max_number;

		// used to generated pseudo-random numbers
		// mt19937 is a mersenne twister generator
		// see https://en.wikipedia.org/wiki/Mersenne_Twister for more info
		std::mt19937 mt;
		// a uniform distributor means that any number in the specified range
		// has the same chance of being generated as any other - which is
		// what we want for our dice!
		std::uniform_int_distribution<int> dist;
	};

	// Dice is a set of die - this represents the multitude
	// of dice rolled in one go.
	class Dice
	{
	public:
		void AddDice(int count, int max, int mod = 0, int best = 0);
		std::vector<DiceRoll> RollAll();

	private:
		std::vector<DiceSet> dice;
	};
}
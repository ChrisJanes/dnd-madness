#pragma once

#include <iostream>
#include <vector>
#include <random>

namespace DieRoller
{
	// Die represents a single die - it stores the 
	// face value and any associated modifiers.
	class Die
	{
	public:
		Die(int max, int mod) : max_number(max), modifier(mod) {
			// we seed the mersenne twister with random data from the OS / hardware through random_device.
			mt = std::mt19937((std::random_device())());
			// then we set the min and max values for the distribution
			dist.param(std::uniform_int_distribution<>::param_type(1, max_number));
		}

		int Roll();
		int GetSides() const { return max_number; };

	private:

		int max_number;
		int modifier = 0;

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
		void AddDie(int max, int mod = 0);
		std::vector<int> RollAll();
		std::vector<int> RollSpecific(int faceLimit);

	private:
		std::vector<Die> dice;
	};
}
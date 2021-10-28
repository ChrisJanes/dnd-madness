#include <iostream>

#include "Dice.h"

using namespace DieRoller;

int main()
{
	Dice dice;
	dice.AddDice(1, 6);

	std::cout << dice.RollAll().size();

	return 0;
}
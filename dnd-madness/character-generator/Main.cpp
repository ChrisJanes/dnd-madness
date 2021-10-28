#include <iostream>

#include "headers/Character.h"
#include "headers/Classes.h"
#include "headers/Race.h"

int main()
{
	std::string name;
	std::cout << "Enter the character name\n> ";
	std::cin >> name;

	std::cout << "Enter the character race\n> ";
	std::string race;
	std::cin >> race;

	CharacterGenerator::CharacterClass classDetails{ "Barbarian", 12 };

	CharacterGenerator::Character character(name, classDetails, CharacterGenerator::Race(race));

	std::cout << character;

	return 0;
}
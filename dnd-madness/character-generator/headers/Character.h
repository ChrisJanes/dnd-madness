#pragma once

#include <string>
#include <iostream>

#include "../../dice-roller/headers/Dice.h"

#include "Classes.h"
#include "Race.h"
#include "Stats.h"

namespace CharacterGenerator
{
	enum class Alignment
	{
		LawfulGood,
		NeutralGood,
		ChaoticGood,
		LawfulNeutral,
		Neutral,
		ChaoticNeutral,
		LawfulEvil,
		NeutralEvil,
		ChaoticEvil
	};

	std::string AlignmentToString(const Alignment& a);

	class Character
	{
	public:
		Character(std::string n, CharacterClass c, Race r) 
			: name(n), character_class(c), race(r) 
		{
			DieRoller::Dice stat_dice;
			for (int i = 0; i < 6; ++i)
			{
				stat_dice.AddDice(4, 6, 0, 3);
			}

			auto stat_values = stat_dice.RollAll();

			std::sort(stat_values.begin(), stat_values.end(), [](const DieRoller::DiceRoll& a, const DieRoller::DiceRoll& b)
				{
					return a.total > b.total;
				});

			/*for (auto& rolls : stat_values)
			{
				std::cout << rolls.total << '\n';
				for (auto results : rolls.results)
				{
					std::cout << results << '\t';
				}
				std::cout << '\n';
			}*/

			// 1st level max HP is just the class hit dice value + con mod
			maxHp = c.hit_die + FindModifierForStat(stats.constitution);
			currentHp = maxHp;
		};

		void AssignStat(StatType stat, int value);

		friend std::ostream& operator<< (std::ostream& out, const Character& c);

	private:
		std::string name;
		CharacterClass character_class;
		int level{ 1 };
		int xp{ 0 };
		Race race;
		Alignment alignment{ Alignment::Neutral };

		StatBlock stats{ 15, 14, 13, 12, 10, 8 };

		int maxHp{ 0 };
		int currentHp{ 0 };
		int tempHp{ 0 };
	};
}
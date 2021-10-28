#pragma once

#include <iostream>

namespace CharacterGenerator
{
	enum class StatType {
		Strength,
		Dexterity,
		Constitution,
		Intelligence,
		Wisdom,
		Charisma
	};

	struct StatBlock
	{
		int strength;
		int dexterity;
		int constitution;
		int intelligence;
		int wisdom;
		int charisma;
	};

	std::ostream& operator<<(std::ostream& out, const StatBlock& stats);

	int FindModifierForStat(int statValue);
}
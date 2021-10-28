#pragma once

#include "Stats.h"

namespace CharacterGenerator
{
	struct CharacterClass
	{
		std::string name;
		int hit_die{ 6 };
		StatType primary{ StatType::Strength };
		StatType saves[2] = { StatType::Strength, StatType::Charisma };
	};
}
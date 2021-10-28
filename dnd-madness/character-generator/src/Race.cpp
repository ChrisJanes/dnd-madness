#include "../headers/Race.h"

namespace CharacterGenerator
{
	int Race::GetAbilityModifier(StatType stat)
	{
		switch (stat)
		{
		case StatType::Strength:
			return modifiers.strength;
		case StatType::Dexterity:
			return modifiers.dexterity;
		case StatType::Constitution:
			return modifiers.constitution;
		case StatType::Intelligence:
			return modifiers.intelligence;
		case StatType::Wisdom:
			return modifiers.wisdom;
		case StatType::Charisma:
			return modifiers.charisma;
		}

		return 0;
	}
}
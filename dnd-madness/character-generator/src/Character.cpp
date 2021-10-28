#include "../headers/Character.h"

namespace CharacterGenerator
{
	std::string AlignmentToString(const Alignment& a)
	{
		switch (a)
		{
		case CharacterGenerator::Alignment::LawfulGood:
			return "Lawful Good";
		case CharacterGenerator::Alignment::NeutralGood:
			return "Neutral Good";
		case CharacterGenerator::Alignment::ChaoticGood:
			return "Chaotic Good";
		case CharacterGenerator::Alignment::LawfulNeutral:
			return "Lawful Neutral";
		case CharacterGenerator::Alignment::Neutral:
			return "Neutral";
		case CharacterGenerator::Alignment::ChaoticNeutral:
			return "Chaotic Neutral";
		case CharacterGenerator::Alignment::LawfulEvil:
			return "Lawful Evil";
		case CharacterGenerator::Alignment::NeutralEvil:
			return "Neutral Evil";
		case CharacterGenerator::Alignment::ChaoticEvil:
			return "Chaotic Evil";
		}
	}

	std::ostream& operator<<(std::ostream& out, const Character& c)
	{
		return out << c.name << " the " << c.character_class.name << '\n' 
				   << AlignmentToString(c.alignment) << '\n'
				   << c.stats;
	}

	void Character::AssignStat(StatType stat, int value)
	{
		switch (stat)
		{
		case StatType::Strength:
			stats.strength = value;
			break;
		case StatType::Dexterity:
			stats.dexterity = value;
			break;
		case StatType::Constitution:
			stats.constitution = value;
			break;
		case StatType::Intelligence:
			stats.intelligence = value;
			break;
		case StatType::Wisdom:
			stats.wisdom = value;
			break;
		case StatType::Charisma:
			stats.charisma = value;
			break;
		}
	}
}

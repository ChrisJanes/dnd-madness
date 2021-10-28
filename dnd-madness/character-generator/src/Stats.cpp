#include "../headers/Stats.h"

#include <math.h>

namespace CharacterGenerator
{
	std::ostream& operator<<(std::ostream& out, const StatBlock& stats)
	{
		{
			return out << "Strength: " << stats.strength << '\n'
				<< "Dexterity: " << stats.dexterity << '\n'
				<< "Constitution: " << stats.constitution << '\n'
				<< "Intelligence: " << stats.intelligence << '\n'
				<< "Wisdom: " << stats.wisdom << '\n'
				<< "Charisma: " << stats.charisma << '\n';
		}
	}

	int FindModifierForStat(int statValue)
	{	
		return (int)floor((statValue - 10) / 2);
	}
}
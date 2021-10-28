#pragma once

#include "Stats.h"
#include <string>

namespace CharacterGenerator
{
	class Race 
	{
	public:
		Race(std::string n) : name(n) {};
		int GetAbilityModifier(StatType stat);
		std::string GetName() { return name; }
	private:
		StatBlock modifiers{ 0,0,0,0,0,0 };
		std::string name;
	};
}
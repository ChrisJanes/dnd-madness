# DnD Madness

[![MSBuild](https://github.com/ChrisJanes/dnd-madness/actions/workflows/msbuild.yml/badge.svg)](https://github.com/ChrisJanes/dnd-madness/actions/workflows/msbuild.yml)

A collection(-ish) of vaguely dnd related code projects.

The repository contains one Visual Studio solution, [dnd-madness.sln](dnd-madness/dnd-madness.sln), that hosts
the following projects:

## Dice :game_die: Roller 
Provides functionality to "roll" user specified numbers of :game_die:
* user enters 2d6
	* application returns "1 and 3"
* user enters 3d10, 2d6
	* application returns "1, 5 and 10 and 2 and 4".
* allow for modifiers (2d6+4)
* partial results (4d6, keep best 3 - 4d6b3)
* specify a re-roll value that will trigger another roll if not met (4d6r2 would re-roll all dice that showed 2 or less).

## Character Generator
Generates a character based on a set of stats.
* Reads and Writes to a character file
* Uses Dice Roller to set stat values
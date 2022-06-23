#include "luanics/testing/tutorial.hpp" // This imports some code that we wrote

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <type_traits> // This imports some code that is part of the standard C++ library
#include <unordered_map>

using namespace luanics;
using namespace std;

BEGIN_CHAPTER(Statements)

// * Statements are commands for the computer.
// * C++ programs are composed of a sequence of statements.
// * Statements are executed (no value), expressions are evaluated (value).
// * Most, but not all, statements end with a semicolon.
// * All whitespace is treated equally, and consecutive whitespaces are effectively collapsed.
// * There are roughly five categories of statement:
//   * expression statement is an expression followed by a semicolon
//   * declaration statement introduces a name and associates it with an entity
//   * compound statement is a group of statements in curly braces
//   * control flow statements redirect the flow of execution, e.g., for-statement and if-statement
//   * try-block statement is used for exception handling
// * The one-definition rule (ODR) says that an entity may have multiple declarations, but only one definition per translation unit.
// * Don't confuse initialization (using '='), assignment (using '='), and equality comparison (using '==').

SECTION(DeclarationStatements) {
	// Here we define and initialize two variables.
	// Fix the initialization to pass the test. There is more than one way to fix.
	int num_blows = FIX(3);
	int damage_per_blow = FIX(5);
	int const total_damage = num_blows * damage_per_blow;
	EXPECT_EQ(14, total_damage);
}

SECTION(OneDefinitionRule) {
	// To see ODR in action, uncomment the following line and try building.
	// You'll get an ODR error because the variable "unicorn" is defined twice.
	// Once you've seen the build error, replace the comment and move on.
//	#define IS_ACTIVE
	#ifdef IS_ACTIVE
		int unicorn;
		int unicorn;
	#endif
	#undef IS_ACTIVE
	EXPECT_REACHED();
}

int good_roll() {return 20;}
int bad_roll() {return 1;}

SECTION(ExpressionStatements) {
	int roll = 6; // (variable) definition statement with initialization - not assignment.
	roll = FIX(5); // assignment statement changes the value of "roll"
	EXPECT_EQ(roll, 2);

	// Another useful expression is the function call
	roll = FIX(bad_roll()); // assignment and function call
	EXPECT_EQ(roll, 20);

	// Don't confuse assignment (=) with equality comparison (==)
	if (roll FIX(=) 1) {
		EXPECT_NOT_REACHED();
	}
	roll FIX(==) 19;
	EXPECT_EQ(19, roll);
}

SECTION(SelectionStatements) {
	// The simplest selection statement is the "if statement".

	// Here we give a bonus if a condition is met:
	int reward = 100;
	bool is_dungeon_clean = true;
	if (is_dungeon_clean)
		reward = reward + 10;
	EXPECT_EQ(FIX(100), reward);

	// Kickin' it up a notch, the if-else statement selects one of two options.
	reward = 100;
	is_dungeon_clean = false;
	if (is_dungeon_clean)
		reward = reward + 10;
	else
		CREATE ;
	EXPECT_EQ(90, reward);
}

SECTION(IterationStatements) {
	// The workhorse of iteration statements is the "for loop".
	int base_roll = 15;
	int modified_roll = base_roll;
	std::vector<int> roll_modifiers{+1, -2, +3};
	for (int i = 0; i < 3; ++i)
		modified_roll += roll_modifiers[i];
	EXPECT_EQ(FIX(15), modified_roll)

	std::string name;
	// Try skipping by 2 instead of 1...
	for (char ch = 'a'; ch <= 'e'; ch = ch + FIX(1))
		name += ch;
	EXPECT_EQ("ace", name);
}

SECTION(CompoundStatements) {
	// if statements can make use of compound statements, i.e, {}
	int reputation = 1000;
	int gold = 100;
	if (true) { // begin compound statement
		CREATE 
	} // end compound statement
	EXPECT_EQ(reputation, 900);
	EXPECT_EQ(gold, 110);
}

SECTION(TryBlockStatements) {
	// try-blocks are used for exception handling
	bool is_everything_ok= true;
	try {
		std::string thoughts = "Hum, dee, hum, dee, hum...";
		throw std::runtime_error("Oh, No!!!");
	}
	catch (...) {
		CREATE 
	}
	EXPECT_FALSE(is_everything_ok);
}

SECTION(BewareDopplegangers) {
	// Change (add or remove) one character in the following code to make it pass.
	int num_puzzles_solved{0};
	if (num_puzzles_solved = 0) {
		++num_puzzles_solved;
	}
	EXPECT_EQ(1, num_puzzles_solved);
}

END_CHAPTER(Statements)

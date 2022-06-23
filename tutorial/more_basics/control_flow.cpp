#include "luanics/testing/tutorial.hpp"

BEGIN_CHAPTER(ControlFlow)

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
//
//	Control Flow
//
// * "Control flow" is the path (flow) of execution.
// * Control flow types are "sequential", "selection" and "iteration" and "jump".
// * Sequential is default control flow - each statement executed consecutively.
// * Use a control flow statement to alter control flow from sequential.
// * Selection control flow statements include "if-else" and "switch".
// * Iteration control flow statements include "for", "while", and "do-while".
//
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

// Sequential is default control flow
SECTION(Sequential) {
	// Obviously, executing these statements in a non-sequential order would
	//  change the result.
	int x = 2;
	x += 2;
	x *= 5;
	x /= 2;
	EXPECT_EQ(FIX(0), x);
}

// "If" is the workhorse of selection control statements.
SECTION(If) {
	bool is_ac_on = false;
	double temp = 90.0;
	if (temp > 75) {
		CREATE 
	}
	EXPECT_TRUE(is_ac_on);
}

// "If-Else" is a bit fancier
SECTION(IfElse) {
	bool likes_garlic = true;
	std::string team("vampire");
	if (likes_garlic) {
		team.insert(0, "is not ");
	}
	else {
		team.insert(0, "is ");
	}
	EXPECT_EQ("is or is not vampire", team);
}

// The queen of ifs
SECTION(IfElseIf) {
	int ac_level = 0;
	double const temperature = 22.2;
	if (temperature < 20.) {
		ac_level = 0;
	}
	else if (temperature < 25.) {
		ac_level = 1;
	}
	else if (temperature < 30.) {
		ac_level = 2;
	}
	else {
		ac_level = 3;
	}
	EXPECT_EQ(FIX(0), ac_level);
}

// The "ternary operator", "?", provides selection between two alternatives.
SECTION(Ternary) {
	bool likes_garlic = FIX(false);
	std::string team = likes_garlic ? "Jacob" : "Edward";
	EXPECT_EQ("Jacob", team);
}

// Switch chooses between integral options, with a "default" catch-all
SECTION(Switch) {
	unsigned const num_times_fooled = FIX(1);
	std::string shamee;
	switch (num_times_fooled) {
		case 0: shamee = "no one"; break;
		case 1: shamee = "you"; break;
		case 2: shamee = "me"; break;
		case 3: shamee = "my parents"; break;
		default: shamee = "evolution"; break;
	}
	EXPECT_EQ("my parents", shamee);
}

// Without a "break" or "return" statement, control "falls through" to the
//  next case...
SECTION(SwitchFallThrough) {
	unsigned const number_grade = 4;
	char letter_grade;
	switch (number_grade) {
		case 0:
		case 1:
		case 2:
		case 3:
		case 4:
		case 5: letter_grade = 'F'; break;
		case 6: letter_grade = 'D'; break;
		case 7: letter_grade = 'C'; break;
		case 8: letter_grade = 'B'; break;
		case 9: case 10: letter_grade = 'A'; break;
		default: letter_grade = '?'; break;
	}
	EXPECT_EQ(FIX('?'), letter_grade);
}

SECTION(For) {
	int sum = 0;
	for (int i = 0; i < FIX(6); ++i) {
		sum += i;
	}
	EXPECT_EQ(10, sum);
}

SECTION(RangeFor) {
	// Range based for loops
	std::string chords[] = {
		"Bmaj7","D7","Gmaj7","Bb7","Ebmaj7",
		"Amin7","D7",
		"Gmaj7","Bb7","Ebmaj7","F#7","Bmaj7"
	};
	std::string target = "Gmaj7";
	int num_matches = 0;
	for (std::string const & chord: chords) {
		if (chord == target) ++num_matches;
	}
	EXPECT_EQ(FIX(0), num_matches);
}

// for loop is useful when working with a pre-existing sequence (1 to n, first element to last, etc...)
// while loop covers most of the other cases
SECTION(While) {
	// Let's say we're reading from an io device or buffer
	int remaining_reads = 15; // This is usually not exposed
	while (remaining_reads > 0) {
		// Do the reading, which has this side effect...
		--remaining_reads;
	}
	EXPECT_EQ(FIX(15), remaining_reads);
}

// For the Book - explain for is the typical choice


// do-while loop is useful when you'll have to iterate at least once.
SECTION(DoWhile) {
	char const userInputs[] = {'y', 'y', 'n'};
	char const * inputPtr = userInputs;
	unsigned numIterations = 0;
	do {
		++numIterations;
		// Pretend we're interacting with user here... "do you want to continue?"
	}
	while (*inputPtr++ == 'y');
	EXPECT_EQ(FIX(3), numIterations);
}

// * Challenge
// * A dog's first year is equivalent to fifteen human years
// * A dog's second year is equivalent to nine human years
// * Each year after second is equivalent to five human years
double dog_years_to_human_years(double const dog_years) {
	CREATE
	return 0;
	
}

// Have them fill in guts of a couple of functions

SECTION(DogYears) {
	EXPECT_EQ(0., dog_years_to_human_years(0.));
	EXPECT_EQ(7.5, dog_years_to_human_years(0.5));
	EXPECT_EQ(15., dog_years_to_human_years(1.));
	EXPECT_EQ(19.5, dog_years_to_human_years(1.5));
	EXPECT_EQ(24., dog_years_to_human_years(2.));
	EXPECT_EQ(29., dog_years_to_human_years(3.));
}

END_CHAPTER(ControlFlow)

#include "luanics/testing/tutorial.hpp" // This imports some code that we wrote

#include <cstring>
#include <string>

BEGIN_CHAPTER(Directives)

// * Directives are commands for the preprocessor.
// * There are roughly five categories of directive:
//   * text replacement - macros
//   * text selection - conditional compilation
//   * text insertion - #include
//   * compiler error - #error
//   * compiler specific - #pragma
// * #define introduces macro directives, #undef removes them.
// * Object-like macros replace the macro name with the body.
// * Function-like macros replace macro name with body, while substituting in arguments.
// * To make macros place nice, use parens twice.
// * Prefer variables and functions to macros.
// * Inside a macro body, # does stringizing while ## does token pasting.
// * Predefined macros like __FILE__ insert information about the context.
// * To avoid collision between libraries, macro names should be prefixed with the name of the library.

SECTION(Macros) {
	// * #define introduces macro directives, #undefine removes them.
	// * Object-like macros replace the macro name with the body.
	// * Function-like macros replace macro name with body, while substituting in arguments.

	// Start by fixing the object-like macro, LEVEL
	#define LEVEL FIX(10)
	EXPECT_EQ(11, LEVEL)
	#undef LEVEL // cleanup

	// Now try an object-like macro, SCALE(x), that does 2*x + 1
	#define SCALE(x) FIX(0)
	EXPECT_EQ(SCALE(1), 3)
	EXPECT_EQ(SCALE(2), 5)
}

SECTION(MacroPitfalls) {
	// * To make macros place nice, use parens twice.
	// For example
	#define DOUBLE(x) (2*(x))
	#undef DOUBLE

	// Did you remember the extra parens when defining SCALE(x) above?
	// In Eclipse, use Ctrl+# to see the macro expansion.
	EXPECT_EQ(15, SCALE(1)*SCALE(2))
	EXPECT_EQ(5, SCALE(1+1))
}

SECTION(PreprocessorOperators) {
	// * Inside a macro body, # does stringizing while ## does token pasting.
	// So, with this definition
	// #define STRINGIZE(x) #x
	// we find that
	// STRINGIZE(hi)
	// is replaced with "hi"

	// The preprocessor will join adjacent string literals, like
	//  "x" "y"
	//  into a single string literal, like
	//  "xy"
	// Define a function-like macro called PIG_LATINATE(x) that stringizes
	//  x with the string "nay" appended
	#define PIG_LATINATE(x) FIX(#x)
	EXPECT_EQ(0, std::strcmp("hinay", PIG_LATINATE(hi)))

	// Define a function-like macro called STRINGIZE_2(x,y) that stringizes
	//  the arguments together.
	#define STRINGIZE_2(x,y) FIX("")
	EXPECT_EQ(0, std::strcmp("hithere", STRINGIZE_2(hi,there)))

	// The token pasting operator, ##, lets us combine our parameter with a non-parameter token
	//  to produce a name (not string).
	int value = 1;
	int better_value = 2;
	#define MAKE_VALUE(x) FIX(value)
	EXPECT_EQ(2, MAKE_VALUE(better));
}

SECTION(StandardPredefinedMacros) {
	// Use the __LINE__, __FILE__ and __cplusplus macros to initialize the variables
	auto const line = FIX(0);
	EXPECT_GT(line, 0);
	auto const file_name = FIX("file");
	EXPECT_GT(std::strlen(file_name), 5);
	auto const cpp_version = FIX(0);
	EXPECT_GT(cpp_version, 201103L);
}

SECTION(ConditionalCompilation) {
	// Use a preprocessor directive to define the macro LOVE
	CREATE

	#ifdef LOVE
		EXPECT_REACHED();
	#else
		EXPECT_NOT_REACHED();
	#endif

	// Now use a preprocessor directive to "cleanup" and undefine LOVE
	CREATE

	#ifndef LOVE
		EXPECT_REACHED();
	#else
		EXPECT_NOT_REACHED();
	#endif
}

END_CHAPTER(Directives)

#include "luanics/meta/expression_analysis.hpp"
#include "luanics/testing/tutorial.hpp"

#include <type_traits>

BEGIN_CHAPTER(Expressions)

SECTION(AnalyzingExpressions) {
	int x = 1;
	int const y = 2;
	int const & z = x;

	// From Introspection.cpp: Variable names as identifiers
	EXPECT_TRUE((std::is_same<FIX(bool), decltype(x)>::value));
	EXPECT_TRUE((std::is_same<FIX(bool), decltype(y)>::value));
	EXPECT_TRUE((std::is_same<FIX(bool), decltype(z)>::value));

	// Variable names as expressions
	EXPECT_TRUE((std::is_same<FIX(bool), decltype((x))>::value));
	EXPECT_TRUE((std::is_same<FIX(bool), decltype((y))>::value));
	EXPECT_TRUE((std::is_same<FIX(bool), decltype((z))>::value));

	// Other expressions
	EXPECT_TRUE((std::is_same<FIX(bool), decltype(std::move(x))>::value));
	EXPECT_TRUE((std::is_same<FIX(bool), decltype(x + x)>::value));
}

SECTION(Literals) {
	// What is the type of a literal expression? Note that it is NOT const
	EXPECT_TRUE((std::is_same<FIX(int const), decltype(4)>::value));
}

END_CHAPTER(Expressions)

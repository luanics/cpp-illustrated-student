#pragma once

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///
/// @file core/statement_macros.hpp
///
/// @brief Test statement macros shared across testing framework.
///
/// Note that all names are decorated (minimally) with "LUANICS_" prefix to avoid name clashes.
///
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

#include "luanics/logging/error.hpp"
#include "luanics/string/stringify.hpp"
#include "luanics/testing/core/log.hpp"
#include "luanics/testing/core/result.hpp"

#include <cmath>

//*********************************************************
// Definitions
//*********************************************************

#define LUANICS_DOUBLE_COMPARISON_PRECISION 1e-6

//*********************************************************
// Messages
//*********************************************************

#define LUANICS_PRINT(expression) \
	LUANICS_REPORTER.record(luanics::testing::core::log{__FILE__, __LINE__, #expression " = " + luanics::string::stringify((expression))});

#define LUANICS_EXPECT_EQ_EXPRESSION(expected_string, actual_string)\
	expected_string "==" actual_string

#define LUANICS_EXPECT_EQ_MESSAGE(expected_string, expected_value, actual_string, actual_value)\
	std::string("in expression ") + LUANICS_EXPECT_EQ_EXPRESSION(expected_string, actual_string) + ", expected=" + luanics::string::stringify(expected_value) + " but actual=" + luanics::string::stringify(actual_value)

#define LUANICS_EXPECT_LT_EXPRESSION(small_string, large_string)\
	small_string "<" large_string

#define LUANICS_EXPECT_LT_MESSAGE(small_string, small_value, large_string, large_value)\
	std::string("in expression ") + LUANICS_EXPECT_LT_EXPRESSION(small_string, large_string) + ", " + luanics::string::stringify(small_value) + " is not less than " + luanics::string::stringify(large_value)

#define LUANICS_EXPECT_LE_EXPRESSION(small_string, large_string)\
	small_string "<=" large_string

#define LUANICS_EXPECT_LE_MESSAGE(small_string, small_value, large_string, large_value)\
	std::string("in expression ") + LUANICS_EXPECT_LE_EXPRESSION(small_string, large_string) + ", " + luanics::string::stringify(small_value) + " is not less than or equal to " + luanics::string::stringify(large_value)

#define LUANICS_EXPECT_GT_EXPRESSION(large_string, small_string)\
	large_string ">" small_string

#define LUANICS_EXPECT_GT_MESSAGE(large_string, large_value, small_string, small_value)\
	std::string("in expression ") + LUANICS_EXPECT_GT_EXPRESSION(large_string, small_string) + ", " + luanics::string::stringify(large_value) + " is not greater than " + luanics::string::stringify(small_value)

#define LUANICS_EXPECT_GE_EXPRESSION(large_string, small_string)\
	large_string ">=" small_string

#define LUANICS_EXPECT_GE_MESSAGE(large_string, large_value, small_string, small_value)\
	std::string("in expression ") + LUANICS_EXPECT_GE_EXPRESSION(large_string, small_string) + ", " + luanics::string::stringify(large_value) + " is not greater than or equal to " + luanics::string::stringify(small_value)

#define LUANICS_EXPECT_REACHED_MESSAGE()\
	"reached REACHED section"

#define LUANICS_EXPECT_NOT_REACHED_MESSAGE()\
	"reached NOT_REACHED section"

#define LUANICS_EXPECT_SAME_MESSAGE(expected_string, actual_string)\
	std::string("expected ") + expected_string + std::string(" to be have same type as ") + actual_string

#define LUANICS_EXPECT_THROW_MESSAGE(expression_string)\
	std::string("in expression ") + expression_string + std::string(" expected throw")

#define LUANICS_EXPECT_NO_THROW_MESSAGE(expression_string)\
	std::string("in expression ") + expression_string + std::string(" expected throw")

#define LUANICS_EXPECT_PRECONDITION_VIOLATION_MESSAGE(expression_string)\
	std::string("in expression ") + expression_string + std::string(" expected precondition violation")

#define LUANICS_EXPECT_POSTCONDITION_VIOLATION_MESSAGE(expression_string)\
	std::string("in expression ") + expression_string + std::string(" expected postcondition violation")

//*********************************************************
// Bodies
//*********************************************************

#define LUANICS_EXPECT_EQ_BODY(expected, actual) \
	auto const expected_value = ((expected)); \
	auto const actual_value = ((actual)); \
	bool const is_passing = expected_value == actual_value; \
	LUANICS_REPORTER.record(luanics::testing::core::result{is_passing, __FILE__, __LINE__, LUANICS_EXPECT_EQ_MESSAGE(#expected, expected_value, #actual, actual_value)});

#define LUANICS_EXPECT_NE_BODY(expected, actual) \
	auto const expected_value = ((expected)); \
	auto const actual_value = ((actual)); \
	bool const is_passing = expected_value != actual_value; \
	LUANICS_REPORTER.record(luanics::testing::core::result{is_passing, __FILE__, __LINE__, LUANICS_EXPECT_EQ_MESSAGE(#expected, expected_value, #actual, actual_value)});

#define LUANICS_EXPECT_LT_BODY(small, large) \
	auto const small_value = ((small)); \
	auto const large_value = ((large)); \
	bool const is_passing = small_value < large_value; \
	LUANICS_REPORTER.record(luanics::testing::core::result{is_passing, __FILE__, __LINE__, LUANICS_EXPECT_LT_MESSAGE(#small, small_value, #large, large_value)});
//	LUANICS_REPORTER.record(luanics::testing::core::result{is_passing, __FILE__, __LINE__, "hi dad"});

#define LUANICS_EXPECT_LE_BODY(small, large) \
	auto const small_value = ((small)); \
	auto const large_value = ((large)); \
	bool const is_passing = small_value <= large_value; \
	LUANICS_REPORTER.record(luanics::testing::core::result{is_passing, __FILE__, __LINE__, LUANICS_EXPECT_LE_MESSAGE(#small, small_value, #large, large_value)});

#define LUANICS_EXPECT_GT_BODY(large, small) \
	auto const small_value = ((small)); \
	auto const large_value = ((large)); \
	bool const is_passing = large_value > small_value; \
	LUANICS_REPORTER.record(luanics::testing::core::result{is_passing, __FILE__, __LINE__, LUANICS_EXPECT_GT_MESSAGE(#large, large_value, #small, small_value)});

#define LUANICS_EXPECT_GE_BODY(large, small) \
	auto const small_value = ((small)); \
	auto const large_value = ((large)); \
	bool const is_passing = large_value >= small_value; \
	LUANICS_REPORTER.record(luanics::testing::core::result{is_passing, __FILE__, __LINE__, LUANICS_EXPECT_GE_MESSAGE(#large, large_value, #small, small_value)});

#define LUANICS_EXPECT_NEAR_BODY(expected, actual) \
	auto const expected_value = ((expected)); \
	auto const actual_value = ((actual)); \
	bool const is_passing = std::fabs(expected_value - actual_value) < LUANICS_DOUBLE_COMPARISON_PRECISION; \
	LUANICS_REPORTER.record(luanics::testing::core::result{is_passing, __FILE__, __LINE__, LUANICS_EXPECT_EQ_MESSAGE(#expected, expected_value, #actual, actual_value)});

#define LUANICS_EXPECT_TRUE_BODY(actual) \
	bool const actual_value = static_cast<bool>(actual); \
	bool const is_passing = actual_value; \
	LUANICS_REPORTER.record(luanics::testing::core::result{is_passing, __FILE__, __LINE__, LUANICS_EXPECT_EQ_MESSAGE("true", true, #actual, actual_value)});

#define LUANICS_EXPECT_FALSE_BODY(actual) \
	bool const actual_value = static_cast<bool>(actual); \
	bool const is_passing = !actual_value; \
	LUANICS_REPORTER.record(luanics::testing::core::result{is_passing, __FILE__, __LINE__, LUANICS_EXPECT_EQ_MESSAGE("false", false, #actual, actual_value)});

#define LUANICS_EXPECT_REACHED_BODY() \
	bool const is_passing = true; \
	LUANICS_REPORTER.record(luanics::testing::core::result{is_passing, __FILE__, __LINE__, LUANICS_EXPECT_REACHED_MESSAGE()});

#define LUANICS_EXPECT_NOT_REACHED_BODY() \
	bool const is_passing = false; \
	LUANICS_REPORTER.record(luanics::testing::core::result{is_passing, __FILE__, __LINE__, LUANICS_EXPECT_NOT_REACHED_MESSAGE()});

#define LUANICS_EXPECT_SAME_BODY(expected, actual) \
	bool const is_passing = std::is_same_v<expected, actual>; \
	LUANICS_REPORTER.record(luanics::testing::core::result{is_passing, __FILE__, __LINE__, LUANICS_EXPECT_SAME_MESSAGE(#expected, #actual)});

#define LUANICS_EXPECT_THROW_BODY(expression) \
	bool is_passing = false; \
	try { \
		(expression); \
	} \
	catch (...) { \
		is_passing = true; \
	} \
	LUANICS_REPORTER.record(luanics::testing::core::result{is_passing, __FILE__, __LINE__, LUANICS_EXPECT_THROW_MESSAGE(#expression)});

#define LUANICS_EXPECT_NO_THROW_BODY(expression) \
	bool is_passing = true; \
	try { \
		(expression); \
	} \
	catch (...) { \
		is_passing = false; \
	} \
	LUANICS_REPORTER.record(luanics::testing::core::result{is_passing, __FILE__, __LINE__, LUANICS_EXPECT_NO_THROW_MESSAGE(#expression)});

#define LUANICS_EXPECT_PRECONDITION_VIOLATION_BODY(expression) \
	bool is_passing = false; \
	try { \
		(expression); \
	} \
	catch (luanics::PreconditionViolation const & e) { \
		is_passing = true; \
	} \
	catch (...) {} \
	LUANICS_REPORTER.record(luanics::testing::core::result{is_passing, __FILE__, __LINE__, LUANICS_EXPECT_PRECONDITION_VIOLATION_MESSAGE(#expression)});

#define LUANICS_EXPECT_POSTCONDITION_VIOLATION_BODY(expression) \
	bool is_passing = false; \
	try { \
		(expression); \
	} \
	catch (luanics::PostconditionViolation const & e) { \
		is_passing = true; \
	} \
	catch (...) {} \
	LUANICS_REPORTER.record(luanics::testing::core::result{is_passing, __FILE__, __LINE__, LUANICS_EXPECT_POSTCONDITION_VIOLATION_MESSAGE(#expression)});

//*********************************************************
// EXPECT macros
//*********************************************************

#define LUANICS_EXPECT_EQ(expected, actual) \
	{ \
		LUANICS_EXPECT_EQ_BODY(expected, actual) \
	}

#define LUANICS_EXPECT_NE(expected, actual) \
	{ \
		LUANICS_EXPECT_NE_BODY(expected, actual) \
	}

#define LUANICS_EXPECT_LT(small, large) \
	{ \
		LUANICS_EXPECT_LT_BODY(small, large) \
	}

#define LUANICS_EXPECT_LE(small, large) \
	{ \
		LUANICS_EXPECT_LE_BODY(small, large) \
	}

#define LUANICS_EXPECT_GT(large, small) \
	{ \
		LUANICS_EXPECT_GT_BODY(large, small) \
	}

#define LUANICS_EXPECT_GE(large, small) \
	{ \
		LUANICS_EXPECT_GE_BODY(large, small) \
	}

#define LUANICS_EXPECT_NEAR(expected, actual) \
	{ \
		LUANICS_EXPECT_NEAR_BODY(expected, actual) \
	}

#define LUANICS_EXPECT_TRUE(actual) \
	{ \
		LUANICS_EXPECT_TRUE_BODY(actual) \
	}

#define LUANICS_EXPECT_FALSE(actual) \
	{ \
		LUANICS_EXPECT_FALSE_BODY(actual) \
	}

#define LUANICS_EXPECT_REACHED() \
	{ \
		LUANICS_EXPECT_REACHED_BODY() \
	}

#define LUANICS_EXPECT_NOT_REACHED() \
	{ \
		LUANICS_EXPECT_NOT_REACHED_BODY() \
	}

#define LUANICS_EXPECT_THROW(expression) \
	{ \
		LUANICS_EXPECT_THROW_BODY(expression) \
	}

#define LUANICS_EXPECT_NO_THROW(expression) \
	{ \
		LUANICS_EXPECT_NO_THROW_BODY(expression) \
	}

#define LUANICS_EXPECT_PRECONDITION_VIOLATION(expression) \
	{ \
		LUANICS_EXPECT_PRECONDITION_VIOLATION_BODY(expression) \
	}

//*********************************************************
// ASSERT macros
//*********************************************************

#define LUANICS_ASSERT_EQ(expected, actual) \
	{ \
		LUANICS_EXPECT_EQ_BODY(expected, actual) \
		if (not is_passing) return; \
	}

#define LUANICS_ASSERT_NE(expected, actual) \
	{ \
		LUANICS_EXPECT_NE_BODY(expected, actual) \
		if (not is_passing) return; \
	}

#define LUANICS_ASSERT_LT(small, large) \
	{ \
		LUANICS_EXPECT_LT_BODY(small, large) \
		if (not is_passing) return; \
	}

#define LUANICS_ASSERT_LE(small, large) \
	{ \
		LUANICS_EXPECT_LE_BODY(small, large) \
		if (not is_passing) return; \
	}

#define LUANICS_ASSERT_GT(large, small) \
	{ \
		LUANICS_EXPECT_GT_BODY(large, small) \
		if (not is_passing) return; \
	}

#define LUANICS_ASSERT_GE(large, small) \
	{ \
		LUANICS_EXPECT_GE_BODY(large, small) \
		if (not is_passing) return; \
	}

#define LUANICS_ASSERT_NEAR(expected, actual) \
	{ \
		LUANICS_ASSERT_NEAR_BODY(expected, actual) \
		if (not is_passing) return; \
	}

#define LUANICS_ASSERT_TRUE(actual) \
	{ \
		LUANICS_EXPECT_TRUE_BODY(actual) \
		if (not is_passing) return; \
	}

#define LUANICS_ASSERT_FALSE(actual) \
	{ \
		LUANICS_EXPECT_FALSE_BODY(actual) \
		if (not is_passing) return; \
	}

#define LUANICS_ASSERT_NOT_REACHED() \
	{ \
		LUANICS_EXPECT_NOT_REACHED_BODY() \
		if (not is_passing) return; \
	}

#define LUANICS_ASSERT_THROW(expression) \
	{ \
		LUANICS_EXPECT_THROW_BODY(expression) \
		if (not is_passing) return; \
	}

#define LUANICS_ASSERT_NO_THROW(expression) \
	{ \
		LUANICS_EXPECT_NO_THROW_BODY(expression) \
		if (not is_passing) return; \
	}

#define LUANICS_ASSERT_PRECONDITION_VIOLATION(expression) \
	{ \
		LUANICS_EXPECT_PRECONDITION_VIOLATION_BODY(expression) \
		if (not is_passing) return; \
	}

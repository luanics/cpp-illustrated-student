#pragma once

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///
/// @file unit/macros.hpp
///
/// @brief Aggregates all unit testing macros
///
/// Also removes LUANICS_ macro decoration if allowed
///
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

#include "luanics/testing/unit/structural_macros.hpp"

#ifndef LUANICS_REQUIRE_MACRO_DECORATION

#define BEGIN_TEST_SET(test_set_name) LUANICS_BEGIN_TEST_SET(test_set_name)
#define END_TEST_SET(test_set_name) LUANICS_END_TEST_SET()

#define TEST(test_name) LUANICS_TEST(test_name)
#define TEST_SLOW(test_name) LUANICS_TEST_SLOW(test_name)

#endif

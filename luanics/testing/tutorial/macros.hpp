#pragma once

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///
/// @file tutorial/macros.hpp
///
/// @brief Aggregates all tutorial macros
///
/// Also removes LUANICS_ macro decoration if allowed
///
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

#include "luanics/testing/tutorial/answer_macros.hpp"
#include "luanics/testing/tutorial/structural_macros.hpp"

#ifndef LUANICS_REQUIRE_MACRO_DECORATION

#define BEGIN_CHAPTER(name) LUANICS_BEGIN_CHAPTER(name)
#define END_CHAPTER(name) LUANICS_END_CHAPTER(name)
#define SECTION(name) LUANICS_SECTION(name)

#define BEGIN_SUBPROJECT(name) LUANICS_BEGIN_SUBPROJECT(name)
#define END_SUBPROJECT(name) LUANICS_END_SUBPROJECT(name)
#define SUBPROJECT_TEST(name) LUANICS_SUBPROJECT_TEST(name)

#define ADD_TUTORIAL(name) LUANICS_ADD_TUTORIAL(name)
#define ADD_PART(name, is_enabled) LUANICS_ADD_PART(name, is_enabled)
#define ADD_CHAPTER(part_name, name, is_enabled) LUANICS_ADD_CHAPTER(part_name, name, is_enabled)

#endif

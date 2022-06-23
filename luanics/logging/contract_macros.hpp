#pragma once

#include "luanics/logging/error.hpp"
#include "luanics/logging/logging.hpp"

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///
/// @file contract_macros.hpp
///
/// @brief Contract macros decorated with LUANICS_ for safety.
///
/// @see contract.hpp
///
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

#define LUANICS_ASSERT(...) LUANICS_ASSERT_IMPL(__VA_ARGS__, "")
#define LUANICS_EXPECTS(...) LUANICS_EXPECTS_IMPL(__VA_ARGS__, "")
#define LUANICS_ENSURES(...) LUANICS_ENSURES_IMPL(__VA_ARGS__, "")

#define LUANICS_ERROR(...) LUANICS_ERROR_IMPL(__VA_ARGS__, "")
#define LUANICS_UNREACHABLE(...) LUANICS_UNREACHABLE_IMPL(__VA_ARGS__, "")

#define LUANICS_ERROR_IMPL(message, ...) \
	LUANICS_FATAL(message, __VA_ARGS__) \
	throw luanics::error(message);

#define LUANICS_UNREACHABLE_IMPL(...) \
	LUANICS_ERROR("Should never reach this line", __VA_ARGS__)

#define LUANICS_ASSERT_IMPL(test, ...) \
{ \
	if (!(test)) { \
		LUANICS_ERROR("Failed ASSERT:" #test, __VA_ARGS__) \
	} \
}

#define LUANICS_EXPECTS_IMPL(test, ...) \
{ \
	if (!(test)) { \
		LUANICS_FATAL("Failed EXPECTS:" #test, __VA_ARGS__) \
		throw luanics::precondition_violation("Failed EXPECTS:" #test); \
	} \
}

#define LUANICS_ENSURES_IMPL(test, ...) \
{ \
	if (!(test)) { \
		LUANICS_FATAL("Failed ENSURES:" #test, __VA_ARGS__) \
		throw luanics::postcondition_violation("Failed ENSURES:" #test); \
	} \
}


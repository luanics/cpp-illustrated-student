#pragma once

#include "luanics/logging/contract_macros.hpp"

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///
/// @file contract.hpp
///
/// @brief Contract macros with LUANICS_ decoration removed for convenience.
///
/// If there is no change of macro name collision with other libraries,
///   use this file and undecorated macro names (ASSERT, etc...) for convenience.
/// Otherwise, *do not* include this file, rather include "contract_macros.hpp" directly
///  and use decorated macro names (LUANICS_ASSERT, etc...).
///
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

/// First arg must be conditional test
#define ASSERT(...) LUANICS_ASSERT(__VA_ARGS__)
/// First arg must be conditional test
#define EXPECTS(...) LUANICS_EXPECTS(__VA_ARGS__)
/// First arg must be conditional test
#define ENSURES(...) LUANICS_ENSURES(__VA_ARGS__)

#define ERROR(message, ...) LUANICS_ERROR(message, __VA_ARGS__)
#define UNREACHABLE(...) LUANICS_UNREACHABLE(__VA_ARGS__)

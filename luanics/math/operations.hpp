#pragma once

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///
/// @file math/operations.hpp
///
/// @brief Basic mathematical operations not provided by Standard Library.
///
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

namespace luanics::math {

/// @returns positive remainder of dividend / divisor
/// @pre divisor > 0
template <typename T>
T positive_modulo(T const dividend, T const divisor);

/// @returns -1 if negative, 0 if zero, 1 if positive
template <typename T>
int sign(T number);

}

#include "luanics/math/operations.ipp"

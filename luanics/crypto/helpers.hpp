#pragma once

#include <cstdint>
#include <string>

namespace luanics::crypto {

/// @returns the distance of value from 'a'
/// @pre ch is lowercase letter
std::int8_t distance_from_a(char value);

/// Shifts the "unshifted" character by "shift" letters in the wrapped English alphabet
/// @pre unshifted is lowercase letter
char shift(char unshifted, int key);

/// Shifts the "unshifted" character by "shift" letters in the wrapped English alphabet
///  if it is a letter, else (number or symbol) leaves it untouched.
///  Maintains capitalization.
char robust_shift(char unshifted, int key);

}

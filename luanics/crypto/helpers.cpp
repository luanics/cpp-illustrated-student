#include "luanics/crypto/helpers.hpp"

#include "luanics/logging/contract.hpp"
#include "luanics/math/operations.hpp"
#include "luanics/testing/tutorial.hpp"

#include <cctype>

namespace {

int constexpr NUM_LETTERS_IN_ENGLISH_ALPHABET = 26;

}

namespace luanics::crypto {

std::int8_t distance_from_a(char const value) {
	EXPECTS(std::islower(value), value);
	return value - 'a';
}

char shift(char const unshifted, int const shift) {
	int const shifted_distance_from_a = distance_from_a(unshifted) + shift;
	int const wrapped_shifted_distance_from_a = math::positive_modulo(shifted_distance_from_a, NUM_LETTERS_IN_ENGLISH_ALPHABET);
	return wrapped_shifted_distance_from_a + 'a';
}

char robust_shift(char const unshifted, int const shift) {
	return FIX(unshifted);
}

} // namespace luanics::crypto

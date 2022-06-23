#include "luanics/testing/core/outcome.hpp"

namespace luanics::testing::core {

namespace {
	constexpr auto NONE_STRING = "NONE";
	constexpr auto PASS_STRING = "PASS";
	constexpr auto FAIL_STRING = "FAIL";
	constexpr auto ERROR_STRING = "ERROR";
}

outcome combined(outcome lhs, outcome rhs) {
	if (lhs <= outcome::NONE and rhs <= outcome::NONE) {
		return outcome::NONE;
	}
	else if (lhs <= outcome::PASS and rhs <= outcome::PASS) {
		return outcome::PASS;
	}
	else if (lhs <= outcome::FAIL and rhs <= outcome::FAIL) {
		return outcome::FAIL;
	}
	else {
		return outcome::ERROR;
	}
}

std::ostream & operator<<(std::ostream & out, outcome outcome) {
	switch (outcome) {
		case outcome::NONE: out << NONE_STRING; break;
		case outcome::PASS: out << PASS_STRING; break;
		case outcome::FAIL: out << FAIL_STRING; break;
		case outcome::ERROR: out << ERROR_STRING; break;
	}
	return out;
}

} // namespace luanics::testing::core

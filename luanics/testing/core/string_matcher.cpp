#include "luanics/testing/core/string_matcher.hpp"

namespace luanics::testing::core {

string_matcher::string_matcher(
	augmented_reporter * decorated,
	matchers_by_depth matchers
) :
	augmented_reporter_decorator{decorated},
	_matchers{std::move(matchers)}
{}

}

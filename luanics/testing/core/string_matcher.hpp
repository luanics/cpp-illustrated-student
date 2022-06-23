#pragma once

#include "luanics/string/matcher.hpp"
#include "luanics/testing/core/augmented_reporter_decorator.hpp"

#include <memory>
#include <unordered_map>

namespace luanics::testing::core {

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
///
/// @class string_matcher
///
/// @brief Decorator that only reports on components with matching name().
///
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
class string_matcher : public augmented_reporter_decorator {
public:
	using matchers_by_depth = std::unordered_map<unsigned, std::unique_ptr<string::matcher>>;

	string_matcher(
		augmented_reporter * decorated,
		matchers_by_depth matchers
	);

private:
	matchers_by_depth _matchers;
};

}

#pragma once

#include "luanics/string/matcher.hpp"

#include <string>
#include <vector>

namespace luanics::string {

/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
///
/// @class enumerated_matcher
///
/// @brief Matches any of an enumerated list of strings.
///
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
class enumerated_matcher : public matcher {
public:
	enumerated_matcher(std::vector<std::string> targets);

	virtual bool operator()(std::string const & candidate) const override final;

private:
	std::vector<std::string> _targets;
};

}

#include "luanics/string/enumerated_matcher.hpp"

namespace luanics::string {

enumerated_matcher::enumerated_matcher(std::vector<std::string> targets) :
	_targets{std::move(targets)}
{}

bool enumerated_matcher::operator()(std::string const & candidate) const {
	for (auto const & target: _targets) {
		if (candidate == target) {
			return true;
		}
	}
	return false;
}

}

#include "luanics/testing/core/string_excluder.hpp"

#include "luanics/testing/core/component.hpp"

namespace luanics::testing::core {

string_excluder::string_excluder(
	augmented_reporter * decorated,
	std::string target
) :
	augmented_reporter_decorator{decorated},
	_target{std::move(target)}
{}

bool string_excluder::start_report_on(
	component const & component,
	unsigned const depth
) {
	bool isMatch = component.name().find(_target) != std::string::npos;
	if (isMatch) {
		return false;
	}
	return augmented_reporter_decorator::start_report_on(component, depth);
}

void string_excluder::finish_report_on(
	component const & component,
	unsigned const depth,
	outcome const outcome
) {
	augmented_reporter_decorator::finish_report_on(component, depth, outcome);
}

} // namespace luanics::testing::core

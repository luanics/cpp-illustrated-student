#include "luanics/testing/core/slow_excluder.hpp"

#include "luanics/testing/core/component.hpp"

namespace luanics::testing::core {

slow_excluder::slow_excluder(augmented_reporter * decorated) :
	augmented_reporter_decorator{decorated}
{}

bool slow_excluder::start_report_on(
	component const & component,
	unsigned const depth
) {
	if (component.is_slow()) return false;
	return augmented_reporter_decorator::start_report_on(component, depth);
}

void slow_excluder::finish_report_on(
	component const & component,
	unsigned const depth,
	outcome const outcome
) {
	augmented_reporter_decorator::finish_report_on(component, depth, outcome);
}

}

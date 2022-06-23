#include "luanics/testing/core/augmented_reporter_decorator.hpp"

namespace luanics::testing::core {

augmented_reporter_decorator::augmented_reporter_decorator(augmented_reporter * decorated) :
	_decorated{decorated}
{}

bool augmented_reporter_decorator::start_report_on(
	component const & component,
	unsigned const depth
) {
	return _decorated->start_report_on(component, depth);
}

void augmented_reporter_decorator::finish_report_on(
	component const & component,
	unsigned const depth,
	outcome const outcome
) {
	_decorated->finish_report_on(component, depth, outcome);
}

void augmented_reporter_decorator::record(error const & error) {
	_decorated->record(error);
}

void augmented_reporter_decorator::record(log const & log) {
	_decorated->record(log);
}

void augmented_reporter_decorator::record(result const & result) {
	_decorated->record(result);
}

} // namespace luanics::testing::core

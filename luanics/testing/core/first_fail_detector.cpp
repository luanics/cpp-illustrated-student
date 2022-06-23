#include "luanics/testing/core/first_fail_detector.hpp"

namespace luanics::testing::core {

namespace {

bool is_fail(outcome const outcome) {
	return outcome == outcome::FAIL or outcome == outcome::ERROR;
}

}

first_fail_detector::first_fail_detector(augmented_reporter * decorated) :
	augmented_reporter_decorator{decorated},
	_has_failed{false}
{}

bool first_fail_detector::start_report_on(
	component const & component,
	unsigned const depth
) {
	if (_has_failed) {
		return false;
	}
	return augmented_reporter_decorator::start_report_on(component, depth);
}

void first_fail_detector::finish_report_on(
	component const & component,
	unsigned const depth,
	outcome const outcome
) {
	_has_failed = is_fail(outcome);
	augmented_reporter_decorator::finish_report_on(component, depth, outcome);
}

} // namespace luanics::testing::core

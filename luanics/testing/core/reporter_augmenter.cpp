#include "luanics/testing/core/reporter_augmenter.hpp"

#include "luanics/logging/contract.hpp"
#include "luanics/testing/core/augmented_reporter.hpp"
#include "luanics/testing/core/component.hpp"
#include "luanics/testing/core/error.hpp"
#include "luanics/testing/core/log.hpp"
#include "luanics/testing/core/result.hpp"

namespace luanics::testing::core {

reporter_augmenter::reporter_augmenter(augmented_reporter * adapted) :
	_adapted{adapted},
	_outcomes{}
{}

bool reporter_augmenter::start_report_on(component const & component) {
	_outcomes.push(outcome::NONE);
	bool const isStarted = _adapted->start_report_on(component, depth());
	if (not isStarted) {
		_outcomes.pop();
	}
	return isStarted;
}

void reporter_augmenter::finish_report_on(component const & component) {
	_adapted->finish_report_on(component, depth(), _outcomes.top());

	// Update outcome for parent level
	outcome const component_outcome = _outcomes.top();
	_outcomes.pop();
	if (not _outcomes.empty()) {
		_outcomes.top() = combined(_outcomes.top(), component_outcome);
	}
}

void reporter_augmenter::record(error const & error) {
	_outcomes.top() = combined(_outcomes.top(), outcome::ERROR);
	_adapted->record(error);
}

void reporter_augmenter::record(log const & log) {
	_adapted->record(log);
}

void reporter_augmenter::record(result const & result) {
	if (result.is_pass) {
		_outcomes.top() = combined(_outcomes.top(), outcome::PASS);
	}
	else {
		_outcomes.top() = combined(_outcomes.top(), outcome::FAIL);
	}
	_adapted->record(result);
}

unsigned reporter_augmenter::depth() const {
	LUANICS_ASSERT(not _outcomes.empty());
	return _outcomes.size() - 1;
}

}

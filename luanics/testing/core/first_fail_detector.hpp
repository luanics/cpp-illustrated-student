#pragma once

#include "augmented_reporter_decorator.hpp"

namespace luanics::testing::core {

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
///
/// @class FirstFailDecorator
///
/// @brief AugmentedReporterDecorator that stops reporting after the
///   first FAIL or ERROR Outcome.
///
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
class first_fail_detector : public augmented_reporter_decorator {
public:
	first_fail_detector(augmented_reporter * decorated);

	virtual bool start_report_on(
		component const & component,
		unsigned depth
	) override final;
	virtual void finish_report_on(
		component const & component,
		unsigned depth,
		outcome outcome
	) override final;

private:
	bool _has_failed;
};

}

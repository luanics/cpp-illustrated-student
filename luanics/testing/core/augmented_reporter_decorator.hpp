#pragma once

#include "luanics/testing/core/augmented_reporter.hpp"

namespace luanics::testing::core {

/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
///
/// @class augmented_reporter_decorator
///
/// @brief Decorator pattern applied to augmented_reporter.
///
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
class augmented_reporter_decorator : public augmented_reporter {
public:
	augmented_reporter_decorator(augmented_reporter * decorated);

	virtual bool start_report_on(
		component const & component,
		unsigned depth
	) override;
	virtual void finish_report_on(
		component const & component,
		unsigned depth,
		outcome outcome
	) override;

	virtual void record(error const & error) override;
	virtual void record(log const & log) override;
	virtual void record(result const & result) override;

private:
	augmented_reporter * _decorated;
};

}

#pragma once

#include "luanics/testing/core/augmented_reporter_decorator.hpp"

namespace luanics::testing::core {

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
///
/// @class slow_exluder
///
/// @brief Decorator that excludes components with is_slow() set.
///
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
class slow_excluder : public augmented_reporter_decorator {
public:
	slow_excluder(augmented_reporter * filtered);

	virtual bool start_report_on(
		component const & component,
		unsigned depth
	) final;
	virtual void finish_report_on(
		component const & component,
		unsigned depth,
		outcome outcome
	) final;
};

}

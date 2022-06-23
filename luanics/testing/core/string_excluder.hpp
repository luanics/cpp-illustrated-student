#pragma once

#include "luanics/testing/core/augmented_reporter_decorator.hpp"

namespace luanics::testing::core {

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
///
/// @class string_excluder
///
/// @brief Decorator that excludes components with target in their name().
///
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
class string_excluder : public augmented_reporter_decorator {
public:
	string_excluder(
		augmented_reporter * filtered,
		std::string target
	);

	virtual bool start_report_on(
		component const & component,
		unsigned depth
	) final;
	virtual void finish_report_on(
		component const & component,
		unsigned depth,
		outcome outcome
	) final;

private:
	std::string _target;
};

}

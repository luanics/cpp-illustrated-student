#pragma once

#include "luanics/testing/core/outcome.hpp"

namespace luanics::testing::core {

class component;
class error;
class log;
class result;

/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
///
/// @class augmented_reporter
///
/// @brief Adds "depth" and "outcome" to the \ref<reporter> callbacks.
///
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
class augmented_reporter {
public:
	virtual ~augmented_reporter() = default;

	/// @return false if wants to skip this component
	virtual bool start_report_on(
		component const & component,
		unsigned depth
	) = 0;
	virtual void finish_report_on(
		component const & component,
		unsigned depth,
		outcome outcome
	) = 0;

	virtual void record(error const & error) = 0;
	virtual void record(log const & log) = 0;
	virtual void record(result const & result) = 0;

}; // class augmented_reporter

} // namespace luanics::testing::core

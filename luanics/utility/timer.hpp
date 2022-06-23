#pragma once

#include <chrono>

namespace luanics::utility {

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///
/// @class timer
///
/// @brief Stopwatch-style timer based on std::chrono clocks.
///
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
template <typename ClockT = std::chrono::high_resolution_clock>
class timer {
public:
	using clock_type = ClockT;
	using duration_type = typename ClockT::duration;

	/// start() called on construction
	timer();

	/// "start" the Timer running from current time
	void start();
	/// @returns time elapsed since start() called
	duration_type elapsed() const;

private:
	using time_type = typename clock_type::time_point;
	time_type _start;
};

}

#include "luanics/utility/timer.ipp"

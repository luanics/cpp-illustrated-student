#include "luanics/utility/timer.hpp"

namespace luanics::utility {

template <typename ClockT>
timer<ClockT>::timer() {
	start();
}

template <typename ClockT>
void timer<ClockT>::start() {
	_start = ClockT::now();
}

template <typename ClockT>
typename timer<ClockT>::duration_type timer<ClockT>::elapsed() const {
	return std::chrono::duration_cast<duration_type>(ClockT::now() - _start);
}

}

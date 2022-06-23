#include "luanics/testing/core/result.hpp"
#include "luanics/testing/core/simple_reporter.hpp"

namespace luanics::testing::core {

simple_reporter::simple_reporter() :
	_num_pass_results{0}, _num_fail_results{0}, _num_errors{0}, _num_logs{0}
{}

bool simple_reporter::start_report_on(component const & component) {
	return true;
}

void simple_reporter::finish_report_on(component const & component) {

}

void simple_reporter::record(result const & result) {
	if (result.is_pass) {
		++_num_pass_results;
	}
	else {
		++_num_fail_results;
	}
}

void simple_reporter::record(error const & error) {
	++_num_errors;
}

void simple_reporter::record(log const & log) {
	++_num_logs;
}

std::size_t simple_reporter::num_pass_results() const {
	return _num_pass_results;
}

std::size_t simple_reporter::num_fail_results() const {
	return _num_fail_results;
}

std::size_t simple_reporter::num_errors() const {
	return _num_errors;
}

size_t simple_reporter::num_logs() const {
	return _num_logs;
}

} // namespace luanics::testing::core

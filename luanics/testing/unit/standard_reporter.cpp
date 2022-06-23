#include "luanics/logging/contract.hpp"
#include "luanics/testing/core/component.hpp"
#include "luanics/testing/core/error.hpp"
#include "luanics/testing/core/log.hpp"
#include "luanics/testing/core/result.hpp"
#include "standard_reporter.hpp"
#include "luanics/utility/paths.hpp"
#include "luanics/utility/streams.hpp"

namespace luanics::testing::unit {

namespace {

using namespace luanics::utility::streams;

std::string const BAR_BEGIN_DELIMITER = "[";
std::string const BAR_END_DELIMITER = "]";
std::string const INTRO_BAR   = "   TEST   ";
std::string const SUITE_BAR   = "==========";
std::string const CASE_BAR    = "----------";
std::string const LOG_BAR     = "    LOG   ";
std::string const RUN_BAR     = " RUN      ";
std::string const OK_BAR      = "       OK ";
std::string const PASS_BAR    = "  PASSED  ";
std::string const FAIL_BAR    = "  FAILED  ";
std::string const FAILURE_MESSAGE_INTRO = "FAILURE";
std::string const ERROR_MESSAGE_INTRO = "ERROR";
std::string const TESTCASE_TEST_DELIMITER = ".";
std::string const FAILED_TEST_BULLET = "* ";

std::ostream & intro_bar(std::ostream & out) {
	out << bold_green << BAR_BEGIN_DELIMITER << bold_blue << INTRO_BAR << bold_green << BAR_END_DELIMITER << plain;
	return out;
}

std::ostream & test_suite_bar(std::ostream & out) {
	out << bold_green << BAR_BEGIN_DELIMITER << SUITE_BAR << BAR_END_DELIMITER << plain;
	return out;
}

std::ostream & test_set_bar(std::ostream & out) {
	out << bold_green << BAR_BEGIN_DELIMITER << CASE_BAR << BAR_END_DELIMITER << plain;
	return out;
}

std::ostream & log_bar(std::ostream & out) {
	out << white << BAR_BEGIN_DELIMITER << LOG_BAR << BAR_END_DELIMITER << plain;
	return out;
}

std::ostream & run_bar(std::ostream & out) {
	out << bold_green << BAR_BEGIN_DELIMITER << RUN_BAR << BAR_END_DELIMITER << plain;
	return out;
}

std::ostream & ok_bar(std::ostream & out) {
	out << bold_green << BAR_BEGIN_DELIMITER << OK_BAR << BAR_END_DELIMITER << plain;
	return out;
}

std::ostream & pass_bar(std::ostream & out) {
	out << bold_green << BAR_BEGIN_DELIMITER << PASS_BAR << BAR_END_DELIMITER << plain;
	return out;
}

std::ostream & fail_bar(std::ostream & out) {
	out << bold_red << BAR_BEGIN_DELIMITER << FAIL_BAR << BAR_END_DELIMITER << plain;
	return out;
}

std::ostream & failed_test_bullet(std::ostream & out) {
	out << bold_red << FAILED_TEST_BULLET << plain;
	return out;
}

}

standard_reporter::standard_reporter(
	std::ostream * out,
	bool const isUsingColors,
	bool const isTerse
) :
	_out{out},
	_isTerse{isTerse},
	_test_suite_timer{},
	_test_set_timer{},
	_test_timer{},
	_test_set_name{},
	_global_test_count{0},
	_local_test_count{0},
	_failed_tests{}
{}

bool standard_reporter::start_report_on(core::component const & component, unsigned const depth) {
	switch (depth) {
		case level::TEST_SUITE: return start_test_suite();
		case level::TEST_SET: return start_test_set(component.name());
		case level::TEST: return start_test(component.name());
		default: LUANICS_UNREACHABLE(depth); return false;
	}
}

void standard_reporter::finish_report_on(core::component const & component, unsigned const depth, core::outcome const outcome) {
	switch (depth) {
		case level::TEST_SUITE: finish_test_suite(outcome); break;
		case level::TEST_SET: finish_test_set(component.name(), outcome); break;
		case level::TEST: finish_test(component.name(), outcome); break;
		default: LUANICS_UNREACHABLE(depth);
	}
}

bool standard_reporter::start_test_suite() {
	*_out << test_suite_bar << std::endl;
	*_out << intro_bar << std::endl;
	*_out << std::endl;
	_test_suite_timer.start();
	return true;
}

void standard_reporter::finish_test_suite(core::outcome const outcome) {
	auto const suite_elapsed = _test_suite_timer.elapsed();
	auto const msec = std::chrono::duration_cast<std::chrono::milliseconds>(suite_elapsed).count();
	*_out << test_suite_bar << " (" << msec << "msec)" << std::endl;
	*_out << pass_bar << " " << num_tests_passed() << " tests" << std::endl;
	if (num_tests_failed() > 0) {
		*_out << fail_bar << " " << num_tests_failed() << " tests" << std::endl;
		for (auto const & test: _failed_tests) {
			*_out << failed_test_bullet << test << std::endl;
		}
	}
	*_out << std::endl;
}

bool standard_reporter::start_test_set(std::string const & name) {
	_test_set_name = name;
	_local_test_count = 0;
	if (_isTerse) {
		return true;
	}
	*_out << test_set_bar << " " << _test_set_name << std::endl;
	_test_set_timer.start();
	return true;
}

void standard_reporter::finish_test_set(std::string const & name, core::outcome const outcome) {
	if (_isTerse) {
		return;
	}
	auto const case_elapsed = _test_set_timer.elapsed();
	auto const msec = std::chrono::duration_cast<std::chrono::milliseconds>(case_elapsed).count();
	*_out << test_set_bar << " " << _local_test_count << " tests from " << _test_set_name;
	*_out << " (" << msec << "msec)" << std::endl;
	*_out << std::endl;
}

bool standard_reporter::start_test(std::string const & name) {
	++_global_test_count;
	++_local_test_count;
	if (_isTerse) {
		return true;
	}
	*_out << run_bar << " " << _test_set_name << TESTCASE_TEST_DELIMITER << name << std::endl;
	_test_timer.start();
	return true;
}

void standard_reporter::finish_test(std::string const & name, core::outcome const outcome) {
	if (_isTerse) {
		return;
	}
	auto const testElapsed = _test_timer.elapsed();
	auto const msec = std::chrono::duration_cast<std::chrono::milliseconds>(testElapsed).count();
	switch (outcome) {
		case core::outcome::NONE:
		case core::outcome::PASS:
			*_out << ok_bar;
			break;
		case core::outcome::FAIL:
		case core::outcome::ERROR:
			*_out << fail_bar;
			_failed_tests.push_back(_test_set_name + TESTCASE_TEST_DELIMITER + name);
			break;
	}
	*_out << " " << _test_set_name << TESTCASE_TEST_DELIMITER << name;
	*_out << " (" << msec << "msec)" << std::endl;
}

void standard_reporter::record(core::error const & error) {
	*_out << ERROR_MESSAGE_INTRO;
	*_out << ": " << error.message << std::endl;
}

void standard_reporter::record(core::log const & log) {
	*_out << log_bar << "(";
	write_file_line_identifier(log.file_name, log.line);
	*_out << ") " << log.message << std::endl;
}

void standard_reporter::record(core::result const & result) {
	if (result.is_pass) {
		return;
	}
	*_out << FAILURE_MESSAGE_INTRO << " @ ";
	write_file_line_identifier(result.file_name, result.line);
	*_out << ": " << result.message << std::endl;
}

//*****************************************************************************
// Helpers
//*****************************************************************************

size_t standard_reporter::num_tests_passed() const {
	return _global_test_count - num_tests_failed();
}

size_t standard_reporter::num_tests_failed() const {
	return _failed_tests.size();
}

void standard_reporter::write_file_line_identifier(char const * const file_path, int const line) {
	*_out << utility::file_name_from(file_path) << ":" << line;
}

} // namespace luanics::testing::unit

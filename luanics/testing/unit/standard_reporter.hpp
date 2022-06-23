#pragma once

#include "luanics/testing/core/augmented_reporter.hpp"
#include "../../utility/timer.hpp"

#include <chrono>
#include <iostream>
#include <vector>

namespace luanics::testing::unit {

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///
/// @class standard_reporter
///
/// @brief A unit-test \tag{reporter} with "gtest"-style output.
///
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
class standard_reporter : public core::augmented_reporter {
public:
	enum level {
		TEST_SUITE = 0,
		TEST_SET = 1,
		TEST = 2
	};

	standard_reporter(
		std::ostream * out,
		bool isUsingColors = true,
		bool isTerse = false
	);

	virtual bool start_report_on(
		core::component const & component,
		unsigned depth
	) final;
	virtual void finish_report_on(
		core::component const & component,
		unsigned depth,
		core::outcome const outcome
	) final;

	virtual void record(core::error const & error) override final;
	virtual void record(core::log const & log) override final;
	virtual void record(core::result const & result) override final;

	size_t num_tests_passed() const;
	size_t num_tests_failed() const;

private:
	bool start_test_suite();
	void finish_test_suite(core::outcome outcome);
	bool start_test_set(std::string const & name);
	void finish_test_set(std::string const & name, core::outcome outcome);
	bool start_test(std::string const & name);
	void finish_test(std::string const & name, core::outcome outcome);

	void write_file_line_identifier(char const * const filePath, int line);

	std::ostream * _out;
	bool _isTerse;
	utility::timer<std::chrono::high_resolution_clock> _test_suite_timer;
	utility::timer<std::chrono::high_resolution_clock> _test_set_timer;
	utility::timer<std::chrono::high_resolution_clock> _test_timer;
	std::string _test_set_name;
	size_t _global_test_count;
	size_t _local_test_count;
	std::vector<std::string> _failed_tests;
};

}

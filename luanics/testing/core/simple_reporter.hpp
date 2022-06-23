#pragma once

#include "luanics/testing/core/reporter.hpp"

#include <cstddef>

namespace luanics::testing::core {

/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
///
/// @class simple_reporter
///
/// @brief reporter that simply counts the kinds of outcomes.
///
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
class simple_reporter : public reporter {
public:
	simple_reporter();

	virtual bool start_report_on(component const & component) final;
	virtual void finish_report_on(component const & component) final;

	virtual void record(result const & result) final;
	virtual void record(error const & error) final;
	virtual void record(log const & log) final;

	std::size_t num_pass_results() const;
	std::size_t num_fail_results() const;
	std::size_t num_errors() const;
	std::size_t num_logs() const;

private:
	std::size_t _num_pass_results;
	std::size_t _num_fail_results;
	std::size_t _num_errors;
	std::size_t _num_logs;
};

}

#pragma once

#include "luanics/testing/core/augmented_reporter.hpp"

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

namespace luanics::testing::core {

/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
///
/// @class IndentingReporter
///
/// @brief Writes test results to ostream, indenting each level of hierarchy.
///
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
class indenting_reporter : public augmented_reporter {
public:
	indenting_reporter(
		std::ostream * out,
		bool const isVerbose = true
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

	virtual void record(error const & error) final;
	virtual void record(log const & log) final;
	virtual void record(result const & result) final;

private:
	void push_line_index();
	unsigned pop_line_index();

	void setup();

	void compose_line(std::string const & name, core::outcome outcome);
	void compose_line(error const & error);
	void compose_line(log const & log);
	void compose_line(result const & result);
	void compose_file_line_identifier(char const * const file_path, int line);
	void compose_indentation(unsigned depth);
	void store_composed_line();
	void store_composed_line_at(unsigned index);
	void clear_line();
	void flush_lines();

	bool _is_verbose;
	unsigned _depth;
	std::vector<std::string> _lines;
	std::vector<unsigned> _indices;
	std::ostringstream _line;
	std::ostream * _out;

	std::string _none_intro;
	std::string _log_intro;
	std::string _pass_intro;
	std::string _fail_intro;
	std::string _error_intro;
};

}

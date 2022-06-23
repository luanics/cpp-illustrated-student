#include "../../logging/contract.hpp"
#include "luanics/testing/core/component.hpp"
#include "luanics/testing/core/error.hpp"
#include "luanics/testing/core/indenting_reporter.hpp"
#include "luanics/testing/core/log.hpp"
#include "luanics/testing/core/result.hpp"
#include "luanics/utility/paths.hpp"
#include "luanics/utility/streams.hpp"

#include <algorithm>
#include <iterator>

namespace luanics::testing::core {

namespace {

std::string const INTRO_BEGIN_DELIMITER = "[";
std::string const INTRO_END_DELIMITER = "]";
std::string const INDENT = "   ";

}

indenting_reporter::indenting_reporter(
	std::ostream * out,
	bool const isVerbose
) :
	_is_verbose{isVerbose},
	_depth{0},
	_lines{},
	_indices{},
	_line{},
	_out{out},
	_none_intro{},
	_log_intro{},
	_pass_intro{},
	_fail_intro{},
	_error_intro{}
{
	setup();
}

bool indenting_reporter::start_report_on(component const & component, unsigned const depth) {
	_depth = depth;
	push_line_index();
	return true;
}

void indenting_reporter::finish_report_on(component const & component, unsigned const depth, outcome const outcome) {
	_depth = depth;
	compose_line(component.name(), outcome);
	store_composed_line_at(pop_line_index());
	if (depth == 0) {
		flush_lines();
	}
}

void indenting_reporter::record(core::error const & error) {
	compose_line(error);
	store_composed_line();
}

void indenting_reporter::record(core::log const & log) {
	compose_line(log);
	store_composed_line();
}

void indenting_reporter::record(core::result const & result) {
	compose_line(result);
	store_composed_line();
}

void indenting_reporter::setup() {
	using namespace utility::streams;

	std::ostringstream out;

	out << INTRO_BEGIN_DELIMITER << dark_gray << "NONE " << plain << INTRO_END_DELIMITER;
	_none_intro = out.str();
	reset(out);

	out << INTRO_BEGIN_DELIMITER << light_gray << "PRINT" << plain << INTRO_END_DELIMITER;
	_log_intro = out.str();
	reset(out);

	out << INTRO_BEGIN_DELIMITER << green << "PASS " << plain << INTRO_END_DELIMITER;
	_pass_intro = out.str();
	reset(out);

	out << INTRO_BEGIN_DELIMITER << red << "FAIL " << plain << INTRO_END_DELIMITER;
	_fail_intro = out.str();
	reset(out);

	out << INTRO_BEGIN_DELIMITER << bold_red << "ERROR" << plain << INTRO_END_DELIMITER;
	_error_intro = out.str();
}

void indenting_reporter::compose_line(std::string const & name, core::outcome const outcome) {
	compose_indentation(_depth);
	switch (outcome) {
		case core::outcome::NONE: _line << _none_intro; break;
		case core::outcome::PASS: _line << _pass_intro; break;
		case core::outcome::FAIL: _line << _fail_intro; break;
		case core::outcome::ERROR: _line << _error_intro; break;
	}
	_line << " " << name;
}

void indenting_reporter::compose_line(core::error const & error) {
	compose_indentation(_depth + 1);
	_line << _error_intro;
	_line << " - " << error.message;
}

void indenting_reporter::compose_line(core::log const & log) {
	compose_indentation(_depth + 1);
	_line << _log_intro;
	_line << " ";
	compose_file_line_identifier(log.file_name, log.line);
	_line << " - " << log.message;
}

void indenting_reporter::compose_line(core::result const & result) {
	compose_indentation(_depth + 1);
	_line << (result.is_pass ? _pass_intro : _fail_intro);
	_line << " ";
	compose_file_line_identifier(result.file_name, result.line);
	if (_is_verbose) {
		_line << " - " << result.message;
	}
}

void indenting_reporter::compose_file_line_identifier(char const * const file_path, int const line) {
	_line << utility::file_name_from(file_path) << ":" << line;
}

void indenting_reporter::compose_indentation(unsigned const depth) {
	for (unsigned d{0}; d < depth; ++d) {
		_line << INDENT;
	}
}

void indenting_reporter::store_composed_line() {
	_lines.push_back(_line.str());
	clear_line();
}

void indenting_reporter::store_composed_line_at(unsigned const index) {
	_lines[index] = _line.str();
	clear_line();
}

void indenting_reporter::clear_line() {
	_line.str("");
	_line.clear();
}

void indenting_reporter::flush_lines() {
	std::copy(
		_lines.begin(),
		_lines.end(),
		std::ostream_iterator<std::string>(*_out, "\n")
	);
}

void indenting_reporter::push_line_index() {
	_lines.push_back("");
	_indices.push_back(_lines.size() - 1);
}

unsigned indenting_reporter::pop_line_index() {
	auto const result = _indices.back();
	_indices.pop_back();
	return result;
}

}

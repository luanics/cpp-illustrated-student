#include "luanics/testing/core/leaf.hpp"

#include "luanics/testing/core/error.hpp"
#include "luanics/testing/core/reporter.hpp"

#include <iostream>

namespace luanics::testing::core {

leaf::leaf(std::string name, bool isSlow) :
	_name{std::move(name)}, _is_slow{isSlow}
{}

std::string const & leaf::name() const {
	return _name;
}

bool leaf::is_slow() const {
	return _is_slow;
}

void leaf::run(reporter & reporter) {
	if (not reporter.start_report_on(*this)) return;
	try {
		do_run(reporter);
	}
	catch (std::exception const & error) {
		reporter.record(core::error{error.what()});
	}
	reporter.finish_report_on(*this);
}

}

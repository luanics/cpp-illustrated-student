#include "composite.hpp"
#include "reporter.hpp"

namespace luanics::testing::core {

composite::composite(std::string name) :
	_name{std::move(name)},
	_children{}
{}

std::string const & composite::name() const {
	return _name;
}

void composite::run(reporter & reporter) {
	if (not reporter.start_report_on(*this)) return;
	for (component * child: _children) {
		child->run(reporter);
	}
	reporter.finish_report_on(*this);
}

void composite::add(component * child) {
	_children.push_back(child);
}

bool composite::is_slow() const {
	return false;
}

typename composite::ChildMapType const & composite::children() const {
	return _children;
}

} // namespace luanics::testing::core

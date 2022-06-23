#pragma once

#include <string>

namespace luanics::testing::core {

class Filter;
class reporter;

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
///
/// @class Component
///
/// @brief Base class for components (nodes) in a test hierarchy.
///
/// `Component` in the `Composite` design pattern.
///
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
class component {
public:
	virtual ~component() = default;

	virtual std::string const & name() const = 0;
	virtual bool is_slow() const = 0;
	virtual void run(reporter & reporter) = 0;
};

} // namespace luanics::testing::core

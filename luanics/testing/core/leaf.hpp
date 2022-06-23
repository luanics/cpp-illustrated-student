#pragma once

#include "component.hpp"

#include <list>

namespace luanics::testing::core {

class reporter;

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
///
/// @class Leaf
///
/// @brief A leaf in a testing hierarchy.
///
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
class leaf : public component {
public:
	leaf(std::string name, bool is_slow = false);

	virtual std::string const & name() const override final;
	virtual bool is_slow() const override final;
	virtual void run(reporter & reporter) override final;

private:
	virtual void do_run(reporter & reporter) = 0;

	std::string _name;
	bool _is_slow;
};

} // namespace luanics::testing::core

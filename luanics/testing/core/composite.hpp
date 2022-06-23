#pragma once

#include "luanics/testing/core/component.hpp"

#include <memory>
#include <vector>

namespace luanics::testing::core {

class reporter;

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
///
/// @class Composite
///
/// @brief A Composite component in a test hierarchy.
///
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
class composite : public component {
public:
	using ChildMapType = std::vector<component*>;

	composite(std::string name);

	virtual std::string const & name() const override final;
	virtual bool is_slow() const override final;
	virtual void run(reporter & reporter) override final;

	void add(component * child);
	ChildMapType const & children() const;

private:
	std::string _name;
	ChildMapType _children;
};

} // namespace luanics::testing::core

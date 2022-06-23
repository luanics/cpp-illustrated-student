#pragma once

#include "luanics/testing/core/component.hpp"

namespace luanics::testing::core {

/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
///
/// @class dummy_component
///
/// @brief Test double for \tag{component} that simply provides a name.
///
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
class dummy_component final : public component {
public:
	dummy_component(std::string name, bool isSlow = false) :
		_name{std::move(name)}, _is_slow{isSlow}
	{}
	virtual std::string const & name() const final {return _name;}
	virtual bool is_slow() const final {return _is_slow;}
	virtual void run(reporter & reporter) final {}

private:
	std::string _name;
	bool _is_slow;
};

}

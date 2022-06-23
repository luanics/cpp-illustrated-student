#pragma once

#include "luanics/logging/filter.hpp"
#include "luanics/logging/record.hpp"

namespace luanics::logging {

/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
///
/// @class LevelFilter
///
/// @brief Filters out all levels above the "maxLevel"
///
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
class level_filter : public filter {
public:
	level_filter(level maxLevel) : _maxLevel{maxLevel} {}
	virtual bool is_accepting(record const & record) const override final {
		return record.level() <= _maxLevel;
	}
private:
	level _maxLevel;
};

}

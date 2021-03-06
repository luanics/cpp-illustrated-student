#pragma once

namespace luanics::logging {

class record;

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///
/// @class filter
///
/// @brief Component that decides whether a logging::record is accepted or rejected.
///
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
class filter {
public:
	virtual bool is_accepting(record const & record) const = 0;

	virtual ~filter() {}
};

}

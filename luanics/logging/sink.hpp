#pragma once

#include <memory>

namespace luanics::logging {

class record;

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///
/// @class sink
///
/// @brief Back-end of logging framework.
///
/// Consumes logging::record handed off from logging::source.
///
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
class sink {
public:
	virtual void consume(std::unique_ptr<record> record) = 0;

	virtual ~sink() {}
};

}

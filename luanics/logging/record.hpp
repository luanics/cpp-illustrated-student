#pragma once

#include "luanics/logging/level.hpp"

#include <iosfwd>

namespace luanics::logging {

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///
/// @class record
///
/// @brief A record of a single client logging request.
///
/// Contains meta-info about a logging message (level, file, line),
///  and has the ability to write the message to std::ostream.
///
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
class record {
public:
	virtual logging::level level() const = 0;
	virtual char const * file() const = 0;
	virtual unsigned line() const = 0;
	virtual void write_message_to(std::ostream & out) const = 0;

	virtual ~record() {};
};

}

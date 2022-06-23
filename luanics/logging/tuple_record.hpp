#pragma once

#include "luanics/logging/record.hpp"

#include <iosfwd>
#include <memory>
#include <tuple>

namespace luanics::logging {

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///
/// @class record
///
/// @brief A logging::record that stores its message data in a tuple.
///
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
template <typename ... ParamsT>
class tuple_record : public record {
public:
	tuple_record(
		logging::level level,
		char const * const file,
		unsigned line,
		ParamsT && ... data
	);
	virtual logging::level level() const override final;
	virtual char const * file() const override final;
	virtual unsigned line() const override final;
	virtual void write_message_to(std::ostream & out) const override final;

private:
	logging::level _level;
	char const * const _file;
	unsigned  _line;
	std::tuple<ParamsT ...> _message_data;
};

template <typename ... ParamsT>
std::unique_ptr<record> make_tuple_record(
	logging::level level,
	char const * const file,
	unsigned line,
	ParamsT && ... data
);

}

#include "luanics/logging/tuple_record.ipp"

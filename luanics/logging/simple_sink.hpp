#pragma once

#include "sink.hpp"

namespace luanics::logging {

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///
/// @class simple_sink
///
/// @brief logging::sink suitable for single-threaded applications.
///
/// All records consumed are printed to std::ostream in same thread.
///
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
class simple_sink : public sink {
public:
	simple_sink(std::ostream * out);
	virtual void consume(std::unique_ptr<record> record) override final;

private:
	void write_level(record const & record);
	void write_file_and_line(record const & record);
	void write_data(record const & record);

	std::ostream * _out;
};

}

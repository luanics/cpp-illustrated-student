#include "luanics/logging/record.hpp"
#include "luanics/logging/simple_sink.hpp"
#include "luanics/utility/paths.hpp"

#include <iomanip>
#include <mutex>

namespace luanics::logging {

simple_sink::simple_sink(std::ostream * out) : _out{out} {}

void simple_sink::consume(std::unique_ptr<record> record) {
	write_level(*record);
	write_file_and_line(*record);
	write_data(*record);
	*_out << std::endl;
}

void simple_sink::write_level(record const & record) {
	*_out << "[" << std::setw(7) << std::left << record.level() << "] ";
}

void simple_sink::write_file_and_line(record const & record) {
	*_out << utility::file_name_from(record.file()) << ":" << record.line() << " - ";
}

void simple_sink::write_data(record const & record) {
	record.write_message_to(*_out);
}

}

#include "simple_sink.hpp"
#include "no_filter.hpp"
#include "simple_source.hpp"

#include <iostream>

namespace luanics {
namespace logging {

simple_source::simple_source() :
	_filter{new no_filter{}},
	_sink{new simple_sink{&std::cout}} {

}

void simple_source::submit(std::unique_ptr<record> record) {
	if (not _filter->is_accepting(*record)) {
		return;
	}
	_sink->consume(std::move(record));
}

void simple_source::set_filter(std::unique_ptr<filter> filter) {
	_filter = std::move(filter);
}

void simple_source::set_sink(std::unique_ptr<sink> sink) {
	_sink = std::move(sink);
}

} // namespace logging
} // namespace luanics

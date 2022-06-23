#include "luanics/logging/tuple_record.hpp"

#include "luanics/utility/tuples.hpp"

namespace luanics::logging {

template <typename ...ParamsT>
tuple_record<ParamsT...>::tuple_record(
	logging::level const level,
	char const * const file,
	unsigned const line,
	ParamsT && ... message_data
) :
	_level{level},
	_file{file},
	_line{line},
	_message_data(std::forward<ParamsT>(message_data)...)
{}

template <typename ...ParamsT>
logging::level tuple_record<ParamsT...>::level() const {
	return _level;
}

template <typename ...ParamsT>
char const * tuple_record<ParamsT...>::file() const {
	return _file;
}

template <typename ...ParamsT>
unsigned tuple_record<ParamsT...>::line() const {
	return _line;
}

template <typename ...ParamsT>
void tuple_record<ParamsT...>::write_message_to(std::ostream & out) const {
	luanics::utility::write_tuple(_message_data, out);
}

template <typename ... ParamsT>
std::unique_ptr<record> make_tuple_record(
	logging::level const level,
	char const * const file,
	unsigned const line,
	ParamsT && ... data
) {
	return std::make_unique<tuple_record<ParamsT...>>(level, file, line, std::forward<ParamsT>(data)...);
}

}

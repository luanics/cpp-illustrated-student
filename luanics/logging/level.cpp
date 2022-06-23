#include "luanics/logging/level.hpp"

#include <iostream>

namespace {

constexpr auto FATAL_STRING = "FATAL";
constexpr auto WARNING_STRING = "WARNING";
constexpr auto INFO_STRING = "INFO";
constexpr auto DEBUG_STRING = "DEBUG";

}

namespace luanics::logging {

std::ostream & operator<<(std::ostream & out, level const level) {
	switch (level) {
		case level::FATAL: out << FATAL_STRING; break;
		case level::WARNING: out << WARNING_STRING; break;
		case level::INFO: out << INFO_STRING; break;
		case level::DEBUG: out << DEBUG_STRING; break;
	}
	return out;
}

}

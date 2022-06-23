#pragma once

#include <iomanip>
#include <sstream>
#include <string>

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///
/// @file conversion.hpp
///
/// @brief Helper functions for converting to and from std::strings.
///
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

namespace luanics::string {

template <class T>
std::string to_string(T * t) {
	std::ostringstream out;
	out << "0x" << std::setw(16) << std::setfill('0') << std::hex << std::noshowbase;
	out << reinterpret_cast<uint64_t>(t);
	return out.str();
}

template <>
inline std::string to_string<char const>(char const * t) {
	return std::string(t);
}

template <class T>
std::string to_string(T const & t) {
	std::ostringstream out;
	out << t;
	return out.str();
}

std::string to_string(const bool value);

inline std::string to_string(double const value) {
	std::ostringstream out;
	out.precision(2);
	out << std::fixed << value;
	return out.str();
}

inline std::string to_string(float const value) {
	std::ostringstream out;
	out.precision(2);
	out << std::fixed << value;
	return out.str();
}

template <class T>
T from_string(std::string const & s) {
	std::istringstream in(s);
	T result;
	in >> result;
	return result;
}

}

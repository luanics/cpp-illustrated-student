#include "luanics/utility/streams.hpp"

namespace {

bool _is_using_ansi_codes = true;

static constexpr char const * PLAIN = "\033[0m";
static constexpr char const * BLACK = "\033[30m";
static constexpr char const * RED = "\033[31m";
static constexpr char const * GREEN = "\033[32m";
static constexpr char const * BROWN = "\033[33m";
static constexpr char const * BLUE = "\033[34m";
static constexpr char const * MAGENTA = "\033[35m";
static constexpr char const * CYAN = "\033[36m";
static constexpr char const * LIGHT_GRAY = "\033[37m";
static constexpr char const * DARK_GRAY  = "\033[1m\033[30m";
static constexpr char const * BOLD_RED = "\033[1m\033[31m";
static constexpr char const * BOLD_GREEN = "\033[1m\033[32m";
static constexpr char const * BOLD_YELLOW = "\033[1m\033[33m";
static constexpr char const * BOLD_BLUE = "\033[1m\033[34m";
static constexpr char const * BOLD_MAGENTA = "\033[1m\033[35m";
static constexpr char const * BOLD_CYAN = "\033[1m\033[36m";
static constexpr char const * WHITE = "\033[1m\033[37m";

}

namespace luanics::utility::streams {

void reset(std::ostringstream & out, std::string const & value) {
	out.str(value);
	out.clear();
}

void reset(std::istringstream & in, std::string const & value) {
	in.str(value);
	in.clear();
}

bool is_using_ansi_codes() {
	return _is_using_ansi_codes;
}

void set_is_using_ansi_codes(bool value) {
	_is_using_ansi_codes = value;
}

std::ostream & plain(std::ostream & out) {
	if (is_using_ansi_codes()) out << PLAIN;
	return out;
}

std::ostream & black(std::ostream & out) {
	if (is_using_ansi_codes()) out << BLACK;
	return out;
}

std::ostream & light_gray(std::ostream & out) {
	if (is_using_ansi_codes()) out << LIGHT_GRAY;
	return out;
}

std::ostream & dark_gray(std::ostream & out) {
	if (is_using_ansi_codes()) out << DARK_GRAY;
	return out;
}

std::ostream & white(std::ostream & out) {
	if (is_using_ansi_codes()) out << WHITE;
	return out;
}

std::ostream & red(std::ostream & out) {
	if (is_using_ansi_codes()) out << RED;
	return out;
}

std::ostream & green(std::ostream & out) {
	if (is_using_ansi_codes()) out << GREEN;
	return out;
}

std::ostream & brown(std::ostream & out) {
	if (is_using_ansi_codes()) out << BROWN;
	return out;
}

std::ostream & blue(std::ostream & out) {
	if (is_using_ansi_codes()) out << BLUE;
	return out;
}

std::ostream & magenta(std::ostream & out) {
	if (is_using_ansi_codes()) out << MAGENTA;
	return out;
}

std::ostream & cyan(std::ostream & out) {
	if (is_using_ansi_codes()) out << CYAN;
	return out;
}

std::ostream & bold_red(std::ostream & out) {
	if (is_using_ansi_codes()) out << BOLD_RED;
	return out;
}

std::ostream & bold_green(std::ostream & out) {
	if (is_using_ansi_codes()) out << BOLD_GREEN;
	return out;
}

std::ostream & bold_yellow(std::ostream & out) {
	if (is_using_ansi_codes()) out << BOLD_YELLOW;
	return out;
}

std::ostream & bold_blue(std::ostream & out) {
	if (is_using_ansi_codes()) out << BOLD_BLUE;
	return out;
}

std::ostream & bold_magenta(std::ostream & out) {
	if (is_using_ansi_codes()) out << BOLD_MAGENTA;
	return out;
}

std::ostream & bold_cyan(std::ostream & out) {
	if (is_using_ansi_codes()) out << BOLD_CYAN;
	return out;
}

}

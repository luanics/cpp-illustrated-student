#pragma once

#include <iostream>
#include <sstream>

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///
/// @file utility::streams
///
/// @brief An assortment of helper functions for iostreams.
///
/// * "reset" functions for stringstreams
/// * "color manip" functions for ostream
///   * Can toggle global behavior with set_is_using_ansi_codes(bool).
///   * Set up as io manipulators, so can apply like this:
///     std::cout << green << "Happy St. Patrick's Day!" << plain << std::endl;
///
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

namespace luanics::utility::streams {

/// Sets "out" to a new value (empty by default)
void reset(std::ostringstream & out, std::string const & value = "");
/// Sets "in" to a new value (empty by default)
void reset(std::istringstream & in, std::string const & value = "");

bool is_using_ansi_codes();
void set_is_using_ansi_codes(bool value);

std::ostream & plain(std::ostream & out);

std::ostream & black(std::ostream & out);
std::ostream & light_gray(std::ostream & out);
std::ostream & dark_gray(std::ostream & out);
std::ostream & white(std::ostream & out);

std::ostream & red(std::ostream & out);
std::ostream & green(std::ostream & out);
std::ostream & brown(std::ostream & out);
std::ostream & blue(std::ostream & out);
std::ostream & magenta(std::ostream & out);
std::ostream & cyan(std::ostream & out);

std::ostream & bold_red(std::ostream & out);
std::ostream & bold_green(std::ostream & out);
std::ostream & bold_yellow(std::ostream & out);
std::ostream & bold_blue(std::ostream & out);
std::ostream & bold_magenta(std::ostream & out);
std::ostream & bold_cyan(std::ostream & out);

}

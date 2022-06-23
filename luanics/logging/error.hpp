#pragma once

#include <stdexcept>

namespace luanics {

class error : public std::runtime_error {
public:
	error(std::string const & message) : std::runtime_error{message} {}
};

class precondition_violation : public error {
public:
	precondition_violation(std::string const & message) : error{message} {}
};

class postcondition_violation : public error {
public:
	postcondition_violation(std::string const & message) : error{message} {}
};

}

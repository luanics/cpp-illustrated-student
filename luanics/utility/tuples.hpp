#pragma once

#include <iostream>
#include <string_view>
#include <tuple>

namespace luanics::utility {

template <typename ... ParamsT>
void write_tuple(
	std::tuple<ParamsT...> const & values,
	std::ostream & out,
	std::string_view delimiter = " "
);

}

namespace std {

template <typename ... ParamsT>
std::ostream & operator<<(std::ostream & out, std::tuple<ParamsT...> const & values);

}

#include "luanics/utility/tuples.ipp"

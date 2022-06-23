#pragma once

#include "luanics/meta/detection.hpp"
#include "luanics/string/conversion.hpp"

namespace luanics::string {

namespace detail {

template<typename T>
using to_string_t = decltype(to_string(std::declval<T>()));

template <typename T>
constexpr bool has_to_string_v = is_detected_v<to_string_t, T>;

}

template <typename T>
std::enable_if_t<detail::has_to_string_v<T>, std::string> stringify(T const & t) {
	return to_string(t);
}

template <typename T>
std::enable_if_t<not detail::has_to_string_v<T>, std::string> stringify(T const & t) {
	return typeid(T).name();
}

} // namespace luanics::utility

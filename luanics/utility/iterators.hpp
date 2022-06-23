#pragma once

#include <iterator>

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///
/// @file Iterators.hpp
///
/// @brief Helper functions for iteration.
///
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

namespace luanics::utility {

template <typename T>
struct reverse_wrapper {T & wrapped;};

template <typename T>
auto begin(reverse_wrapper<T> wrapper) {return std::rbegin(wrapper.wrapped);}

template <typename T>
auto end(reverse_wrapper<T> wrapper) {return std::rend(wrapper.wrapped);}

/// Provides means of reverse iterations in a range-based for loop
/// Example usage:
///  for (int x: reverse(numbers)) {}
template <typename T>
reverse_wrapper<T> reverse(T && t) {return {t};}

} // namespace luanics::utility

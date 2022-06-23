#include <iostream>
#include <type_traits>

namespace luanics::detail {

template<typename T>
using stream_insert_t = decltype(std::declval<std::ostream &>() << std::declval<T>());

}

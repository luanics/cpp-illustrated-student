#pragma once

#include "luanics/meta/detection.hpp"
#include "luanics/meta/type_traits.ipp"

namespace luanics {

template<typename T>
constexpr bool is_stream_insertable_v = is_detected_v<detail::stream_insert_t, T>;

}

#pragma once

#include "luanics/meta/detection.ipp"

namespace luanics {

/// Implementation of Walter Brown's detection toolkit.
/// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/n4436.pdf

template<template<typename ...> class OpT, typename ...ArgsT>
using is_detected = detail::detector<void, OpT, ArgsT...>;

template<template<typename ...> class OpT, typename ...ArgsT>
bool constexpr is_detected_v = is_detected<OpT, ArgsT...>::value;

template<template<typename ...> class OpT, typename ...ArgsT >
using detected_t = typename is_detected<OpT, ArgsT...>::type;

}

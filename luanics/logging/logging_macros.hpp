///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///
/// @file LoggingMacros.hpp
///
/// @brief Logging macros decorated with LUANICS_ for safety.
///
/// @see Logging.hpp
///
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include "luanics/logging/logger.hpp"
#include "luanics/logging/tuple_record.hpp"

#include <iostream>

#ifdef LUANICS_LOGGING
	#define LUANICS_LOG(level, ...) \
		luanics::logging::logger().submit(luanics::logging::make_tuple_record(level, __FILE__, __LINE__, __VA_ARGS__));
#else
	#define LUANICS_LOG(level, ...)
#endif

#define LUANICS_FATAL(...) LUANICS_LOG(luanics::logging::level::FATAL, __VA_ARGS__)
#define LUANICS_WARNING(...) LUANICS_LOG(luanics::logging::level::WARNING, __VA_ARGS__)
#define LUANICS_INFO(...) LUANICS_LOG(luanics::logging::level::INFO, __VA_ARGS__)
#define LUANICS_DEBUG(...) LUANICS_LOG(luanics::logging::level::DEBUG, __VA_ARGS__)

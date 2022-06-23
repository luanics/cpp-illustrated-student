#pragma once

#include "luanics/logging/filter.hpp"
#include "luanics/logging/record.hpp"
#include "luanics/logging/sink.hpp"
#include "luanics/logging/source.hpp"

#include <iostream>
#include <memory>

namespace luanics::logging {

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///
/// @class simple_source
///
/// @brief logging::source suitable for single-threaded applications.
///
/// All records submitted are immediately handed off to sink in same thread.
///
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
class simple_source : public source {
public:
	simple_source(); ///< Installs no_filter and simple_sink

	virtual void submit(std::unique_ptr<record> record) override final;
	virtual void set_filter(std::unique_ptr<filter> filter) override final;
	virtual void set_sink(std::unique_ptr<sink> sink) override final;

private:
	std::unique_ptr<filter> _filter;
	std::unique_ptr<sink> _sink;
}; // class SimpleSource

}  // namespace luanics::logging

#pragma once

namespace luanics::testing::core {

class component;
class error;
class log;
class result;

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
///
/// @class reporter
///
/// @brief Gathers the results of running the test hierarchy.
///
/// Uses Hierarchical Visitor pattern.
///
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
class reporter {
public:
	virtual ~reporter() = default;

	/// @return false if wants to skip this component
	virtual bool start_report_on(component const & component) = 0;
	/// NOT called if startReportOn() returns false.
	virtual void finish_report_on(component const & component) = 0;

	virtual void record(error const & error) = 0;
	virtual void record(log const & log) = 0;
	virtual void record(result const & result) = 0;
};

} // namespace luanics::testing::core

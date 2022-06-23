#pragma once

#include "../../../logging/contract.hpp"
#include "luanics/testing/core/error.hpp"
#include "luanics/testing/core/log.hpp"
#include "luanics/testing/core/result.hpp"
#include "luanics/testing/core/augmented_reporter.hpp"

#include <map>
#include <optional>
#include <string>
#include <vector>

namespace luanics::testing::core {

/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
///
/// @class spy_augmented_reporter
///
/// @brief Test double for augmented_reporter that keeps track of calls.
///
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
class spy_augmented_reporter final : public augmented_reporter {
public:
	using start_report_params = std::tuple<std::string, unsigned>;
	using finish_report_params = std::tuple<std::string, unsigned, outcome>;

	std::vector<start_report_params> const & calls_to_start_report() const {return _calls_to_start_report;}
	std::vector<finish_report_params> const & calls_to_finish_report() const {return _calls_to_finish_report;}
	std::vector<core::error> const & calls_to_record_error() const {return _calls_to_record_error;}
	std::vector<core::log> const & calls_to_record_log() const {return _calls_to_record_log;}
	std::vector<core::result> const & calls_to_record_result() const {return _calls_to_record_result;}

	virtual bool start_report_on(
		component const & component,
		unsigned const depth
	) {
		 _calls_to_start_report.emplace_back(component.name(), depth);
		return true;
	}
	virtual void finish_report_on(
		component const & component,
		unsigned const depth,
		outcome const outcome
	) {
		_calls_to_finish_report.emplace_back(component.name(), depth, outcome);
	}
	virtual void record(core::error const & error) {
		_calls_to_record_error.push_back(error);
	}
	virtual void record(core::log const & log) {
		_calls_to_record_log.push_back(log);
	}
	virtual void record(core::result const & result) {
		_calls_to_record_result.push_back(result);
	}

private:
	std::vector<start_report_params> _calls_to_start_report;
	std::vector<finish_report_params> _calls_to_finish_report;
	std::vector<core::error> _calls_to_record_error;
	std::vector<core::log> _calls_to_record_log;
	std::vector<core::result> _calls_to_record_result;

};

}

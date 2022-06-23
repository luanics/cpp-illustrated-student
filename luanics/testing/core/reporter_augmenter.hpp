#pragma once

#include "luanics/testing/core/outcome.hpp"
#include "luanics/testing/core/reporter.hpp"

#include <stack>

namespace luanics::testing::core {

class augmented_reporter;

/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
///
/// @class reporter_augmenter
///
/// @brief Adapts \tag{reporter} interface to the augmented_reporter interface.
///
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
class reporter_augmenter : public reporter {
public:
	reporter_augmenter(augmented_reporter * adapted);

	virtual bool start_report_on(component const & component) override final;
	virtual void finish_report_on(component const & component) override final;

	virtual void record(error const & error) final;
	virtual void record(log const & log) final;
	virtual void record(result const & result) final;

private:
	unsigned depth() const;

	augmented_reporter * _adapted;
	std::stack<outcome> _outcomes;
}; // class ReporterAugmenter

} // namespace luanics::testing::core

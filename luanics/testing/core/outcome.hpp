#pragma once

#include <iostream>

namespace luanics::testing::core {

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///
/// @class outcome
///
/// @brief An outcome of the testing framework.
///
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
enum class outcome {
	NONE, ///< All children have NONE outcome
	PASS, ///< At least one child has PASS outcome - beats NONE
	FAIL, ///< At least one child has FAIL outcome - beats PASS
	ERROR ///< At least one child has ERROR outcome - beats FAIL
};

outcome combined(outcome lhs, outcome rhs);

std::ostream & operator<<(std::ostream & out, outcome outcome);

} // namespace luanics::testing::core

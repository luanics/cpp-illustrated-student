#include "luanics/logging/contract.hpp"
#include "luanics/testing/unit.hpp"

namespace luanics::logging {

BEGIN_TEST_SET(contract)

TEST(all) {
	bool is_exception_thrown = false;
	try {
		LUANICS_EXPECTS(false);
	}
	catch (luanics::error const & error) {
		is_exception_thrown = true;
	}
	EXPECT_TRUE(is_exception_thrown);
}

END_TEST_SET(contract)

}

#include "luanics/testing/unit.hpp"
#include "luanics/testing/core/outcome.hpp"

namespace luanics::testing::core {

BEGIN_TEST_SET(outcome)

TEST(combine) {
	EXPECT_EQ(outcome::NONE, combined(outcome::NONE, outcome::NONE));
	EXPECT_EQ(outcome::PASS, combined(outcome::PASS, outcome::NONE));
	EXPECT_EQ(outcome::PASS, combined(outcome::NONE, outcome::PASS));
	EXPECT_EQ(outcome::PASS, combined(outcome::PASS, outcome::PASS));
	EXPECT_EQ(outcome::FAIL, combined(outcome::FAIL, outcome::NONE));
	EXPECT_EQ(outcome::FAIL, combined(outcome::FAIL, outcome::PASS));
	EXPECT_EQ(outcome::FAIL, combined(outcome::FAIL, outcome::FAIL));
	EXPECT_EQ(outcome::ERROR, combined(outcome::ERROR, outcome::NONE));
	EXPECT_EQ(outcome::ERROR, combined(outcome::ERROR, outcome::PASS));
	EXPECT_EQ(outcome::ERROR, combined(outcome::ERROR, outcome::FAIL));
	EXPECT_EQ(outcome::ERROR, combined(outcome::ERROR, outcome::ERROR));
}

END_TEST_SET(outcome)

}

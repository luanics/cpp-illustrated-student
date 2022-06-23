#include "luanics/math/operations.hpp"
#include "luanics/testing/unit.hpp"

namespace luanics::math {

BEGIN_TEST_SET(operations)

TEST(positive_modulo) {
	EXPECT_EQ(2, positive_modulo(5,3));
	EXPECT_EQ(1, positive_modulo(4,3));
	EXPECT_EQ(0, positive_modulo(3,3));
}

TEST(sign) {
	EXPECT_EQ(-1, sign(-100.0));
	EXPECT_EQ(-1, sign(-100));
	EXPECT_EQ(0, sign(0.0));
	EXPECT_EQ(0.0, sign(0));
	EXPECT_EQ(1, sign(100.0));
	EXPECT_EQ(1, sign(100));
}

END_TEST_SET(operations)

}

#include "luanics/crypto/helpers.hpp"
#include "luanics/testing/unit.hpp"

namespace luanics::crypto {

BEGIN_TEST_SET(helpers)

TEST(distance_from_a) {
	EXPECT_EQ(0, distance_from_a('a'));
	EXPECT_EQ(25, distance_from_a('z'));
	EXPECT_THROW(distance_from_a('1'));
	EXPECT_THROW(distance_from_a('%'));
	EXPECT_THROW(distance_from_a('A'));
}

TEST(shift) {
	EXPECT_EQ('c', shift('a', 2));
	EXPECT_EQ('a', shift('y', 2));

	EXPECT_EQ('y', shift('a', -2));
	EXPECT_EQ('a', shift('c', -2));
}

END_TEST_SET(helpers)

}

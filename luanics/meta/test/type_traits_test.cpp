#include "luanics/meta/type_traits.hpp"
#include "luanics/testing/unit.hpp"

#include <iostream>
#include <type_traits>

using namespace luanics;

BEGIN_TEST_SET(type_traits)

class Empty {};

TEST(all) {
	bool const is_int_stream_insertable = is_stream_insertable_v<int>;
	EXPECT_TRUE(is_int_stream_insertable);

	bool const is_empty_stream_insertable = is_stream_insertable_v<Empty>;
	EXPECT_FALSE(is_empty_stream_insertable);
}

END_TEST_SET(type_traits)

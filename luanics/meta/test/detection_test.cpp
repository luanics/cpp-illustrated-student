#include "luanics/meta/detection.hpp"
#include "luanics/testing/unit.hpp"

#include <iostream>
#include <type_traits>

namespace luanics {
namespace {

BEGIN_TEST_SET(detection)

template <typename T>
using increment_t = decltype(++std::declval<T&>());

template<typename T>
using ostream_t = decltype(std::declval<std::ostream &>() << std::declval<T>());

class empty {};

TEST(all) {
	bool const is_incrementable = is_detected_v<increment_t, int>;
	EXPECT_TRUE(is_incrementable);

	bool const is_empty_incrementable = is_detected_v<increment_t, empty>;
	EXPECT_FALSE(is_empty_incrementable);

	bool const is_int_ostreamable = is_detected_v<ostream_t, int>;
	EXPECT_TRUE(is_int_ostreamable);

	bool const is_empty_ostreamable = is_detected_v<ostream_t, empty>;
	EXPECT_FALSE(is_empty_ostreamable);

	bool const is_void_ostreamable = is_detected_v<ostream_t, void>;
	EXPECT_FALSE(is_void_ostreamable);
}

END_TEST_SET(detection)

}
}

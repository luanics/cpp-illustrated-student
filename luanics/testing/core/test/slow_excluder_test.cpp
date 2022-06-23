#include "luanics/testing/core/test/dummy_component.hpp"
#include "luanics/testing/core/test/spy_augmented_reporter.hpp"
#include "luanics/testing/core/slow_excluder.hpp"
#include "luanics/testing/unit.hpp"

namespace luanics::testing::core {

BEGIN_TEST_SET(slow_excluder)

enum level {
	TEST_SUITE = 0,
	TEST_SET = 1,
	TEST = 2
};

TEST(all) {
	spy_augmented_reporter reporter{};

	slow_excluder filter{&reporter};

	EXPECT_EQ(0, reporter.calls_to_start_report().size());

	bool const is_starting_fast_test = filter.start_report_on(dummy_component{"fast", false}, TEST);
	EXPECT_TRUE(is_starting_fast_test);
	EXPECT_EQ(1, reporter.calls_to_start_report().size());

bool const is_starting_slow_test = filter.start_report_on(dummy_component{"slow", true}, TEST);
	EXPECT_FALSE(is_starting_slow_test);
	EXPECT_EQ(1, reporter.calls_to_start_report().size());
}

END_TEST_SET(slow_excluder)

}

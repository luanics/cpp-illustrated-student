#include "luanics/testing/core/string_matcher.hpp"
#include "luanics/testing/core/test/dummy_component.hpp"
#include "luanics/testing/core/test/spy_augmented_reporter.hpp"
#include "luanics/string/enumerated_matcher.hpp"
#include "luanics/testing/unit.hpp"

namespace luanics::testing::core {

BEGIN_TEST_SET(string_matcher_tutorial)

enum level {
	TEST_SUITE = 0,
	TEST_SET = 1,
	TEST = 2
};

TEST(All) {
	spy_augmented_reporter reporter{};

	string_matcher::matchers_by_depth matchers;
	matchers.emplace(1, std::make_unique<string::enumerated_matcher>(std::vector<std::string>{"cat", "dog"}));
	matchers.emplace(2, std::make_unique<string::enumerated_matcher>(std::vector<std::string>{"black", "white"}));

	string_matcher filter{&reporter, std::move(matchers)};

	EXPECT_EQ(0, reporter.calls_to_start_report().size());
	filter.start_report_on(dummy_component{"suite"}, TEST_SUITE);
	EXPECT_EQ(1, reporter.calls_to_start_report().size());

	bool const is_starting_fish_test_set = filter.start_report_on(dummy_component{"fish"}, TEST_SET);
	EXPECT_FALSE(is_starting_fish_test_set);
	EXPECT_EQ(1, reporter.calls_to_start_report().size());

	bool const is_starting_dog_test_set = filter.start_report_on(dummy_component{"dog"}, TEST_SET);
	EXPECT_TRUE(is_starting_dog_test_set);
	EXPECT_EQ(2, reporter.calls_to_start_report().size());

	bool const is_starting_green_test = filter.start_report_on(dummy_component{"green"}, TEST);
	EXPECT_FALSE(is_starting_green_test);
	EXPECT_EQ(2, reporter.calls_to_start_report().size());

	bool const is_starting_black_test = filter.start_report_on(dummy_component{"black"}, TEST);
	EXPECT_TRUE(is_starting_black_test);
	EXPECT_EQ(3, reporter.calls_to_start_report().size());

	EXPECT_EQ(0, reporter.calls_to_record_result().size());
	filter.record(core::result{false, "", 0, ""});
	EXPECT_EQ(1, reporter.calls_to_record_result().size());

	EXPECT_EQ(0, reporter.calls_to_finish_report().size());
	filter.finish_report_on(dummy_component{"dog"}, TEST_SET, outcome::FAIL);
	EXPECT_EQ(1, reporter.calls_to_finish_report().size());

	filter.finish_report_on(dummy_component{"suite"}, TEST_SUITE, outcome::FAIL);
	EXPECT_EQ(2, reporter.calls_to_finish_report().size());
}

END_TEST_SET(string_matcher_tutorial)

}

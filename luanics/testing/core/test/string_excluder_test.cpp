#include "luanics/testing/core/test/dummy_component.hpp"
#include "luanics/testing/core/test/spy_augmented_reporter.hpp"
#include "luanics/testing/core/string_excluder.hpp"
#include "luanics/testing/unit.hpp"

namespace luanics::testing::core {
namespace {

BEGIN_TEST_SET(string_excluder)

enum level {
	TEST_SUITE = 0,
	TEST_SET = 1,
	TEST = 2
};

TEST(all) {
	spy_augmented_reporter reporter{};

	string_excluder filter{&reporter, "tutorial"};

	EXPECT_EQ(0, reporter.calls_to_start_report().size());
	filter.start_report_on(dummy_component{"suite"}, TEST_SUITE);
	EXPECT_EQ(1, reporter.calls_to_start_report().size());

	bool const isStartingFishTestSet = filter.start_report_on(dummy_component{"fish_tutorial"}, TEST_SET);
	EXPECT_FALSE(isStartingFishTestSet);
	EXPECT_EQ(1, reporter.calls_to_start_report().size());

	bool const isStartingDogTestSet = filter.start_report_on(dummy_component{"dog"}, TEST_SET);
	EXPECT_TRUE(isStartingDogTestSet);
	EXPECT_EQ(2, reporter.calls_to_start_report().size());

	bool const isStartingGreenTest = filter.start_report_on(dummy_component{"green_tutorial"}, TEST);
	EXPECT_FALSE(isStartingGreenTest);
	EXPECT_EQ(2, reporter.calls_to_start_report().size());

	bool const isStartingBlackTest = filter.start_report_on(dummy_component{"black"}, TEST);
	EXPECT_TRUE(isStartingBlackTest);
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

END_TEST_SET(string_excluder)

}
}

#include "luanics/testing/unit.hpp"
#include "luanics/testing/core/reporter_augmenter.hpp"
#include "luanics/testing/core/string_excluder.hpp"
#include "luanics/testing/unit/standard_reporter.hpp"

#include <iostream>

int main() {
	bool const is_using_color = true;
	bool const is_terse = false;

	luanics::testing::unit::standard_reporter reporter{&std::cout, is_using_color, is_terse};
	luanics::testing::core::string_excluder filter{&reporter, "tutorial"};
	luanics::testing::core::reporter_augmenter augmenter{&filter};
	luanics::testing::unit::suite_instance().run(augmenter);

	auto result = reporter.num_tests_failed() == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
	return result;
}

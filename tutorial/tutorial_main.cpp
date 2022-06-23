#include "luanics/testing/core/first_fail_detector.hpp"
#include "luanics/testing/core/indenting_reporter.hpp"
#include "luanics/testing/core/reporter_augmenter.hpp"
#include "luanics/testing/tutorial.hpp"
#include "luanics/utility/streams.hpp"

#include <algorithm>
#include <cstring>
#include <iostream>
#include <iterator>

using namespace luanics::testing::core;
using namespace luanics;
using namespace std;

constexpr const char * no_color_option_key = "--no-color";
constexpr const char * hints_option_key = "--hints";
constexpr const char * run_all_option_key = "--run-all";
constexpr const char * help_option_key = "--help";
std::vector<const char *> option_keys{
	no_color_option_key,
	hints_option_key,
	run_all_option_key,
	help_option_key
};

ADD_TUTORIAL(Tutorial)

ADD_PART(Basics, true)
ADD_CHAPTER(Basics, GettingStarted, true)
ADD_CHAPTER(Basics, Statements, true)
ADD_CHAPTER(Basics, Building, true)
ADD_CHAPTER(Basics, Variables, true)
ADD_CHAPTER(Basics, Directives, true)
ADD_CHAPTER(Basics, Objects, true)
ADD_CHAPTER(Basics, References, true)
ADD_CHAPTER(Basics, Grid, true)

ADD_PART(MoreBasics, true)
ADD_CHAPTER(MoreBasics, ControlFlow, true)
ADD_CHAPTER(MoreBasics, Expressions, true)
ADD_CHAPTER(MoreBasics, Functions, true)

int main(int argc, char * argv[]) {
	//*********************************************************
	// Parse options
	//*********************************************************

	bool is_using_color = true;
	bool is_using_first_fail = true;
	bool is_showing_hints = false;

	for (int i = 1; i < argc; ++i) {
		if (strcmp(no_color_option_key, argv[i]) == 0) {
			is_using_color = false;
		}
		else if (strcmp(hints_option_key, argv[i]) == 0) {
			is_showing_hints = true;
		}
		else if (strcmp(run_all_option_key, argv[i]) == 0) {
			is_using_first_fail = false;
		}
		else if (strcmp(help_option_key, argv[i]) == 0) {
			std::cout << "C++ Illustrated Tutorial" << std::endl;
			std::cout << "options:";
			std::copy(begin(option_keys), end(option_keys), ostream_iterator<const char *>(std::cout, ","));
			std::cout << std::endl;
			return 0;
		}
	}

	//*********************************************************
	// Run tutorial
	//*********************************************************

	luanics::utility::streams::set_is_using_ansi_codes(is_using_color);
	luanics::testing::core::indenting_reporter unfiltered(&cout, is_showing_hints);
	luanics::testing::core::first_fail_detector filtered(&unfiltered);
	using luanics::testing::core::augmented_reporter;
	augmented_reporter * reporter = is_using_first_fail ? static_cast<augmented_reporter*>(&filtered) : static_cast<augmented_reporter*>(&unfiltered);
	luanics::testing::core::reporter_augmenter augmenter(reporter);
	tutorial.run(augmenter);

	return 0;
}

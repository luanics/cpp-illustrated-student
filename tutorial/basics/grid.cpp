#include "luanics/grid/dynamic_grid.hpp"
#include "luanics/grid/sub_grid.hpp"
#include "luanics/testing/tutorial.hpp"

#include <sstream>

using namespace luanics::grid;
using namespace std;

BEGIN_CHAPTER(Grid)

SECTION(dynamic_grid) {

	// Create a dynamic_grid that matches this output...
	std::string expected_box_output{
		"****" "\n"
		"****" "\n"
	};
	// This can be done in two statements
	FIX(
		dynamic_grid box;
		
	)
	std::ostringstream actual_box_output;
	actual_box_output << box;
	EXPECT_EQ(expected_box_output, actual_box_output.str());

	// Create a dynamic_grid that matches this output...
	std::string expected_smile_output{
		"*  *" "\n"
		"****" "\n"
	};
	// This can be done in four statements
	FIX(
		dynamic_grid smile;
		
	)
	std::ostringstream actual_smile_output;
	actual_smile_output << smile;
	EXPECT_EQ(expected_smile_output, actual_smile_output.str());
}

SECTION(sub_grid) {
	// Match the following output using a dynamic_grid and sub_grid...
	std::string expected_window_output{
		"*****" "\n"
		"*...*" "\n"
		"*...*" "\n"
		"*...*" "\n"
		"*****" "\n"
	};
	// This can be done with four statements
	FIX(
		dynamic_grid window;
		
	)
	std::ostringstream actual_window_output;
	actual_window_output << window;
	EXPECT_EQ(expected_window_output, actual_window_output.str());
}

END_CHAPTER(Grid)

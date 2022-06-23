#include "luanics/grid/dynamic_grid.hpp"
#include "luanics/grid/flipped_grid.hpp"
#include "luanics/testing/unit.hpp"

#include <sstream>

namespace luanics::grid {

BEGIN_TEST_SET(flipped_grid_tutorial)

TEST(all) {
	dynamic_grid unflipped{4, 3};
	flipped_grid grid{&unflipped};
	EXPECT_EQ(4, grid.width());
	EXPECT_EQ(3, grid.height());
	EXPECT_THROW(grid(4,3));

	std::istringstream in{
		"*..." "\n"
		"...." "\n"
		"...." "\n"
	};
	in >> grid;
	EXPECT_EQ('*', grid(0,0));
	EXPECT_EQ('.', grid(3,2));

	grid(3,2) = '@';
	std::ostringstream out;
	out << grid;
	std::string const expected_out{
		"*..." "\n"
		"...." "\n"
		"...@" "\n"
	};
	EXPECT_EQ(expected_out, out.str());
}

END_TEST_SET(flipped_grid)

} // namespace luanics::grid

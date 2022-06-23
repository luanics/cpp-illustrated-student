#include "luanics/grid/grid.hpp"
#include "luanics/grid/dynamic_grid.hpp"
#include "luanics/testing/unit.hpp"

#include <iostream>
#include <sstream>

namespace luanics::grid {
namespace {

BEGIN_TEST_SET(grid)

TEST(io) {
	std::string data{
		"ab\n"
		"cd\n"
	};
	dynamic_grid grid;
	// test operator>>
	std::istringstream in{data};
	in >> grid;
	EXPECT_EQ(2, grid.width());
	EXPECT_EQ(2, grid.height());
	EXPECT_EQ('c', grid(0,0));
	EXPECT_EQ('d', grid(1,0));
	EXPECT_EQ('a', grid(0,1));
	EXPECT_EQ('b', grid(1,1));

	// test operator<<
	std::ostringstream out;
	out << grid;
	EXPECT_EQ(data, out.str());
}

TEST(comparison) {
	dynamic_grid one_by_two{1,2};
	dynamic_grid two_by_one{2,1};
	EXPECT_EQ(one_by_two, one_by_two);
	EXPECT_NE(one_by_two, two_by_one);
	dynamic_grid another_one_by_two{1,2};
	another_one_by_two(0,1) = '*';
	EXPECT_NE(one_by_two, another_one_by_two);
}

END_TEST_SET(grid)

} // namespace
} // namespace luanics::grid

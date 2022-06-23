#include "luanics/grid/dynamic_grid.hpp"
#include "luanics/testing/unit.hpp"

#include <iostream>
#include <sstream>

namespace luanics::grid {
namespace {

BEGIN_TEST_SET(dynamic_grid)

TEST(basics) {
	dynamic_grid grid(5, 5);
	EXPECT_EQ(5, grid.width());
	EXPECT_EQ(5, grid.height());

	char const star = '*';
	char const dot = '.';
	grid(1,1) = star;
	grid(2,2) = dot;
	EXPECT_EQ(star, grid(1,1));
}

TEST(fill_with) {
	dynamic_grid grid(5,5);
	char const dot = '.';
	grid.fill_with(dot);
	EXPECT_EQ(dot, grid(1,1));
	EXPECT_EQ(dot, grid(4,4));
}

TEST(write_to) {
	dynamic_grid grid(5, 3);
	char const dot = '.';
	grid.fill_with(dot);
	char const star = '*';
	grid(3, 2) = star;
	std::string const expected =
		"...*.\n"
		".....\n"
		".....\n";
	std::ostringstream out;
	grid.write_to(out);
	EXPECT_EQ(expected, out.str());
	// Having problems here? Make sure you have operator() defined correctly!
}

TEST(read_from) {
	std::string const data =
		".*...\n"
		".....\n"
		".....\n";
	std::istringstream in(data);
	dynamic_grid grid(5, 3);
	grid.read_from(in);
	char const star = '*';
	char const dot = '.';
	EXPECT_EQ(5, grid.width());
	EXPECT_EQ(3, grid.height());
	EXPECT_EQ(star, grid(1,2));
	EXPECT_EQ(dot, grid(0,0));
}

END_TEST_SET(dynamic_grid)

} // namespace
} // namespace luanics::grid

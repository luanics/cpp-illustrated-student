#include "luanics/grid/sub_grid.hpp"
#include "luanics/grid/dynamic_grid.hpp"
#include "luanics/testing/unit.hpp"
#include "luanics/utility/streams.hpp"

#include <iostream>
#include <sstream>

namespace luanics::grid {

BEGIN_TEST_SET(sub_grid)

TEST(parents) {
	dynamic_grid parent{5, 5};
	sub_grid sub{3, 3, 1, 1, &parent};
	EXPECT_EQ(3, sub.width());
	EXPECT_EQ(3, sub.height());
	EXPECT_EQ(1, sub.x_offset());
	EXPECT_EQ(1, sub.y_offset());

	EXPECT_EQ(grid::empty_value, parent(1,1));
	EXPECT_EQ(grid::empty_value, sub(0,0));
	EXPECT_EQ(grid::empty_value, parent(3,3));
	EXPECT_EQ(grid::empty_value, sub(2,2));
	EXPECT_EQ(grid::empty_value, parent(3,2));
	EXPECT_EQ(grid::empty_value, sub(2,1));

	char const star = '*';
	char const dot = '.';
	char const hash = '#';
	sub(0,0) = star;
	sub(2,2) = dot;
	sub(1,2) = hash;
	EXPECT_EQ(star, parent(1,1));
	EXPECT_EQ(star, sub(0,0));
	EXPECT_EQ(dot, parent(3,3));
	EXPECT_EQ(dot, sub(2,2));
	EXPECT_EQ(hash, parent(2,3));
	EXPECT_EQ(hash, sub(1,2));
}

TEST(fill_with) {
	dynamic_grid parent{5, 5};
	sub_grid sub{3, 3, 1, 1, &parent};
	char const dot = '.';
	sub.fill_with(dot);
	EXPECT_EQ(dot, parent(1,1));
	EXPECT_EQ(dot, sub(0,0));
	EXPECT_EQ(dot, parent(3,3));
	EXPECT_EQ(dot, sub(2,2));
}

TEST(write) {
	dynamic_grid parent{5, 5};
	sub_grid sub{3, 3, 1, 1, &parent};
	char const dot = '.';
	parent.fill_with(dot);

	std::ostringstream out;
	out << sub;
	std::string expected =
		"...\n"
		"...\n"
		"...\n"
	;
	EXPECT_EQ(expected, out.str());

	utility::streams::reset(out);
	char const star = '*';
	parent(1,1) = star;
	parent(3,2) = star;
	expected =
		"...\n"
		"..*\n"
		"*..\n"
	;
	out << sub;
	EXPECT_EQ(expected, out.str());
}

TEST(read) {
	dynamic_grid parent{5, 5};
	sub_grid sub{3, 3, 1, 1, &parent};
	char const dot = '.';
	parent.fill_with(dot);
	std::string const data =
		"123\n"
		"456\n"
		"789\n"
	;
	std::istringstream in(data);
	in >> sub;

	std::ostringstream out;
	out << parent;
	std::string const expected =
		".....\n"
		".123.\n"
		".456.\n"
		".789.\n"
		".....\n"
	;
	EXPECT_EQ(expected, out.str());
}

END_TEST_SET(sub_grid)

} // namespace luanics::grid

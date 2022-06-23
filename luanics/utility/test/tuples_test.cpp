#include "luanics/utility/tuples.hpp"
#include "luanics/testing/unit.hpp"

namespace luanics::utility {

BEGIN_TEST_SET(tuples)

TEST(writer) {
	std::tuple<char, int> values('A', 1);
	std::ostringstream out;
	write_tuple(values, out);
	EXPECT_EQ("A 1 ", out.str());
}

END_TEST_SET(tuples)

}

#include "luanics/testing/unit.hpp"
#include "luanics/utility/paths.hpp"

#include <cstring>

namespace luanics::utility {

BEGIN_TEST_SET(paths)

TEST(file_name_from) {
	auto const * path = "/this/is/a/path/to/a/file.ext";
	auto const * file = file_name_from(path);
	EXPECT_EQ(std::strcmp(file, "file.ext"), 0);
}

END_TEST_SET(paths)

}

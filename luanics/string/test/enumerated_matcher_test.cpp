#include "luanics/string/enumerated_matcher.hpp"
#include "luanics/testing/unit.hpp"

namespace luanics::string {
namespace {

BEGIN_TEST_SET(enumerated_matcher)

TEST(empty) {
	enumerated_matcher matcher{{}};
	EXPECT_FALSE(matcher(""));
	EXPECT_FALSE(matcher("something"));
}

TEST(not_empty) {
	enumerated_matcher matcher{{"", "cat","dog"}};
	EXPECT_TRUE(matcher(""));
	EXPECT_FALSE(matcher("bird"));
	EXPECT_TRUE(matcher("cat"));
	EXPECT_TRUE(matcher("dog"));
	EXPECT_FALSE(matcher("doggy"));
}

END_TEST_SET(enumerated_matcher)

}
}

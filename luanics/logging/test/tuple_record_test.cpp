#include "luanics/logging/tuple_record.hpp"
#include "luanics/testing/unit.hpp"

#include <cstring>
#include <sstream>

namespace luanics::logging {

BEGIN_TEST_SET(tuple_record)

TEST(construct) {
	auto record = make_tuple_record(level::WARNING, "Source.cpp", 10, "data:", 42);
	EXPECT_EQ(level::WARNING, record->level());
	EXPECT_EQ(0, std::strcmp("source.cpp", record->file()));
	EXPECT_EQ(10, record->line());
}

TEST(write_message) {
	auto record = make_tuple_record(level::WARNING, "source.cpp", 10, "data:", 42);
	std::ostringstream out;
	record->write_message_to(out);
	EXPECT_EQ("data: 42 ", out.str());
}

END_TEST_SET(tuple_record)

}

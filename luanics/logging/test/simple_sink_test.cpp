#include "luanics/logging/tuple_record.hpp"
#include "luanics/logging/simple_sink.hpp"
#include "luanics/testing/unit.hpp"

#include <cstring>
#include <sstream>

namespace luanics::logging {

BEGIN_TEST_SET(simple_sink)

TEST(all) {
	std::ostringstream out;
	simple_sink sink{&out};
	auto record1 = make_tuple_record(level::WARNING, "Source.cpp", 10, "data:", 42);
	auto record2 = make_tuple_record(level::INFO, "File.cpp", 200, "stuff:", 101);
	sink.consume(std::move(record1));
	sink.consume(std::move(record2));
	std::string expected{
		"[WARNING] Source.cpp:10 - data: 42 \n"
		"[INFO   ] File.cpp:200 - stuff: 101 \n"
	};
	EXPECT_EQ(expected, out.str());
}

END_TEST_SET(simple_sink)

}

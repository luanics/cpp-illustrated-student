#include "luanics/logging/level_filter.hpp"
#include "luanics/logging/simple_sink.hpp"
#include "luanics/logging/simple_source.hpp"
#include "luanics/logging/tuple_record.hpp"
#include "luanics/testing/unit.hpp"

#include <cstring>
#include <sstream>

namespace luanics::logging {

BEGIN_TEST_SET(simple_source)

TEST(all) {
	std::ostringstream out;
	simple_source source;
	source.set_filter(std::make_unique<level_filter>(level::INFO));
	source.set_sink(std::make_unique<simple_sink>(&out));
	auto record1 = make_tuple_record(level::WARNING, "Source.cpp", 10, "data:", 42);
	auto record2 = make_tuple_record(level::INFO, "File.cpp", 200, "stuff:", 101);
	auto record3 = make_tuple_record(level::DEBUG, "File.cpp", 300, "stuff:", 201);
	source.submit(std::move(record1));
	source.submit(std::move(record2));
	source.submit(std::move(record3));
	std::string expected{
		"[WARNING] Source.cpp:10 - data: 42 \n"
		"[INFO   ] File.cpp:200 - stuff: 101 \n"
	};
	EXPECT_EQ(expected, out.str());
}

END_TEST_SET(simple_source)

}

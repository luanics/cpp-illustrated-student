#pragma once

#include <cstddef>

namespace luanics::testing::unit {

enum class level : std::size_t {
	SUITE = 0,
	SET = 1,
	TEST = 2
};

}

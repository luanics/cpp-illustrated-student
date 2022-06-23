#include "instance.hpp"

namespace luanics::testing::unit {

core::composite & suite_instance() {
	static core::composite instance{"suite"};
	return instance;
}

}

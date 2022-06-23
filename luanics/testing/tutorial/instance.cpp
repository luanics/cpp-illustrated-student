#include "luanics/testing/core/composite.hpp"
#include "luanics/testing/tutorial/instance.hpp"

namespace luanics::testing::tutorial {

core::composite & tutorial_instance() {
	static core::composite result{"tutorial"};
	return result;
}

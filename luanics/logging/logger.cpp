#include "luanics/logging/logger.hpp"
#include "luanics/logging/simple_source.hpp"

namespace luanics::logging {

source & logger() {
	static simple_source instance;
	return instance;
}

}

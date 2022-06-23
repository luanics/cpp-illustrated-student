#include "luanics/utility/paths.hpp"

#include <cstring>

namespace luanics::utility {

char const * file_name_from(char const * const path_name, char const delimiter) {
	auto found = std::strrchr(path_name, delimiter);
	return found == nullptr ? path_name : found + 1;
}

}

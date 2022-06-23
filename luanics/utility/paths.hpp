#pragma once

namespace luanics::utility {

/// @returns the last element of the path_name, e.g., "File.ext" in /path/File.ext"
char const * file_name_from(char const * const path_name, char delimiter = '/');

}

cmake_minimum_required(VERSION 2.8)

project(cpp-illustrated)

# Put our targets in top-level directories
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# Add C++20 support and warnings
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)
set(CMAKE_CXX_FLAGS "-Wall -pedantic-errors -fsignaling-nans")

# Display compiler information
message(STATUS "CMAKE_CXX_COMPILER      : " ${CMAKE_CXX_COMPILER} )
message(STATUS "CMAKE_CXX_FLAGS         : " ${CMAKE_CXX_FLAGS} )
message(STATUS "CMAKE_BUILD_TYPE        : " ${CMAKE_BUILD_TYPE})

# Set build-type-specific configuration
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0 -fno-elide-constructors")
set(CMAKE_CXX_FLAGS_RELEASE "-g -O3 -DNDEBUG")
include(cmake/profile_build_type.cmake)

add_compile_definitions(
	$<$<CONFIG:Debug>:LUANICS_LEAK_CHECKING>
	$<$<OR:$<CONFIG:Debug>,$<CONFIG:Profile>>:LUANICS_PROFILING>
	$<$<CONFIG:Debug>:LUANICS_LOGGING>
)
set(BUILD_POSTFIX 
	$<$<CONFIG:Debug>:_d>
	$<$<CONFIG:Release>:_r>
	$<$<CONFIG:Profile>:_s>
)

message(STATUS "CMAKE_CXX_FLAGS_DEBUG   : " ${CMAKE_CXX_FLAGS_DEBUG} )
message(STATUS "CMAKE_CXX_FLAGS_RELEASE : " ${CMAKE_CXX_FLAGS_RELEASE} )
message(STATUS "CMAKE_CXX_FLAGS_PROFILE : " ${CMAKE_CXX_FLAGS_PROFILE} )
get_directory_property(DirectoryDefinitions COMPILE_DEFINITIONS)
message(STATUS "DEFINITIONS             : " ${DirectoryDefinitions})

include_directories(.)

#add_subdirectory(book)
add_subdirectory(luanics)
add_subdirectory(tutorial)

#include "luanics/testing/tutorial.hpp"

#include <cassert>

BEGIN_CHAPTER(Building)

//* The build process creates an executable file or library from source code.
//* A build refers to one complete iteration of the build process.
//* The execution process creates a running program from an executable file.
//* The main stages of the build process are preprocessor, compiler, assembler and linker.
//* The preprocessor produces a translation unit from a source file by inserting all "included" headers into the source file. \Term{Include guards} are used to prevent multiple insertion of the same file.
//* Pitfall - people often use "compiling" to mean "building", and "compiler" to mean "build toolchain".
//* Source code is typically divided up into header files (.hpp) for the interface, and source files (.cpp) for the implementation
//* Build management coordinates the builds, providing an easier build experience for the user. We use CMake for build managent.

#include "data/comment_me_out_to_play.hpp"
//#include "data/door_a.hpp"
//#include "data/door_b.hpp"
//#include "data/door_c.hpp"

SECTION(IncludeFiles) {
	// * The preprocessor produces a translation unit from a source file by inserting all "included" headers into the source file.
	// Uncomment the correct line above to win the grand prize...
	EXPECT_EQ("new car", prize());
}

END_CHAPTER(Building)

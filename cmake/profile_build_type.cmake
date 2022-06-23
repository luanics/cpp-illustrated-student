set(CMAKE_C_FLAGS_PROFILE	
	"${CMAKE_C_FLAGS_RELEASE}" CACHE STRING
	"Flags used by the C compiler for Profile build type or configuration." FORCE
)
set(CMAKE_CXX_FLAGS_PROFILE
	"${CMAKE_CXX_FLAGS_RELEASE}" CACHE STRING
	"Flags used by the C++ compiler for Profile build type or configuration." FORCE
)
set(CMAKE_EXE_LINKER_FLAGS_PROFILE
	"${CMAKE_SHARED_LINKER_FLAGS_RELEASE}" CACHE STRING
	"Linker flags to be used to create executables for Profile build type." FORCE
)
set(CMAKE_SHARED_LINKER_FLAGS_PROFILE
	"${CMAKE_SHARED_LINKER_FLAGS_RELEASE}" CACHE STRING
	"Linker lags to be used to create shared libraries for Profile build type." FORCE
)
set(CMAKE_MODULE_LINKER_FLAGS_PROFILE
	"${CMAKE_MODULE_LINKER_FLAGS_RELEASE}" CACHE STRING
	"Linker lags to be used to create module libraries for Profile build type." FORCE
)

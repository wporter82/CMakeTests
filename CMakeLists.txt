cmake_minimum_required (VERSION 2.6)
project (HelloWorld)

# Set a version number
set (HelloWorld_VERSION_MAJOR 1)
set (HelloWorld_VERSION_MINOR 1)

# config a header to pass some of the CMake settings
# to the source code
configure_file (
	"${PROJECT_SOURCE_DIR}/HelloWorldConfig.h.in"
	"${PROJECT_SOURCE_DIR}/HelloWorldConfig.h"
)

# add the binary tree to the search path for include
# files so that we will find HelloWorldConfig.h
include_directories("${PROJECT_BINARY_DIR}")

# add the executable
add_executable (HelloWorld hello.c)

# add the install target
install (TARGETS HelloWorld DESTINATION bin)
install (FILES "${PROJECT_BINARY_DIR}/HelloWorldConfig.h" DESTINATION include)

# Tests that can be run with ctest
############################################################
include(CTest)

# does it run
add_test (HelloWorldRuns HelloWorld bob)

# macro to make running tests easier
macro (do_test arg result)
	add_test (HelloWorld${arg} HelloWorld ${arg})
	set_tests_properties (HelloWorld${arg} PROPERTIES PASS_REGULAR_EXPRESSION ${result})
endmacro (do_test)

# does it print the name passed in
do_test(bob "Hello bob")

# does the usage message work
do_test ("" "Usage: .*name")
############################################################



# build a cpack driven installer package
#############################################################
include (InstallRequiredSystemLibraries)
set (CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
set (CPACK_PACKAGE_VERSION_MAJOR "${HelloWorld_VERSION_MAJOR}")
set (CPACK_PACKAGE_VERSION_MINOR "${HelloWorld_VERSION_MINOR}")
include (CPack)
#############################################################

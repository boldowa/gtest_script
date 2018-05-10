#-------------------------------------------------
# ProjectName CMake
#-------------------------------------------------
cmake_minimum_required(VERSION 3.10)

if(NOT CMAKE_BUILD_TYPE)
	message(STATUS "No build type selected, default to Debug")
	set(CMAKE_BUILD_TYPE "Debug" CACHE STRING 
                "Choose the type of build, options are: Debug Release RelWithDebInfo MinSizeRel." FORCE)
endif()
option(PROJECTNAME_EXECUTE_TEST "Execute test suite" ON)
option(PROJECTNAME_COVERAGE "Check code coverage" ON)
set(PROJECTNAME_COVERAGE_EXECUTE FALSE)

project(ProjectName)
include(cmake/macs.cmake)

add_subdirectory(ext)
add_subdirectory(src)

if(PROJECTNAME_EXECUTE_TEST)
	find_program(GCOV gcov)
	if(NOT GCOV)
		message(FATAL_ERROR "-- gcov not found...")
	endif()
	message("-- gcov found: ${GCOV}")

	enable_testing()
	add_subdirectory(test)
	add_test(NAME ProjectName COMMAND ProjectName_test)
	add_custom_target(check ALL
		COMMAND ctest -VV
		)
	add_dependencies(check ProjectName_test)
	add_dependencies(ProjectName_exe check)
	if(PROJECTNAME_COVERAGE_EXECUTE)
		add_custom_target(coverage ALL
			COMMAND rm -rf gcov
			COMMAND mkdir gcov
			COMMAND find src/CMakeFiles/ProjectName.dir/ -type f -name "*.gcno" -print0 | xargs -0 gcov
			COMMAND mv *.gcov gcov
			)
		add_dependencies(coverage check)
		add_dependencies(ProjectName_exe coverage)
	endif(PROJECTNAME_COVERAGE_EXECUTE)
endif(PROJECTNAME_EXECUTE_TEST)




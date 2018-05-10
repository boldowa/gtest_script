#-------------------------------------------------
# ProjectName main source
#-------------------------------------------------

# Compile All sources
file(GLOB_RECURSE PRJCSOURCES
	"."  "*.c"
)
file(GLOB_RECURSE PRJCPPSOURCES
	"."  "*.cpp"
)
# exclude main.c
list(FILTER PRJCSOURCES EXCLUDE REGEX ".*main.c$")
list(FILTER PRJCPPSOURCES EXCLUDE REGEX ".*main.cpp$")

add_library(ProjectName ${PRJCSOURCES} ${PRJCPPSOURCES})
target_include_directories(ProjectName PRIVATE
	"../include"
	"../ext/googletest/googletest/include"
)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
	if(UNIX AND PROJECTNAME_COVERAGE)
		set_target_properties(ProjectName PROPERTIES COMPILE_FLAGS
			"${CMAKE_C_FLAGS} ${CMAKE_C_FLAGS_DEBUG} --coverage")
		target_link_libraries(ProjectName gcov)
		set(PROJECTNAME_COVERAGE_EXECUTE TRUE PARENT_SCOPE)
	endif()
endif()

add_executable(ProjectName_exe main.c)
target_link_libraries(ProjectName_exe ProjectName)
set_target_properties(ProjectName_exe PROPERTIES OUTPUT_NAME ProjectName)



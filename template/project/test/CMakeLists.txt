#-------------------------------------------------
# PROJECTNAME test
#-------------------------------------------------

# TODO
file(GLOB_RECURSE TESTSOURCES
	"."  "*.cpp"
)
add_executable(ProjectName_test ${TESTSOURCES})
target_link_libraries(ProjectName_test ProjectName gtest gtest_main pthread)
target_include_directories(ProjectName_test PRIVATE
	"../include"
	"../ext/googletest/googletest/include"
)



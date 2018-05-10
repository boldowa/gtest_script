#--- Builds Google Test
option(BUILD_GTEST "Builds the googletest subproject" ON)
option(BUILD_GMOCK "Builds the googlemock subproject" OFF)
option(INSTALL_GTEST "Installs the google test" OFF)

if(PROJECTNAME_EXECUTE_TEST)
	add_subdirectory(googletest)
endif(PROJECTNAME_EXECUTE_TEST)


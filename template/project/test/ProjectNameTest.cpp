/**
 * @file ProjectNameTest.cpp
 *   This is a test for ProjectName main function.
 */
extern "C"
{
	extern int ProjectName(int argc, char** argv);
}

#include <gtest/gtest.h>

TEST(ProjectNameTest, case1)
{
	/* TODO: Write main test. */
	char* dummy[] = {(char*)"dummy"};
	EXPECT_EQ(0, ProjectName(1, (char**)dummy));
}


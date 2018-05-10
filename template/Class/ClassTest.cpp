/**
 * @file ClassTest.cpp
 */

#include "PackageName/Class.h"
#include <gtest/gtest.h>

class ClassTest : public :: testing::Test {
	protected:
		ClassName* target;

		virtual void SetUp()
		{
			target = new ClassName();
		}

		virtual void TearDown()
		{
			delete target;
		}
};

/**
 * Check object create
 */
TEST_F(ClassTest, new)
{
	ASSERT_TRUE(NULL != target);
}

/**
 * Check object delete
 */
TEST_F(ClassTest, delete)
{
	/* check delete */
}


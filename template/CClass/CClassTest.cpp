/**
 * ClassNameTest.cpp
 */
extern "C"
{
/*#include "common/types.h"*/
#include "PackageName/CClass.h"
}

#include <gtest/gtest.h>

class ClassNameTest : public :: testing::Test {
	protected:
		ClassName* target;

		virtual void SetUp()
		{
			target = new_ClassName();
		}

		virtual void TearDown()
		{
			delete_ClassName(&target);
		}
};

/**
 * Check object create
 */
TEST_F(ClassNameTest, new)
{
	ASSERT_TRUE(NULL != target);
}

/**
 * Check object delete
 */
TEST_F(ClassNameTest, delete)
{
	delete_ClassName(&target);

	/* check delete */
	ASSERT_EQ(NULL, target);
}


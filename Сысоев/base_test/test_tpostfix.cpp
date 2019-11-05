#include <gtest.h>
#include "postfix.h"
#include "postfix.cpp"


TEST(TPostfix, can_create_postfix)
{
  ASSERT_NO_THROW(TPostfix p);
}

TEST(TPostfix, can_create_postfix_with_inicialization_of_string)
{
	ASSERT_NO_THROW(TPostfix p("a+b"));
}

TEST(TPostfix, can_get_infix)
{
	TPostfix p("a+b");
	EXPECT_EQ("a+b", p.GetInfix());
}

TEST(TPostfix, can_create_right_postfix_test1)
{
	TPostfix p("(a+b)*c");
	p.ToPostfix();
	EXPECT_EQ("ab+c*", p.GetPostfix());
}


TEST(TPostfix, can_create_right_postfix_test2)
{
	TPostfix p("a+b*c/d-e");
	p.ToPostfix();
	EXPECT_EQ("abc*d/+e-", p.GetPostfix());
}

TEST(TPostfix, can_calculate_postfix_test1)
{
	TPostfix p("a+b*c");
	p.ToPostfix();
	double a = 1, b = 2, c = 3;
	EXPECT_EQ(7, p.Calculate());
}

TEST(TPostfix, can_calculate_postfix_test2)
{
	TPostfix p("(a+b)*c");
	p.ToPostfix();
	double a = 1, b = 2, c = 3;
	EXPECT_EQ(9, p.Calculate());
}


TEST(TPostfix, can_get_right_priority_of_the_operations)
{
	TPostfix p("a+b");
	EXPECT_TRUE(p.Priority('*') > p.Priority('+'));
}


TEST(TPostfix, can_check_operations)
{
	TPostfix p("a*b");
	string res;
	res = p.GetInfix();
	EXPECT_EQ(true, p.Check_op(res[1]));
}


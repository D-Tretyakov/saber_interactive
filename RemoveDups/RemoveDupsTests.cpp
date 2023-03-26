#include "RemoveDups.hpp"
#include <gtest/gtest.h>

TEST(RemoveDupsTests, ExampleFromTask)
{
    char data[] = "AAA BBB AAA";
    RemoveDups(data);
    const char expected[] = "A B A";
    ASSERT_STREQ(data, expected);
}

TEST(RemoveDupsTests, EmptyString)
{
    char data[] = "";
    RemoveDups(data);
    const char expected[] = "";
    ASSERT_STREQ(data, expected);
}

TEST(RemoveDupsTests, OnlyOneSpace)
{
    char data[] = " ";
    RemoveDups(data);
    const char expected[] = " ";
    ASSERT_STREQ(data, expected);
}

TEST(RemoveDupsTests, ManySpaces)
{
    char data[] = "        ";
    RemoveDups(data);
    const char expected[] = " ";
    ASSERT_STREQ(data, expected);
}
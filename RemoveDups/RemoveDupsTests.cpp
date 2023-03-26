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

TEST(RemoveDupsTests, VariousConsecutiveLen)
{
    char data[] = " a aa  aaa    aaaa      aaaaa     ";
    RemoveDups(data);
    const char expected[] = " a a a a a ";
    ASSERT_STREQ(data, expected);
}
TEST(RemoveDupsTests, OneRepeatedLetter)
{
    char data[] = "aaaaaaaaaaaaaaaaaaaa";
    RemoveDups(data);
    const char expected[] = "a";
    ASSERT_STREQ(data, expected);
}

TEST(RemoveDupsTests, HelloWorld)
{
    char data[] = "Hello World!!!!!111!";
    RemoveDups(data);
    const char expected[] = "Helo World!1!";
    ASSERT_STREQ(data, expected);
}

TEST(RemoveDupsTests, NoDups)
{
    char data[] = "I like cats";
    RemoveDups(data);
    const char expected[] = "I like cats";
    ASSERT_STREQ(data, expected);
}
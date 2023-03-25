#include "PrintBinary.hpp"
#include <gtest/gtest.h>

TEST(PrintBinaryTests, PositiveTen)
{
    testing::internal::CaptureStdout();
    PrintBinary(10);
    std::string actual = testing::internal::GetCapturedStdout();
    std::string expected("00000000000000000000000000001010\n");
    EXPECT_EQ(actual, expected);
}

TEST(PrintBinaryTests, NegativeTen)
{
    testing::internal::CaptureStdout();
    PrintBinary(-10);
    std::string actual = testing::internal::GetCapturedStdout();
    std::string expected("11111111111111111111111111110110\n");
    EXPECT_EQ(actual, expected);
}

TEST(PrintBinaryTests, PositiveOne)
{
    testing::internal::CaptureStdout();
    PrintBinary(1);
    std::string actual = testing::internal::GetCapturedStdout();
    std::string expected("00000000000000000000000000000001\n");
    EXPECT_EQ(actual, expected);
}

TEST(PrintBinaryTests, NegativeOne)
{
    testing::internal::CaptureStdout();
    PrintBinary(-1);
    std::string actual = testing::internal::GetCapturedStdout();
    std::string expected("11111111111111111111111111111111\n");
    EXPECT_EQ(actual, expected);
}

TEST(PrintBinaryTests, PositiveZero)
{
    testing::internal::CaptureStdout();
    PrintBinary(0);
    std::string actual = testing::internal::GetCapturedStdout();
    std::string expected("00000000000000000000000000000000\n");
    EXPECT_EQ(actual, expected);
}

TEST(PrintBinaryTests, NegativeZero)
{
    testing::internal::CaptureStdout();
    PrintBinary(0);
    std::string actual = testing::internal::GetCapturedStdout();
    std::string expected("00000000000000000000000000000000\n");
    EXPECT_EQ(actual, expected);
}

TEST(PrintBinaryTests, MaxIntValue)
{
    testing::internal::CaptureStdout();
    PrintBinary(std::numeric_limits<int>::max());
    std::string actual = testing::internal::GetCapturedStdout();
    std::string expected("01111111111111111111111111111111\n");
    EXPECT_EQ(actual, expected);
}

TEST(PrintBinaryTests, MinIntValue)
{
    testing::internal::CaptureStdout();
    PrintBinary(std::numeric_limits<int>::min());
    std::string actual = testing::internal::GetCapturedStdout();
    std::string expected("10000000000000000000000000000000\n");
    EXPECT_EQ(actual, expected);
}
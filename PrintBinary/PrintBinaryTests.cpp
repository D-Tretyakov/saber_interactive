#include "PrintBinary.hpp"
#include <gtest/gtest.h>

TEST(PrintBinaryTests, PositiveTwo)
{
    testing::internal::CaptureStdout();
    PrintBinary(2);
    std::string actual = testing::internal::GetCapturedStdout();
    std::string expected("00000000000000000000000000000010\n");
    EXPECT_EQ(actual, expected);
}

TEST(PrintBinaryTests, NegativeTwo)
{
    testing::internal::CaptureStdout();
    PrintBinary(-2);
    std::string actual = testing::internal::GetCapturedStdout();
    std::string expected("11111111111111111111111111111110\n");
    EXPECT_EQ(actual, expected);
}

TEST(PrintBinaryTests, PositiveFour)
{
    testing::internal::CaptureStdout();
    PrintBinary(4);
    std::string actual = testing::internal::GetCapturedStdout();
    std::string expected("00000000000000000000000000000100\n");
    EXPECT_EQ(actual, expected);
}

TEST(PrintBinaryTests, NegativeFour)
{
    testing::internal::CaptureStdout();
    PrintBinary(-4);
    std::string actual = testing::internal::GetCapturedStdout();
    std::string expected("11111111111111111111111111111100\n");
    EXPECT_EQ(actual, expected);
}

TEST(PrintBinaryTests, PositiveEight)
{
    testing::internal::CaptureStdout();
    PrintBinary(8);
    std::string actual = testing::internal::GetCapturedStdout();
    std::string expected("00000000000000000000000000001000\n");
    EXPECT_EQ(actual, expected);
}

TEST(PrintBinaryTests, NegativeEight)
{
    testing::internal::CaptureStdout();
    PrintBinary(-8);
    std::string actual = testing::internal::GetCapturedStdout();
    std::string expected("11111111111111111111111111111000\n");
    EXPECT_EQ(actual, expected);
}

TEST(PrintBinaryTests, PositiveSixteen)
{
    testing::internal::CaptureStdout();
    PrintBinary(16);
    std::string actual = testing::internal::GetCapturedStdout();
    std::string expected("00000000000000000000000000010000\n");
    EXPECT_EQ(actual, expected);
}

TEST(PrintBinaryTests, NegativeSixteen)
{
    testing::internal::CaptureStdout();
    PrintBinary(-16);
    std::string actual = testing::internal::GetCapturedStdout();
    std::string expected("11111111111111111111111111110000\n");
    EXPECT_EQ(actual, expected);
}

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
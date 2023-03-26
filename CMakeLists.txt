cmake_minimum_required(VERSION 3.14)
project(SaberInteractiveTest)

set(CMAKE_CXX_STANDARD 17)

if (CMAKE_VERSION VERSION_GREATER_EQUAL "3.24.0")
    cmake_policy(SET CMP0135 NEW)
endif()

# Качаем GTest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

set(PrintBinarySources 
  "PrintBinary/PrintBinary.cpp" 
  "PrintBinary/PrintBinaryTests.cpp"
)

set(RemoveDupsSources 
  "RemoveDups/RemoveDups.cpp" 
  "RemoveDups/RemoveDupsTests.cpp"
)

enable_testing()

add_executable(
  tests
  ${PrintBinarySources}
  ${RemoveDupsSources}
)
target_link_libraries(
  tests
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(tests)

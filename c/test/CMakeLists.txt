include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/34ad51b3dc4f922d8ab622491dd44fc2c39afee9.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()


link_libraries(
  GTest::gtest_main
  implementations
)

include(GoogleTest)

# Declare a single test executable at this top level instead of multiple at lower levels
add_executable(
  implementations_tests
  data_structures_tests/linked_list_tests.cpp
)

gtest_discover_tests(implementations_tests)

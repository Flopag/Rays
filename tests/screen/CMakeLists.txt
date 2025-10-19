enable_testing()

add_executable(screen_test)
target_sources(screen_test
    PRIVATE
        screen.cc
)
target_link_libraries(screen_test
  PRIVATE
    Screen
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(screen_test)
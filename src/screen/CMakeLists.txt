enable_testing()

add_executable(screen_test)
target_sources(screen_test
    PRIVATE
        tests/screen.cc
)
target_link_libraries(screen_test
  PRIVATE
    Screen
    GTest::gtest_main
)

add_library(Screen)

target_sources(Screen
    PRIVATE
        screen.cpp
    
    PUBLIC
        FILE_SET HEADERS
        FILES
            screen.hpp
)

include(GoogleTest)
gtest_discover_tests(screen_test)
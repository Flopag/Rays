add_library(Screen)

target_sources(Screen
    PRIVATE
        screen.cpp
    
    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS ${CMAKE_SOURCE_DIR}/include
        FILES
            ${CMAKE_SOURCE_DIR}/include/screen/screen.hpp
)
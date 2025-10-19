add_library(Screen)

target_sources(Screen
    PRIVATE
        screen.cpp
    
    PUBLIC
        FILE_SET HEADERS
        FILES
            screen.hpp
)
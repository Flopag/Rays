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

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.2
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

target_link_libraries(Screen 
    PUBLIC 
        SFML::Graphics
)
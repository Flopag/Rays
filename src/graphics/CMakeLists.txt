add_library(Graphics)

target_sources(Graphics
    PRIVATE
        face.cpp
        point.cpp
    
    PUBLIC
        FILE_SET HEADERS
        FILES
            face.hpp
            point.hpp
)

target_link_libraries(Graphics
  PRIVATE
    Screen
)
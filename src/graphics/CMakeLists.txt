add_library(Graphics)

target_sources(Graphics
    PRIVATE
        face.cpp
        point.cpp
        camera.cpp
    
    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS ${CMAKE_SOURCE_DIR}/include
        FILES
            ${CMAKE_SOURCE_DIR}/include/graphics/face.hpp
            ${CMAKE_SOURCE_DIR}/include/graphics/point.hpp
            ${CMAKE_SOURCE_DIR}/include/graphics/camera.hpp
            ${CMAKE_SOURCE_DIR}/include/graphics/color.hpp
)

target_link_libraries(Graphics
  PRIVATE
    os_api
)
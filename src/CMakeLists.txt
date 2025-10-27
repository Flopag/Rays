add_executable(rays)

target_sources(rays
    PRIVATE
        main.cpp
)

target_link_libraries(rays
  PRIVATE
    os_api
    Graphics
)

add_subdirectory(graphics)
add_subdirectory(os_api)
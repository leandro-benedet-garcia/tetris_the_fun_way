ADD_EXECUTABLE(FUNTetris tetris_the_fun_way.cpp)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

find_package(Vulkan REQUIRED)
find_package(glfw3 3.3 REQUIRED)

target_link_libraries(FUNTetris PRIVATE Vulkan::Vulkan glfw)

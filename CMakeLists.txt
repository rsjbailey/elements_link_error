cmake_minimum_required(VERSION 3.28)
project(linkerror)

set(CMAKE_CXX_STANDARD 17)
add_subdirectory(elements)

# When building with MSVC toolchain (VS 2022):
# Without the following line, you get a MT_StaticRelease/MDd_DynamicDebug mismatch error.
# With it you can build a release configuration but debug mode gives an _ITERATOR_DEBUG_LEVEL mismatch error.
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

# The following line would work but isn't always what you want for debug builds as you lose all the STL sanity checks
# set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded")
add_library(linkerror MODULE library.cpp)

target_link_libraries(linkerror PRIVATE elements)



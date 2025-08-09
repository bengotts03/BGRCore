cmake_minimum_required(VERSION 3.31)
project(BGRCore)

set(CMAKE_CXX_STANDARD 20)

if(NOT DEFINED CMAKE_TOOLCHAIN_FILE AND DEFINED ENV{VCPKG_ROOT})
    set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")
endif()

file(GLOB_RECURSE HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.h" "${CMAKE_CURRENT_SOURCE_DIR}/src/*.hpp")
file(GLOB_RECURSE SOURCE "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

add_library(BGRCore STATIC ${HEADERS} ${SOURCE})

target_include_directories(BGRCore PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/dependencies/BGApp/include"
)

find_package(glfw3 CONFIG REQUIRED)
find_package(OpenGL REQUIRED)
target_link_libraries(BGRCore PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/third-party/BGApp/lib/libBGApp.a"
        OpenGL::GL
        glfw
)

target_include_directories(BGRCore PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
        $<INSTALL_INTERFACE:include/src>
)

install(TARGETS BGRCore
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
)

install(DIRECTORY src/
        DESTINATION include
        FILES_MATCHING PATTERN "*.h" PATTERN "*.hpp"
)
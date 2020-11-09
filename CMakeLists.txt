cmake_minimum_required(VERSION 3.0)

# set the project name
project(LinkedList VERSION 1.0.0)

# Set Language
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# set Header and Source paths
set(INCLUDE_PATH ./include)
set(SOURCE_FILES ./source)

# Set specific header and source variables
set(HEADER_FILES ${INCLUDE_PATH}/lib.hpp)
set(SOURCES ${SOURCE_FILES}/main.cpp ${HEADER_FILES})

# Download automatically, you can also just copy the conan.cmake file
if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
    message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
    file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/v0.9/conan.cmake"
            "${CMAKE_BINARY_DIR}/conan.cmake")
endif()

include(${CMAKE_BINARY_DIR}/conan.cmake)
conan_cmake_run(CONANFILE conanfile.txt BASIC_SETUP BUILD missing)

add_library(LinkedListLib ${HEADER_FILES} ${SOURCE_FILES}/LinkedList.cpp)
target_include_directories(LinkedListLib PUBLIC ${INCLUDE_PATH}/linked_list)

add_executable(LinkedList ${SOURCES})
target_link_libraries(LinkedList PRIVATE LinkedListLib PUBLIC ${CONAN_LIBS})

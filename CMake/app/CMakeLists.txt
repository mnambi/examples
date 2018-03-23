cmake_minimum_required(VERSION 2.8.8)
project(app)

set(${PROJECT_NAME}_VERSION_MAJOR 0)
set(${PROJECT_NAME}_VERSION_MINOR 1)
set(${PROJECT_NAME}_VERSION_PATCH 0)
set(${PROJECT_NAME}_VERSION ${${PROJECT_NAME}_VERSION_MAJOR}.${${PROJECT_NAME}_VERSION_MINOR}.${${PROJECT_NAME}_VERSION_PATCH})


message (${PROJECT_NAME} " version is ${${PROJECT_NAME}_VERSION}")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_BUILD_TYPE Release)

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../wee/ ${CMAKE_MODULE_PATH})
message(${CMAKE_MODULE_PATH})
find_package(WEE REQUIRED)
# add_library cannot have only header files. It needs source files also. Otherwise CMake throws an
# error saying that it cannot determine linker language.
set(SOURCES
    app.cpp
    )

set(HEADERS
    )   

add_executable(app ${SOURCES} ${HEADERS})



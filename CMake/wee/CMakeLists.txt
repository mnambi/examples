cmake_minimum_required(VERSION 2.8.8)
project(wee)

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

# add_library cannot have only header files. It needs source files also. Otherwise CMake throws an
# error saying that it cannot determine linker language.
set(SOURCES
    wee.cpp
    )

set(HEADERS
    )   


add_library(wee_static STATIC ${SOURCES} ${HEADERS})
add_library(wee_shared SHARED ${SOURCES} ${HEADERS})

# By default this command will install the libraries to /usr/local/lib/ and /usr/local/bin.
# To specify a custom path use -DCMAKE_INSTALL_PREFIX:PATH=<new path> with your cmake command.
install(TARGETS wee_static wee_shared
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib/wee/
        ARCHIVE DESTINATION lib/wee/static
        )
#install (TARGETS some_library.cpp DES)



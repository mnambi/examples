cmake_minimum_required(VERSION 2.8.6)
project(uscxml-sample)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "/usr/local/share/uscxml/cmake/")
set (CMAKE_CXX_STANDARD 11)
find_package(USCXML REQUIRED)


include_directories(${USCXML_INCLUDE_DIR})
add_executable(uscxml-sample
               src/main.cpp)
target_link_libraries(uscxml-sample ${USCXML_LIBRARIES})

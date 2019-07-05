cmake_minimum_required(VERSION 3.5)
project(info_projekt)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

list(APPEND CMAKE_PREFIX_PATH "/home/m1824717/root/")
find_package(ROOT REQUIRED COMPONENTS MathCore Hist Tree)
include(${ROOT_USE_FILE})

add_executable(a.out
        bahnkurve.cpp
        bahnkurve.hpp
        mainWurf.cpp
        statischeDaten.cpp
        statischeDaten.hpp)


target_link_libraries(a.out ${ROOT_LIBRARIES})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

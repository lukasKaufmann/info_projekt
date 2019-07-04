cmake_minimum_required(VERSION 3.14)
project(info_projekt)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

list(APPEND CMAKE_PREFIX_PATH "/Applications/root_v6.16.00/")
find_package(ROOT REQUIRED COMPONENTS MathCore Hist Tree)
include(${ROOT_USE_FILE})

add_executable(info projekt
        bahnkurve.cpp
        bahnkurve.hpp
        mainWurf.cpp
        statischeDaten.cpp
        statischeDaten.hpp)


target_link_libraries(info_projekt-version_1${ROOT_LIBRARIES})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

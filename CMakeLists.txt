cmake_minimum_required(VERSION 2.8)

project(kuros)

add_subdirectory(kuros)
add_subdirectory(demos)

install(FILES resources/ServerConfig.xml resources/trajectory.txt DESTINATION ${CMAKE_SOURCE_DIR}/bin)
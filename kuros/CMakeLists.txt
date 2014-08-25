cmake_minimum_required(VERSION 2.8)

#project(kuros)

#set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/lib)
#set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

find_package(Boost REQUIRED COMPONENTS system thread)

include_directories(
	include
	${Boost_INCLUDE_DIRS}
)

# static library
add_library(
	kuros
	src/BlockingServer.cpp
	src/KukaCommand.cpp
	src/KukaResponse.cpp
	src/ServerConfig.cpp
	src/Server.cpp
	src/XMLParser.cpp
)

#install_files(${kuros_SOURCE_DIR}/lib kuros)

#add_subdirectory(demos)

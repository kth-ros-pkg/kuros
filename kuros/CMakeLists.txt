cmake_minimum_required(VERSION 2.8)

#project(kuros)

#set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/lib)
#set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

find_package(Boost REQUIRED COMPONENTS system thread)
#set(TinyXML_LIBRARIES "/usr/lib/x86_64-linux-gnu/libtinyxml2.so")
set(TinyXML_LIBRARIES "tinyxml2")

include_directories(
	include
	${Boost_INCLUDE_DIRS}
)

# static library
add_library(
	kuros_static
	src/BlockingServer.cpp
	src/KukaCommand.cpp
	src/KukaResponse.cpp
	src/ServerConfig.cpp
	src/Server.cpp
	src/XMLParser.cpp
)

# shared library
add_library(
	kuros
	SHARED
	src/BlockingServer.cpp
	src/KukaCommand.cpp
	src/KukaResponse.cpp
	src/ServerConfig.cpp
	src/Server.cpp
	src/XMLParser.cpp
)

TARGET_LINK_LIBRARIES(kuros_static ${Boost_LIBRARIES} ${TinyXML_LIBRARIES})
TARGET_LINK_LIBRARIES(kuros ${Boost_LIBRARIES} ${TinyXML_LIBRARIES})

#install_files(${kuros_SOURCE_DIR}/lib kuros)

#add_subdirectory(demos)

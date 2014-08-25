#project(kuros_demo_simple)

#set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

find_package(Boost REQUIRED COMPONENTS system thread)

include_directories(
	include
	${kuros_SOURCE_DIR}/kuros/include
	${Boost_INCLUDE_DIRS}
)

link_directories(
	${kuros_BINARY_DIR}/kuros
)

add_executable(
	kuros_demo_simple
	src/DataFile.cpp
	src/HandlingServer.cpp
	src/simple_main.cpp
)

target_link_libraries(kuros_demo_simple libkuros.a tinyxml2 boost_system boost_thread)

install(TARGETS kuros_demo_simple DESTINATION ${CMAKE_SOURCE_DIR}/bin)
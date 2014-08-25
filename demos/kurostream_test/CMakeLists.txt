#project(kuros_demo_simple)

#set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

set(CMAKE_CXX_FLAGS "-std=c++11")

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
	kurostream_test
	src/HandlingServer.cpp
	src/streamtest_main.cpp
)

target_link_libraries(kurostream_test libkuros.a tinyxml2 boost_system boost_thread)

install(TARGETS kurostream_test DESTINATION ${CMAKE_SOURCE_DIR}/bin)
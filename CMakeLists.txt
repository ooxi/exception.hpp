# ooxi / exception
cmake_minimum_required(VERSION 3.5)


enable_testing()


project("ooxi-exception" CXX)
add_library("${PROJECT_NAME}-c++20" INTERFACE)
add_library("ooxi::exception::c++20" ALIAS "${PROJECT_NAME}-c++20")


target_compile_options(
	"${PROJECT_NAME}-c++20"
	INTERFACE
		-std=c++20
		-Wall
		-Wextra
		-Werror
		-Wpedantic

		-Wnon-virtual-dtor
		-Wcast-align
		-Wunused
		-Woverloaded-virtual
		-Wdouble-promotion
		-Wformat=2
)


add_library("${PROJECT_NAME}" STATIC "")
add_library("ooxi::exception" ALIAS "${PROJECT_NAME}")


target_sources(
	"${PROJECT_NAME}"
	PRIVATE
		"${CMAKE_CURRENT_LIST_DIR}/src/Exception.c++"
		"${CMAKE_CURRENT_LIST_DIR}/src/ExtendedException.c++"
)


target_include_directories(
	"${PROJECT_NAME}"
	PUBLIC
		"${CMAKE_CURRENT_LIST_DIR}/include"
)


target_link_libraries(
	"${PROJECT_NAME}"
	PRIVATE
		ooxi::exception::c++20
)


add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/test/ExceptionTest")
add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/test/GlobalVsLocalExceptionTest")

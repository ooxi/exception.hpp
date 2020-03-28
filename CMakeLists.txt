# ooxi / exception
cmake_minimum_required(VERSION 3.5)


enable_testing()


project("ooxi-exception" CXX)
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


target_compile_options(
	"${PROJECT_NAME}"
	PRIVATE
		-std=c++17
		-Wall
		-Wextra
		-Werror
		-pedantic

		-Wnon-virtual-dtor
		-Wcast-align
		-Wunused
		-Woverloaded-virtual
		-Wpedantic
		-Wdouble-promotion
		-Wformat=2

)


add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/test/ExceptionTest")
add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/test/GlobalVsLocalExceptionTest")

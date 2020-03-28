# ooxi / exception / test / ExceptionTest
cmake_minimum_required(VERSION 3.5)


project("${PROJECT_NAME}-ExceptionTest" CXX)
add_executable("${PROJECT_NAME}")


target_sources(
	"${PROJECT_NAME}"
	PRIVATE
		"${CMAKE_CURRENT_LIST_DIR}/ExceptionTest.c++"
)


target_link_libraries(
	"${PROJECT_NAME}"
	PUBLIC
		ooxi::exception
		stdc++fs
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


add_test(
	NAME	"${PROJECT_NAME}"
	COMMAND	"${PROJECT_NAME}"
)

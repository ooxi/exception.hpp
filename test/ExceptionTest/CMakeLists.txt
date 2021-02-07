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
	PRIVATE
		ooxi::exception::c++20
)


add_test(
	NAME	"${PROJECT_NAME}"
	COMMAND	"${PROJECT_NAME}"
)

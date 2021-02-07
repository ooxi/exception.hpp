# ooxi / exception / test / GlobalVsLocalExceptionTest
cmake_minimum_required(VERSION 3.5)


project("${PROJECT_NAME}-GlobalVsLocalExceptionTest" CXX)
add_executable("${PROJECT_NAME}")


target_sources(
	"${PROJECT_NAME}"
	PRIVATE
		"${CMAKE_CURRENT_LIST_DIR}/GlobalVsLocalExceptionTest.c++"
)


target_link_libraries(
	"${PROJECT_NAME}"
	PRIVATE
		ooxi::exception::c++20
)


add_test(
	NAME	"${PROJECT_NAME}"
	COMMAND	"${PROJECT_NAME}"
)

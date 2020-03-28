#include <cstdlib>
#include <filesystem>
#include <ooxi/exception/Exception.h++>
#include <string>





static void throwException() {
	THROW(MyException, "This is my exception");
}

static void throwAnotherException() {

	/* Do not move the next line or the test will fail!
	 */
	THROW(AnotherException, "Another exception");
}



int main() {
	using s = std::string;


	/* Base test
	 */
	try {
		throwException();
		return EXIT_FAILURE;

	} catch (std::exception& e) {
		if (s{"[MyException] This is my exception"} != e.what()) {
			return EXIT_FAILURE;
		}
	}


	/* Ensure more than one exception per translation unit is possible
	 */
	using ooxi::exception::ExtendedException;

	try {
		throwAnotherException();
		return EXIT_FAILURE;

	} catch (ExtendedException& e) {
		std::filesystem::path file{e.file()};

		if (s{"[AnotherException] Another exception"} != e.what()) {
			return EXIT_FAILURE;
		}

		if (s{"ExceptionTest.c++"} != file.filename()) {
			return EXIT_FAILURE;
		}

		if (18 != e.line()) {
			return EXIT_FAILURE;
		}

		if (s{"Another exception"} != e.message()) {
			return EXIT_FAILURE;
		}
	}


	return EXIT_SUCCESS;
}

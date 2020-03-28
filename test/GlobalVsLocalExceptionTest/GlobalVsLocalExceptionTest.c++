#include <cstdlib>
#include <exception>
#include <string>





class GlobalException final : public std::exception {
};

static void throwGlobalException() {
	throw GlobalException{};
}



static void throwLocalException() {
	class LocalException : public std::exception {
	};

	throw LocalException{};
}





int main() {

	/* Test globaler Ausnahme
	 */
	try {
		throwGlobalException();
		return EXIT_FAILURE;

	} catch (std::exception& e) {
		if (std::string{"std::exception"} != e.what()) {
			return EXIT_FAILURE;
		}
		if (std::string{"15GlobalException"} != typeid(e).name()) {
			return EXIT_FAILURE;
		}
	}


	/* Test lokaler Ausnahme
	 */
	try {
		throwLocalException();
		return EXIT_FAILURE;

	} catch (std::exception& e) {
		if (std::string{"std::exception"} != e.what()) {
			return EXIT_FAILURE;
		}
		if (std::string{"ZL19throwLocalExceptionvE14LocalException"} != typeid(e).name()) {
			return EXIT_FAILURE;
		}
	}


	return EXIT_SUCCESS;
}

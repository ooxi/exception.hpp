#include <cstdlib>
#include <exception>
#include <string>





/* @see https://gist.github.com/brimston3/2be168bb423c83b0f469c0be56e66d31
 */
#if defined(__clang__)
	#if __has_feature(cxx_rtti)
		#define RTTI_ENABLED
	#endif
#elif defined(__GNUG__)
	#if defined(__GXX_RTTI)
		#define RTTI_ENABLED
	#endif
#elif defined(_MSC_VER)
	#if defined(_CPPRTTI)
		#define RTTI_ENABLED
	#endif
#endif





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
		#if defined(RTTI_ENABLED)
		if (std::string{"15GlobalException"} != typeid(e).name()) {
			return EXIT_FAILURE;
		}
		#endif
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
		#if defined(RTTI_ENABLED)
		if (std::string{"ZL19throwLocalExceptionvE14LocalException"} != typeid(e).name()) {
			return EXIT_FAILURE;
		}
		#endif
	}


	return EXIT_SUCCESS;
}

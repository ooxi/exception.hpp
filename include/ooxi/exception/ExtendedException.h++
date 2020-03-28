#ifndef HEADER_OOXI_EXCEPTION_EXTENDED_EXCEPTION
#define HEADER_OOXI_EXCEPTION_EXTENDED_EXCEPTION


#include <cstddef>





namespace ooxi::exception {

	/**
	 * All local exceptions will implement this interface in order to
	 * provide additional information.
	 */
	class ExtendedException {
	public:
		virtual ~ExtendedException() = 0;

		virtual char const* what() const noexcept = 0;

		virtual char const* file() const noexcept = 0;
		virtual std::size_t line() const noexcept  = 0;

		virtual char const* message() const noexcept = 0;
	};
}


#endif

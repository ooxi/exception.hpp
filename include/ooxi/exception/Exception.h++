#ifndef HEADER_OOXI_EXCEPTION_EXCEPTION
#define HEADER_OOXI_EXCEPTION_EXCEPTION


#include <cstddef>
#include <exception>
#include <ooxi/exception/ExtendedException.h++>





#define THROW(ClassName, msg)									\
	{											\
		class ClassName final								\
			: public ::std::exception						\
			, public ::ooxi::exception::ExtendedException {				\
		public:										\
			explicit ClassName() {							\
			}									\
												\
			virtual ~ClassName() {							\
			}									\
												\
												\
			char const* what() const noexcept final {				\
				return "[" #ClassName "] " msg;					\
			}									\
												\
												\
			char const* file() const noexcept final {				\
				return __FILE__;						\
			}									\
												\
			::std::size_t line() const noexcept final {				\
				return __LINE__;						\
			}									\
												\
												\
			char const* message() const noexcept final {				\
				return "" msg;							\
			}									\
		};										\
												\
		throw ClassName{};								\
	}											\


#endif

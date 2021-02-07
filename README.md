[![Build Status](https://github.com/ooxi/exception.hpp/workflows/CI/badge.svg)](https://github.com/ooxi/exception.hpp/actions?query=workflow%3ACI+branch%3Amaster)

# Exception.h++

A simple header only library for defining custom exceptions.


## Example

```
#include <ooxi/exception/Exception.h++>

int main() {
	THROW(MyException, "This is my exception");
}
```

```
terminate called after throwing an instance of 'main::MyException'
  what():  [MyException] This is my exception
```

See [ExceptionTest](test/ExceptionTest/ExceptionTest.c++) for more examples and
how to access properties of a caught exception like
[source file](include/ooxi/exception/ExtendedException.h++#L23) and
[line number](include/ooxi/exception/ExtendedException.h++#L24).


## Quickstart

```
mc _ make
```


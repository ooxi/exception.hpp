.PHONY: all
all: clean build test


.PHONY: clean
clean:
	@if [ -d 'build' ]; then	\
		rm -rf 'build';	\
	fi

	@mkdir -p 'build'
	(cd 'build' && cmake -DCMAKE_BUILD_TYPE=Release ..)


.PHONY: build
build:
	$(MAKE) -C 'build'


.PHONY: test
test:
	$(MAKE) -C 'build' test


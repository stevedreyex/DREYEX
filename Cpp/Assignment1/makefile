.PHONY: clean dirs

all: dirs bin/ut_all exec

bin/ut_all: test/ut_all.cpp src/test_string.h
	g++ -o bin/ut_all test/ut_all.cpp -lgtest -lpthread

clean: bin
	rm -rf bin

dirs: 
	mkdir -p bin

test: test/*.cpp
	g++ -o bin/ut_all test/*.cpp -lgtest -lpthread

exec:
	bin/ut_all
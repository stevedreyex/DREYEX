.PHONY: clean dirs

all: dirs bin/ut_all

bin/ut_all: test/*
	g++ -o bin/ut_all test/ut_main.cpp -lgtest -lpthread

clean: bin
	rm -rf bin

dirs:
	mkdir -p bin

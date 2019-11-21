.PHONY: clean dirs stat

CFLAGS = -std=c++11 -Wfatal-errors
LIBS = -lgtest -lpthread
SRC_HEADERS = src/*
TEST_HEADERS = test/*

all: bin/ut_ip

bin/ut_ip: test/ut_ip.cpp $(TEST_HEADERS) $(SRC_HEADERS)
	g++ $(CFLAGS) -o $@ $< $(LIBS)

clean:
	rm -f bin/*

dirs:
	mkdir -p bin

stat:
	wc -l src/*
	wc -l test/*

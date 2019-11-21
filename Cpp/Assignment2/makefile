.PHONY: directories clean

all: directories bin/ut_all

bin/ut_all: obj/ut_main.o
	g++ -std=c++11 -o bin/ut_all test/ut_main.cpp -lgtest -lpthread

obj/ut_main.o: test/ut_main.cpp test/ut_vector.h
	g++ -std=c++11 -c test/ut_main.cpp -o obj/ut_main.o

directories:
	mkdir -p bin obj

clean:
	rm -rf bin obj

stat:
	wc src/* test/*

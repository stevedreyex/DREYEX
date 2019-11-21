all: directories bin/ut_all bin/user_main

bin/user_main: src/user_main.cpp src/bin_calc.h src/binary.h
	g++ -std=c++11 -o bin/user_main src/user_main.cpp

bin/ut_all: obj/ut_main.o
	g++ -std=c++11 -o bin/ut_all obj/ut_main.o -lgtest -lpthread

obj/ut_main.o: test/ut_main.cpp test/ut_binary.h src/bin_calc.h src/binary.h
	g++ -std=c++11 -c test/ut_main.cpp -o obj/ut_main.o

directories:
	mkdir -p bin obj

clean:
	rm -rf bin obj

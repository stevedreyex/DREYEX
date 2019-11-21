.PHONY: directories clean
CC=g++
CFLAGS=-std=c++11
LIBS=-lgtest -lpthread
OBJ=obj
BIN=bin
SRC=src
TEST=test

all: directories $(BIN)/ut_all

$(BIN)/ut_all: $(OBJ)/ut_main.o
	$(CC) $(CFLAGS) -o $@ $(OBJ)/ut_main.o $(LIBS)
$(OBJ)/ut_main.o: $(TEST)/ut_main.cpp $(TEST)/test_svg_shape.h $(SRC)/svg_circle.h $(SRC)/svg_polygon.h $(SRC)/svg_shape.h $(SRC)/svg_line.h
	$(CC) $(CFLAGS) -c $< -o $@

directories:
	mkdir -p bin obj

clean:
	rm -rf $(OBJ) $(BIN)

stat:
	wc $(SRC)/*.h $(SRC)/*.cpp

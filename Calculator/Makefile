#compiler
CC=g++

#compile flags
CFLAGS=-c -Wall -fexceptions -g -Iinclude

#compile files
SRC=main.cpp src/calculator.cpp
OBJ=$(SRC:%.cpp=%.o)

all: $(OBJ)
	$(CC) $(OBJ) -o main
	
%.o: %.cpp
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o
	rm -rf ./*/*.o

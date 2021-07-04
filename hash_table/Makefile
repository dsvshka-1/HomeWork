#compiler
CC=g++

#compile flags
CFLAGS=-Wall -fexceptions -Weffc++ -pedantic-errors -Wextra -std=c++17 -g -Iinclude -c

#compile files
SRC=main.cpp
OBJ=$(SRC:%.cpp=%.o)

all: $(OBJ)
	$(CC) $(OBJ) -o main
	
%.o: %.cpp
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o
	rm -rf ./*/*.o
	rm -f main
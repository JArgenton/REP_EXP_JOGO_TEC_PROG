CXX		  := g++
CXX_FLAGS := -Wall -Wextra -std=c++17 -ggdb

BIN		:= bin
SRC		:= src
INCLUDE	:= include
LIB		:= lib

LIBRARIES	:= -lsfml-graphics -lsfml-window -lsfml-system
EXECUTABLE	:= main

# Find all .cpp files in the src directory
SOURCES := $(wildcard $(SRC)/*.cpp)
# Replace .cpp with .o for each source file
OBJECTS := $(SOURCES:.cpp=.o)

all: $(BIN)/$(EXECUTABLE)

run: clean all
	@clear
	@./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(OBJECTS)
    
	@$(CXX) $(CXX_FLAGS) -I$(INCLUDE) -L$(LIB) $^ -o $@ $(LIBRARIES)

$(SRC)/%.o: $(SRC)/%.cpp
	@$(CXX) $(CXX_FLAGS) -I$(INCLUDE) -L$(LIB) -c $< -o $@

clean:
	@-rm $(SRC)/* $(SRC)/*.o

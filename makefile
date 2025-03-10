# Compiler
CXX = g++

# Compiler Flags
CXXFLAGS = -Wall -Wextra -std=c++11

# SFML Libraries (Linking)
SFML_LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

# Directories
SRC_DIR = .
MENU_DIR = menu

# Source Files
SRC = $(SRC_DIR)/main.cpp $(MENU_DIR)/menu.cpp $(MENU_DIR)/instruction.cpp $(MENU_DIR)/history.cpp

# Object Files
OBJ = $(SRC:.cpp=.o)

# Output Executable
TARGET = TicTacToe

# Default Rule: Build the Executable
all: $(TARGET)

# Compile Object Files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Link Executable with SFML
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(TARGET) $(SFML_LIBS)

# Clean Object Files and Executable
clean:
	rm -f $(OBJ) $(TARGET)

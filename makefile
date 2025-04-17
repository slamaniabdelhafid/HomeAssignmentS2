# Compiler
CXX = g++

# Compiler Flags
CXXFLAGS = -Wall -Wextra -std=c++11 -I. -I$(MENU_DIR) -I$(PUZZLE_DIR) -I$(MODEL_DIR) -I$(VIEW_DIR) -I$(CONTROLLER_DIR)

# SFML Libraries (Linking)
SFML_LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

# Google Test Flags
GTEST_FLAGS = -lgtest -lgtest_main -pthread

# Source Directories
MODEL_DIR = model
VIEW_DIR = view
CONTROLLER_DIR = controller
TEST_DIR = Test
PUZZLE_DIR = puzzle
MENU_DIR = menu
QUIZ_DIR = quiz
DOORS_DIR = doors
CHAR_DIR = character
MEMO_DIR = memo
SRC_DIR = .

# Main Source Files
SRCS = $(MODEL_DIR)/game_logic.cpp \
       $(MODEL_DIR)/player.cpp \
       $(VIEW_DIR)/bouton.cpp \
       $(VIEW_DIR)/game_view.cpp \
       $(CONTROLLER_DIR)/game_controller.cpp \
       $(SRC_DIR)/main.cpp \
       $(SRC_DIR)/winpage.cpp \
       $(MENU_DIR)/menu.cpp \
       $(MENU_DIR)/instruction.cpp \
       $(MENU_DIR)/history.cpp \
       $(PUZZLE_DIR)/puzzle.cpp \
       $(QUIZ_DIR)/quiz.cpp \
       $(DOORS_DIR)/doors.cpp \
       $(CHAR_DIR)/character.cpp \
       $(CHAR_DIR)/platform.cpp \
       $(CHAR_DIR)/arrow.cpp \
       $(CHAR_DIR)/message.cpp \
       $(MEMO_DIR)/GameBox.cpp \
       $(MEMO_DIR)/NumberGame.cpp

# Test Source Files
TEST_SRCS = $(TEST_DIR)/test_puzzle.cpp \
            $(TEST_DIR)/test_game_logic.cpp \
            $(TEST_DIR)/test_player.cpp \
            $(TEST_DIR)/test_doors.cpp \
            $(TEST_DIR)/test_quiz.cpp

# Main Object Files
OBJS = $(SRCS:.cpp=.o)

# Test Object Files
TEST_OBJS = $(TEST_SRCS:.cpp=.o) \
            $(MODEL_DIR)/game_logic.o \
            $(MODEL_DIR)/player.o \
            $(PUZZLE_DIR)/puzzle.o \
            $(DOORS_DIR)/doors.o \
            $(QUIZ_DIR)/quiz.o

# Output Executables
TARGET = TicTacToe
TEST_TARGET = test_all

# Default Rule: Build the main executable
all: $(TARGET)

# Rule to compile any .cpp file to .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Link main executable with SFML
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $(TARGET) $(SFML_LIBS)

# Build and run tests
test: $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) $(TEST_OBJS) $(GTEST_FLAGS) $(SFML_LIBS) -o $(TEST_TARGET)
	./$(TEST_TARGET)

# Clean all generated files
clean:
	rm -f $(OBJS) $(TARGET) $(TEST_OBJS) $(TEST_TARGET)

# Explicit rules for test dependencies
$(QUIZ_DIR)/quiz.o: $(QUIZ_DIR)/quiz.cpp $(QUIZ_DIR)/quiz.h
	$(CXX) $(CXXFLAGS) -c $(QUIZ_DIR)/quiz.cpp -o $(QUIZ_DIR)/quiz.o

$(TEST_DIR)/test_quiz.o: $(TEST_DIR)/test_quiz.cpp $(QUIZ_DIR)/quiz.h
	$(CXX) $(CXXFLAGS) -c $(TEST_DIR)/test_quiz.cpp -o $(TEST_DIR)/test_quiz.o

.PHONY: all test clean
# Compiler
CXX = g++

# Compiler Flags
CXXFLAGS = -Wall -Wextra -std=c++11 -I. -I$(MENU_DIR) -I$(PUZZLE_DIR) -I$(MODEL_DIR) -I$(VIEW_DIR) -I$(CONTROLLER_DIR)

# SFML Libraries (Linking)
SFML_LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

# Drapeaux pour Google Test
GTEST_FLAGS = -lgtest -lgtest_main -pthread

# Répertoires des sources
MODEL_DIR = model
VIEW_DIR = view
CONTROLLER_DIR = controller
TEST_DIR = Test
PUZZLE_DIR = puzzle
MENU_DIR = menu
SRC_DIR = .

# Fichiers sources principaux
SRCS = $(MODEL_DIR)/game_logic.cpp \
       $(MODEL_DIR)/player.cpp \
       $(VIEW_DIR)/bouton.cpp \
       $(VIEW_DIR)/game_view.cpp \
       $(CONTROLLER_DIR)/game_controller.cpp \
       $(SRC_DIR)/main.cpp \
       $(MENU_DIR)/menu.cpp \
       $(MENU_DIR)/instruction.cpp \
       $(MENU_DIR)/history.cpp \
       $(PUZZLE_DIR)/puzzle.cpp

# Fichiers de test
TEST_SRCS = $(TEST_DIR)/test_button.cpp \
            $(TEST_DIR)/test_player.cpp \
            $(TEST_DIR)/test_game_logic.cpp \
            $(TEST_DIR)/test_game_controller.cpp \
            $(VIEW_DIR)/bouton.cpp \
            $(MODEL_DIR)/player.cpp \
            $(MODEL_DIR)/game_logic.cpp \
            $(CONTROLLER_DIR)/game_controller.cpp \
            $(VIEW_DIR)/game_view.cpp 

# Fichiers objets principaux
OBJS = $(SRCS:.cpp=.o)

# Fichiers objets de test
TEST_OBJS = $(TEST_SRCS:.cpp=.o)

# Output Executable
TARGET = TicTacToe

# Default Rule: Build the Executable
all: $(TARGET)

# Compile Object Files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Link Executable with SFML
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $(TARGET) $(SFML_LIBS)

# Compiler et exécuter les tests
test: $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) $(TEST_OBJS) $(GTEST_FLAGS) $(SFML_LIBS) -o /test_all && /test_all

# Nettoyer les fichiers temporaires
clean:
	rm -f $(OBJS) $(TARGET)
# Compiler
CXX = g++

<<<<<<< HEAD
# Flags de compilation
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic

# Drapeaux pour SFML
SFML_FLAGS = -lsfml-graphics -lsfml-window -lsfml-system
=======
# Compiler Flags
CXXFLAGS = -Wall -Wextra -std=c++11 -I. -I$(MENU_DIR) -I$(PUZZLE_DIR) -I$(MODEL_DIR) -I$(VIEW_DIR) -I$(CONTROLLER_DIR)

# SFML Libraries (Linking)
SFML_LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
>>>>>>> 128a514 (update)

# Drapeaux pour Google Test
GTEST_FLAGS = -lgtest -lgtest_main -pthread

# Répertoires des sources
MODEL_DIR = model
VIEW_DIR = view
CONTROLLER_DIR = controller
TEST_DIR = Test
<<<<<<< HEAD

# Fichiers sources principaux
SRCS = main.cpp \
       $(MODEL_DIR)/game_logic.cpp \
       $(MODEL_DIR)/player.cpp \
       $(VIEW_DIR)/bouton.cpp \
       $(VIEW_DIR)/game_view.cpp \
       $(CONTROLLER_DIR)/game_controller.cpp

=======
PUZZLE_DIR = puzzle
MENU_DIR = menu
QUIZ_DIR = quiz
DOORS_DIR = doors
CHAR_DIR = character
MEMO_DIR = memo
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
       $(PUZZLE_DIR)/puzzle.cpp \
	   $(QUIZ_DIR)/quiz.cpp \
	   $(DOORS_DIR)/doors.cpp \
	   $(CHAR_DIR)/character.cpp \
	   $(CHAR_DIR)/platform.cpp \
	   $(CHAR_DIR)/arrow.cpp \
	   $(CHAR_DIR)/message.cpp \
	   $(MEMO_DIR)/GameBox.cpp \
	   $(MEMO_DIR)/NumberGame.cpp 
>>>>>>> 128a514 (update)
# Fichiers de test
TEST_SRCS = $(TEST_DIR)/test_button.cpp \
            $(TEST_DIR)/test_player.cpp \
            $(TEST_DIR)/test_game_logic.cpp \
            $(TEST_DIR)/test_game_controller.cpp \
            $(VIEW_DIR)/bouton.cpp \
            $(MODEL_DIR)/player.cpp \
            $(MODEL_DIR)/game_logic.cpp \
<<<<<<< HEAD
            $(CONTROLLER_DIR)/game_controller.cpp\
			$(VIEW_DIR)/game_view.cpp

# Options d'inclusion pour les fichiers d'en-tête
INCLUDES = -I$(MODEL_DIR) -I$(VIEW_DIR) -I$(CONTROLLER_DIR)

# Options d'inclusion pour SFML
SFML_INCLUDE = -I/usr/include/SFML

# Chemins des bibliothèques SFML
SFML_LIB = -L/usr/lib/x86_64-linux-gnu

# Règle principale : compiler et exécuter le programme principal
run:
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(SRCS) $(SFML_FLAGS) -o /tmp/tic_tac_toe && /tmp/tic_tac_toe

# Compiler et exécuter les tests
test: $(TEST_SRCS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(SFML_INCLUDE) $(TEST_SRCS) $(GTEST_FLAGS) $(SFML_FLAGS) $(SFML_LIB) -o /tmp/test_all && /tmp/test_all

# Nettoyer les fichiers temporaires
clean:
	rm -f /tmp/tic_tac_toe /tmp/test_all

.PHONY: run test clean
=======
            $(CONTROLLER_DIR)/game_controller.cpp \
            $(VIEW_DIR)/game_view.cpp 

# Fichiers objets principaux
OBJS = $(SRCS:.cpp=.o)

# Fichiers objets de test
TEST_OBJS = $(TEST_SRCS:.cpp=.o)

# Output Executable
TARGET = TicTacToe
TEST_TARGET = test_all

# Default Rule: Build the Executable
all: $(TARGET)

# Compile Object Files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Link Executable with SFML
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $(TARGET) $(SFML_LIBS)

# Compile and run tests
test: $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) $(TEST_OBJS) $(GTEST_FLAGS) $(SFML_LIBS) -o $(TEST_TARGET)
	./$(TEST_TARGET)

# Nettoyer les fichiers temporaires
clean:
	rm -f $(OBJS) $(TARGET) $(TEST_TARGET)
>>>>>>> 128a514 (update)

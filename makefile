# Compiler
CXX = g++

# Flags de compilation
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic

# Drapeaux pour SFML
SFML_FLAGS = -lsfml-graphics -lsfml-window -lsfml-system

# Drapeaux pour Google Test
GTEST_FLAGS = -lgtest -lgtest_main -pthread

# Répertoires des sources
MODEL_DIR = model
VIEW_DIR = view
CONTROLLER_DIR = controller
TEST_DIR = Test

# Fichiers sources principaux
SRCS = main.cpp \
       $(MODEL_DIR)/game_logic.cpp \
       $(MODEL_DIR)/player.cpp \
       $(VIEW_DIR)/bouton.cpp \
       $(VIEW_DIR)/game_view.cpp \
       $(CONTROLLER_DIR)/game_controller.cpp

# Fichiers de test
TEST_SRCS = $(TEST_DIR)/test_button.cpp \
            $(TEST_DIR)/test_player.cpp \
            $(TEST_DIR)/test_game_logic.cpp \
            $(TEST_DIR)/test_game_controller.cpp \
            $(VIEW_DIR)/bouton.cpp \
            $(MODEL_DIR)/player.cpp \
            $(MODEL_DIR)/game_logic.cpp \
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
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(SFML_INCLUDE) $(TEST_SRCS) $(GTEST_FLAGS) $(SFML_FLAGS) $(SFML_LIB) -o ./test_all && ./test_all

# Nettoyer les fichiers temporaires
clean:
	rm -f /tmp/tic_tac_toe /tmp/test_all

.PHONY: run test clean


# Nom de l'exécutable
EXEC = TicTacToe

# Compilateur et options
CXX = g++
CXXFLAGS = -Wall -std=c++17

# Bibliothèques SFML
SFML_LIBS = -lsfml-graphics -lsfml-window -lsfml-system

# Fichiers sources et objets
SRC = main.cpp
OBJ = $(SRC:.cpp=.o)

# Règle principale pour compiler le projet
all: $(EXEC)

# Compilation de l'exécutable
$(EXEC): $(OBJ)
	$(CXX) -o $(EXEC) $(OBJ) $(SFML_LIBS)

# Compilation des fichiers objets
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Nettoyer les fichiers compilés
clean:
	rm -f $(OBJ) $(EXEC)

# Exécuter le programme après compilation
run: all
	./$(EXEC)

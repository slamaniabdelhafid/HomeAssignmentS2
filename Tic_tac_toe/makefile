# Compiler et options
CXX = g++
CXXFLAGS = -std=c++11 -Wall -I/path/to/sfml/include  # Si besoin d'inclure des dossiers spécifiques
LDFLAGS = -L/path/to/sfml/lib -lsfml-graphics -lsfml-window -lsfml-system  # Lier SFML

# Cibles et fichiers
SRC = main.cpp  # Ajoutez vos autres fichiers .cpp ici
OBJ = $(SRC:.cpp=.o)
EXEC = ../build-Debug/bin/Tic_tac_toe

# Règle de compilation
all: $(EXEC)

$(EXEC): $(OBJ)
    $(CXX) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
    $(CXX) -o $@ -c $< $(CXXFLAGS)

clean:
    rm -f $(OBJ) $(EXEC)
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
SRC_DIR = ./impl
INC_DIR = ./headers
OBJ_DIR = ./obj
BUILD_DIR = ./build
EXEC = game

# Listez tous les fichiers source
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
# Ajoutez main.cpp à la liste des fichiers source
SRCS += main.cpp
# Générer une liste d'objets correspondant à chaque fichier source
OBJS := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

# Règle pour compiler chaque fichier source en un fichier objet
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -I$(INC_DIR) -c $< -o $@

# Règle pour créer l'exécutable final en liant tous les fichiers objets
$(BUILD_DIR)/$(EXEC): $(OBJS)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

.PHONY: clean

clean:
	@rm -rf $(OBJ_DIR) $(BUILD_DIR)

run: $(BUILD_DIR)/$(EXEC)
	@./$(BUILD_DIR)/$(EXEC)
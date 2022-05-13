CC		= g++
CFLAGS	= -Wall -O2 -g

LDFLAGS	=  -lSDL2main -lSDL2 -lGL -lGLU -lSDL2_image

BIN_DIR	= bin
INC_DIR = -I include
SRC_DIR	= src
OBJ_DIR	= obj


SRC_FILES 	= $(shell find $(SRC_DIR)/ -type f -name '*.cpp')
OBJ_FILES 	= $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o, $(SRC_FILES))
EXEC_BIN	= main


all : $(OBJ_FILES)

Game : $(OBJ_FILES)
	$(CC) -o $(BIN_DIR)/$(EXEC_BIN) $(OBJ_FILES) $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) -c $< -o $@ $(CFLAGS) $(INC_DIR)

clean :
	rm -rf *~
	rm -r obj/*

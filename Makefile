CC		= gcc
CFLAGS	= -Wall -O2 -g
LDFLAGS	= -lmingw32 -lSDL2main -lSDL2 -lglu32 -lopengl32 -lSDL2_image

BIN_DIR	= bin
INC_DIR = -I include
SRC_DIR	= src
OBJ_DIR	= obj

SRC_FILES 	= src/main.c 
OBJ_FILES 	= obj/main.o 
EXEC_BIN	= game


all : $(OBJ_FILES)

Game : $(OBJ_FILES)
	$(CC) -o $(BIN_DIR)/$(EXEC_BIN) $(OBJ_FILES) $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c $< -o $@ $(CFLAGS) $(INC_DIR)

clean :
	rm -rf *~
	rm -rf $(SRC_DIR)/*/*~
	rm -rf $(OBJ_DIR)/
	rm -rf $(BIN_DIR)/*
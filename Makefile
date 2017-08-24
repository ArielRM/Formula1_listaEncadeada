OBJ_DIR=./obj/
SRC_DIR=./src/
INCLUDE=./include/

PROG=f1.bin

SRC = $(wildcard $(SRC_DIR)*.c)
OBJ = $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRC))


all: $(PROG)

$(PROG) : $(OBJ)
	gcc -o $@ $^

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	gcc -c $< -o $@
	
clean: 
	rm ./obj/*.o ./$(PROG)
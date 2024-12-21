CC = gcc
SRC = main.c hashmap.c file_io.c utils.c

OUT = kv_store

all: $(OUT)

$(OUT): $(SRC)
	@$(CC)  -o $@ $^

clean:
	@rm -f $(OBJ) $(OUT)

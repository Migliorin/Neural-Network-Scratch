CC = gcc
CFLAGS = -Wall -Wno-implicit-function-declaration -Iinclude
BUILD = build
SRC = src

test: $(BUILD) $(BUILD)/test.out

$(BUILD):
	mkdir -p $(BUILD)

$(BUILD)/test.out: $(BUILD)/matrix.o $(BUILD)/test.o
	$(CC) $(CFLAGS) $(BUILD)/matrix.o $(BUILD)/test.o -o $(BUILD)/test.out


$(BUILD)/matrix.o: $(SRC)/matrix.c
	$(CC) $(CFLAGS) -c $(SRC)/matrix.c -o $(BUILD)/matrix.o


$(BUILD)/test.o: $(SRC)/test.c
	$(CC) $(CFLAGS) -c $(SRC)/test.c -o $(BUILD)/test.o



# Por p "|" no final forca o makefile chamar a regra $(BUILD)
# para criar o dir build e ai sim compilar
# $(BUILD)/linear.out: $(SRC)/linear.c | $(BUILD)
# 	@echo "Compiling linear file"
# 	$(CC) $(CFLAGS) $(SRC)/linear.c -o $(BUILD)/linear.out
#
# $(BUILD)/main.out: $(SRC)/main.c | $(BUILD)
# 	@echo "Compiling main file"
# 	$(CC) $(CFLAGS) $(SRC)/main.c -o $(BUILD)/main.out
#

clean:
	rm -rf $(BUILD)

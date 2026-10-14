# Gerador de Oferta de Disciplinas do IC/UFAL
#
#   make         compila (src/*.c -> obj/*.o -> bin/oferta)
#   make run     gera a oferta a partir dos arquivos de dados/
#   make test    gera a oferta e compara com tests/oferta_esperada.txt
#   make clean   remove obj/, bin/ e a oferta gerada

# O padrão do make para CC é "cc"; usa gcc, a menos que CC seja
# definido no ambiente ou na linha de comando (ex.: make CC=clang).
ifeq ($(origin CC),default)
CC := gcc
endif

CFLAGS   = -Wall -Wextra -std=c11
CPPFLAGS = -Iinclude -MMD -MP
LDFLAGS  =
LDLIBS   =

SRC_DIR   := src
OBJ_DIR   := obj
BIN_DIR   := bin
DADOS_DIR := dados
ESPERADA  := tests/oferta_esperada.txt

# No Windows (MSYS2/MinGW), o GCC gera o executável com .exe.
ifeq ($(OS),Windows_NT)
EXE := .exe
endif

SRCS   := $(wildcard $(SRC_DIR)/*.c)
OBJS   := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))
DEPS   := $(OBJS:.o=.d)
TARGET := $(BIN_DIR)/oferta$(EXE)

.PHONY: all run test clean

all: $(TARGET)

$(TARGET): $(OBJS) | $(BIN_DIR)
	$(CC) $(LDFLAGS) $(OBJS) $(LDLIBS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(OBJ_DIR) $(BIN_DIR):
	mkdir -p $@

# O programa lê e escreve no diretório atual, então roda dentro de dados/.
run: $(TARGET)
	cd $(DADOS_DIR) && ../$(TARGET)

test: $(TARGET)
	cd $(DADOS_DIR) && ../$(TARGET) > /dev/null
	@if cmp -s $(DADOS_DIR)/oferta.txt $(ESPERADA); then \
		echo "OK: $(DADOS_DIR)/oferta.txt confere com $(ESPERADA)"; \
	else \
		echo "FALHOU: $(DADOS_DIR)/oferta.txt difere de $(ESPERADA)"; \
		diff $(ESPERADA) $(DADOS_DIR)/oferta.txt; \
		exit 1; \
	fi

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR) $(DADOS_DIR)/oferta.txt

-include $(DEPS)

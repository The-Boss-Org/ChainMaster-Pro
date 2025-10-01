CC=gcc
CFLAGS=-Iinclude -Wall -Wextra -O2
CFLAGS_DEBUG=-Iinclude -Wall -Wextra -g

SRC_CORE=src/core/list_simple.c \
         src/core/list_double.c \
         src/core/list_circulaire_simple.c \
         src/core/list_circulaire_double.c \
         src/core/common.c

SRC_INTERFACE=src/core/interface/main.c
SRC_EXAMPLE=examples/demo_complete.c
SRC_TUTORIAL=examples/tutorial.c
SRC_TESTS=src/tests/test_runner.c

BUILD_DIR=build
BIN=$(BUILD_DIR)/demo
BIN_ALL=$(BUILD_DIR)/demo_all
BIN_TUTORIAL=$(BUILD_DIR)/tutorial
BIN_TESTS=$(BUILD_DIR)/test_runner

all: demo demo_all tutorial test-build

$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

$(BIN): $(SRC_CORE) $(SRC_INTERFACE) | $(BUILD_DIR)
	$(CC) $(CFLAGS) $^ -o $@

install: all
	@echo "Install step placeholder (no system-wide install)."

Demo: demo

demo: $(BIN)
	@echo "--- Lancement du demo interface ---"
	$(BIN)

demo_all: $(BIN_ALL)
	@echo "--- Lancement du demo complet ---"
	$(BIN_ALL)

$(BIN_ALL): $(SRC_CORE) $(SRC_EXAMPLE) | $(BUILD_DIR)
	$(CC) $(CFLAGS) $^ -o $@

tutorial: $(BIN_TUTORIAL)
	@echo "--- Lancement du tutorial ---"
	$(BIN_TUTORIAL)

$(BIN_TUTORIAL): $(SRC_CORE) $(SRC_TUTORIAL) | $(BUILD_DIR)
	$(CC) $(CFLAGS) $^ -o $@

test-build: $(BIN_TESTS)
	@echo "Tests compilés avec succès"

$(BIN_TESTS): $(SRC_CORE) $(SRC_TESTS) | $(BUILD_DIR)
	$(CC) $(CFLAGS) $^ -o $@

test-all: $(BIN_TESTS)
	@echo "--- Exécution de la suite de tests ---"
	$(BIN_TESTS)

benchmark:
	@echo "🏁 Benchmark mode: compilation optimisée"
	$(CC) $(CFLAGS) -O3 $(SRC_CORE) $(SRC_EXAMPLE) -o $(BUILD_DIR)/benchmark
	@echo "Exécution du benchmark..."
	$(BUILD_DIR)/benchmark

check-memory: $(BIN_ALL)
	@echo "🔍 Vérification mémoire (nécessite valgrind sur Linux/Mac)"
	@echo "Sur Windows, utilisez Dr. Memory ou compilez avec -fsanitize=address"
	@echo "Commande: valgrind --leak-check=full $(BIN_ALL)"

clean:
	rm -rf $(BUILD_DIR)

help:
	@echo "ChainMaster Pro - Makefile Commands"
	@echo "===================================="
	@echo "make all         - Compile tous les programmes"
	@echo "make demo        - Exécuter le demo interface"
	@echo "make demo_all    - Exécuter le demo complet (5 exercices)"
	@echo "make tutorial    - Exécuter le tutorial guidé"
	@echo "make test-all    - Exécuter la suite de tests"
	@echo "make benchmark   - Tester les performances"
	@echo "make clean       - Nettoyer les fichiers compilés"
	@echo "make help        - Afficher cette aide"

.PHONY: all install demo demo_all tutorial test-build test-all benchmark check-memory clean help

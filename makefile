CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude
LDFLAGS = -pthread
TESTFLAGS = -lgtest -lgtest_main

SRC_DIR = src
TEST_DIR = tests
OBJ_DIR = obj
BIN_DIR = bin
TEST_OBJ_DIR = $(OBJ_DIR)/tests

MAIN_SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
TEST_SOURCES = $(wildcard $(TEST_DIR)/*.cpp)

MAIN_OBJECTS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(MAIN_SOURCES))
TEST_OBJECTS = $(patsubst $(TEST_DIR)/%.cpp,$(TEST_OBJ_DIR)/%.o,$(TEST_SOURCES))

EXECUTABLE = $(BIN_DIR)/neon_fx
TEST_EXEC = $(BIN_DIR)/neon_fx_test

all: $(EXECUTABLE) test

$(EXECUTABLE): $(MAIN_OBJECTS) | $(BIN_DIR)
	$(CXX) $(LDFLAGS) $^ -o $@

$(TEST_EXEC): $(filter-out $(OBJ_DIR)/main.o,$(MAIN_OBJECTS)) $(TEST_OBJECTS) | $(BIN_DIR)
	$(CXX) $(LDFLAGS) $^ $(TESTFLAGS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(TEST_OBJ_DIR)/%.o: $(TEST_DIR)/%.cpp | $(TEST_OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(TEST_OBJ_DIR):
	mkdir -p $(TEST_OBJ_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

test: $(TEST_EXEC)
	@echo "Running tests..."
	@./$(TEST_EXEC)

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

.PHONY: all clean test
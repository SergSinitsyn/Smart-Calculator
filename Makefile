CXX						:= g++ -std=c++17
CXXFLAGS 				:= -Wall -Werror -Wextra -g -fPIC -O0
COVFLAGS				:= -fprofile-arcs -ftest-coverage -fprofile-abs-path --coverage
CLEAN					:= rm -rf

OC := $(shell uname)
ifeq ($(OC),Darwin)
	LEAKS 				:= CK_FORK=no leaks --atExit --
	LDFLAGS 			:= -lgtest -lgtest_main -lm -lstdc++ $(shell pkg-config --cflags gtest)
	OPEN 				:= open
	APP					:= $(EXECUTABLE).app
else
	LEAKS 				:= valgrind --leak-check=full --track-origins=yes -s
	LDFLAGS				:= -lgtest -lgtest_main -lm -lstdc++ -lpthread $(shell pkg-config --cflags gtest)
	OPEN 				:= xdg-open
	APP					:= $(EXECUTABLE)
endif

SRC_DIR 				:= ./src/
SRC_MODEL_DIR 			:= $(SRC_DIR)/model/
TESTS_DIR				:= ./tests/
BUILD_DIR 				:= ./build/
BUILD_MODEL_DIR 		:= ./build_model/
REPORT_DIR 				:= ./report/
DOCUMENT_DIR 			:= ./document/

PROJECT_FILES 			:= $(shell find $(SRC_DIR) -name '*.cc' -o -name '*.h')

SRC 					:= $(shell find $(SRC_MODEL_DIR) -name '*.cc')
HEADERS 				:= $(shell find $(SRC_MODEL_DIR) -name '*.h')
TESTS_SRC 				:= $(wildcard $(TESTS_DIR)*.cc)

OBJ 					:= $(patsubst $(SRC_MODEL_DIR)%.cc, $(BUILD_MODEL_DIR)%.o, $(SRC))
TESTS_OBJ 				:= $(patsubst $(TESTS_DIR)%.cc, $(BUILD_MODEL_DIR)%.o, $(TESTS_SRC))

GCOV_FILES 				:= $(shell find $(BUILD_MODEL_DIR) -name '*.gcno' -o -name '*.gcda')

EXECUTABLE				:= SmartCalc
TESTS_EXECUTABLE		:= $(EXECUTABLE)_tests
DIST_NAME 				:= $(EXECUTABLE)-$(VERSION)
VERSION 				:= 1.0

all: install

rebuild: uninstall build
	
build:
	qmake CONFIG+=release -o $(BUILD_DIR)/Makefile $(SRC_DIR)/$(EXECUTABLE).pro
	-cd $(BUILD_DIR); make

install:
	qmake CONFIG+=release -o $(BUILD_DIR)/Makefile $(SRC_DIR)/$(EXECUTABLE).pro
	-cd $(BUILD_DIR); make
	-cd $(BUILD_DIR); make clean

uninstall:
	$(CLEAN) $(BUILD_DIR)

$(TESTS_EXECUTABLE): $(OBJ) $(TESTS_OBJ)
	$(CXX) $(CXXFLAGS) $(COVFLAGS) $(OBJ) $(TESTS_OBJ) $(LDFLAGS) -o $@

$(BUILD_MODEL_DIR)%.o: $(SRC_MODEL_DIR)%.cc $(SRC_MODEL_DIR)%.h
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(COVFLAGS) -c $< -o $@

$(BUILD_MODEL_DIR)%.o: $(TESTS_DIR)%.cc
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(COVFLAGS) -c $< -o $@

test: $(TESTS_EXECUTABLE)
	./$(TESTS_EXECUTABLE)

$(REPORT_DIR)/index.html: test
	mkdir -p $(dir $@) 
	lcov -t "$(TESTS_EXECUTABLE)" -o $(REPORT_DIR)/$(TESTS_EXECUTABLE).info -c -d . --no-external --ignore-errors inconsistent
	genhtml -o $(REPORT_DIR) $(REPORT_DIR)/$(TESTS_EXECUTABLE).info

report: $(REPORT_DIR)/index.html
	$(OPEN) $(REPORT_DIR)/index.html

dist:
	$(CLEAN) $(DIST_NAME).tar.gz
	tar -cvf $(DIST_NAME).tar.gz Makefile $(SRC_DIR) $(TESTS_DIR) linters README.md images LICENSE.txt

dvi:
	mkdir -p $(DOCUMENT_DIR)
	makeinfo -o $(DOCUMENT_DIR) --html --no-warn --no-validate --force $(SRC_DIR)/documentation.texi

linter:
	cp linters/.clang-format ./
	clang-format -i --style=LLVM $(PROJECT_FILES) $(TESTS_SRC)
	rm -f .clang-format

run_linter:
	cp linters/.clang-format ./
	clang-format -n --style=LLVM $(PROJECT_FILES) $(TESTS_SRC)
	rm -f .clang-format

clean:
	$(CLEAN) $(BUILD_DIR)
	$(CLEAN) $(BUILD_MODEL_DIR)
	$(CLEAN) $(TESTS_EXECUTABLE)
	$(CLEAN) $(REPORT_DIR)
	$(CLEAN) $(DIST_NAME)

cppcheck:
	cppcheck --std=c++17 --enable=all --language=c++ --suppress=missingIncludeSystem $(TESTS_SRC) $(PROJECT_FILES)

leaks: $(TESTS_EXECUTABLE)
	$(LEAKS) ./$(TESTS_EXECUTABLE)

.PHONY: all clean test buold rebuild install uninstall report linter cppcheck dvi
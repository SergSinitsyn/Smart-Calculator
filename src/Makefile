CC						= g++ -std=c++17
WFLAGS 					= -Wall -Werror -Wextra
GCOVFLAGS 				= --coverage
CLEAN					= rm -rf
TEXI2DVI 				= makeinfo --html

OC := $(shell uname)
ifeq ($(OC),Darwin)
	LEAKS 				= CK_FORK=no leaks --atExit --
	CHECKFLAGS 			= -lgtest -lgtest_main -lm -lstdc++ $(shell pkg-config --cflags gtest)
	OPEN 				= open
	APP					= $(NAME).app
else
	LEAKS 				= valgrind --leak-check=full --track-origins=yes -s
	CHECKFLAGS			= -lgtest -lgtest_main -lm -lstdc++ -lpthread $(shell pkg-config --cflags gtest)
	OPEN 				= xdg-open
	APP					= $(NAME)
endif

NAME					= SmartCalc

SRC_DIR					= ./model/*
SOURCE_FILES			= *.cc

TEST_FILE				= $(NAME)_test
TEST_FILE_COV			= $(TEST_FILE)_cov

TEST_DIR				= ./tests
TEST_SOURCE_FILE		= $(TEST_FILE).cc

SOURCE					= $(SRC_DIR)/$(SOURCE_FILES) 
TEST 					= $(TEST_DIR)/$(TEST_SOURCE_FILE)

BUILD_DIR 				= ../build
DOCUMENT_DIR			= ../documentation
DOCUMENT				= documentation
DIST_NAME 				= $(NAME)-1.0

all: install

clean:
	$(CLEAN) $(TEST_FILE) $(TEST_FILE_FOR_LEAKS) $(TEST_FILE_COV) .clang-format
	$(CLEAN) *.o *.a *.gcno *.gcda *.info *.out *.gch *.dSYM report
	$(CLEAN) ../$(DIST_NAME).tar.gz ../$(DIST_NAME)
	$(CLEAN) ../documentation
	$(CLEAN) report*

$(TEST_FILE): $(SOURCE) $(TEST)
	$(CC) $(WFLAGS) $(SOURCE) $(TEST) -o $(TEST_FILE) $(CHECKFLAGS)

test: $(TEST_FILE)
	./$(TEST_FILE)

rebuild: clean all

report/index.html: $(SOURCE) $(TEST)
	$(CC) $(WFLAGS) $(GCOVFLAGS) $(SOURCE) $(TEST) -o $(TEST_FILE_COV) $(CHECKFLAGS)
	./$(TEST_FILE_COV)
	lcov -t "$(TEST_FILE_COV)" -o $(TEST_FILE_COV).info -c -d . --no-external
	genhtml -o report $(TEST_FILE_COV).info

gcov_report: report/index.html
	open report/index.html

build:
	qmake CONFIG+=release -o $(BUILD_DIR)/Makefile $(NAME).pro
	-cd $(BUILD_DIR); make
	
install: uninstall
	qmake CONFIG+=release -o $(BUILD_DIR)/Makefile $(NAME).pro
	-cd $(BUILD_DIR); make
	-cd $(BUILD_DIR); make clean
	$(CLEAN) $(BUILD_DIR)/Makefile
	$(CLEAN) $(BUILD_DIR)/.qmake.stash
	$(CLEAN) $(BUILD_DIR)/qmake_qmake_qm_files.qrc
	$(CLEAN) $(BUILD_DIR)/.qm

uninstall: clean
	$(CLEAN) $(BUILD_DIR)	

dvi:
	makeinfo -o $(DOCUMENT_DIR) --html --no-warn --no-validate --force $(DOCUMENT).texi
	make open_dvi

open_report:
	-$(OPEN) report/index.html

open_dvi:
	-$(OPEN) $(DOCUMENT_DIR)/index.html

dist:
	make clean
	cd ..; $(CLEAN) $(DIST_NAME).tar.gz
	$(CLEAN) ../$(DIST_NAME)
	cd ..; cp -r src $(DIST_NAME)
	cd ..; tar -cvf $(DIST_NAME).tar.gz $(DIST_NAME)
	$(CLEAN) ../$(DIST_NAME)

check: leaks cppcheck linter

linter:
	@cp ../linters/.clang-format ./
	@clang-format -n $(TEST)
	@clang-format -n $(SOURCE)
	@clang-format -n view/*/*.cc view/*/*.h
	@clang-format -n controller/*.cc controller/*.h
	@clang-format -n main.cc
	@rm -f .clang-format

run_linter:
	@cp ../linters/.clang-format ./
	@clang-format -i $(TEST)
	@clang-format -i $(SOURCE)
	@clang-format -i view/*/*.cc view/*/*.h
	@clang-format -i controller/*.cc controller/*.h
	@clang-format -i main.cc
	@rm -f .clang-format

cppcheck:
	cppcheck --std=c++17 --enable=all --language=c++ --suppress=missingIncludeSystem $(TEST) $(SOURCE)

leaks: $(TEST_FILE)
	$(LEAKS) ./$(TEST_FILE)

.PHONY: all clean test gcov_report rebuild linter cppcheck leaks check

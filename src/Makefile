CC					= g++ -std=c++17
WFLAGS 				= -Wall -Werror -Wextra
GCOVFLAGS 			= --coverage
CLEAN				= rm -rf

OC := $(shell uname)
ifeq ($(OC),Darwin)
	LEAKS = CK_FORK=no leaks --atExit --
	CHECKFLAGS = -lgtest -lgtest_main -lm -lstdc++ $(shell pkg-config --cflags gtest) 
else
	LEAKS = valgrind --leak-check=full --track-origins=yes -s
	CHECKFLAGS = -lgtest -lgtest_main -lm -lstdc++ -lpthread $(shell pkg-config --cflags gtest) 
endif

NAME				= SmartCalc_V2

SRC_DIR				= ./model
SOURCE_FILES		= *.cc
# HEADERS 			= $(SRC_DIR)/$(NAME).h $(SRC_DIR)/$(NAME_PLUS).h */*.h

TEST_FILE			= $(NAME)_test
TEST_FILE_COV		= $(TEST_FILE)_cov
TEST_FILE_FOR_LEAKS	= $(TEST_FILE)_leaks

TEST_DIR			= ./tests
TEST_SOURCE_FILE	= $(TEST_FILE).cc
# TEST_SOURCE_FILE_2	= $(TEST_FILE)_throw.cc */*_throw.cc


SOURCE				= $(SRC_DIR)/$(SOURCE_FILES) 
TEST 				= $(TEST_DIR)/$(TEST_SOURCE_FILE) 
# $(TEST_DIR)/$(TEST_SOURCE_FILE_2)
TEST_LEAKS 			= $(TEST_DIR)/$(TEST_SOURCE_FILE)


all: test

clean:
	$(CLEAN) $(TEST_FILE) $(TEST_FILE_FOR_LEAKS) $(TEST_FILE_COV) .clang-format
	$(CLEAN) *.o *.a *.gcno *.gcda *.info *.out *.gch *.dSYM report
	$(CLEAN) report*

$(TEST_FILE): $(SOURCE) $(TEST)
	$(CC) $(WFLAGS) $(SOURCE) $(TEST) -o $(TEST_FILE) $(CHECKFLAGS)

test: $(TEST_FILE)
	./$(TEST_FILE)

rebuild: clean all

report/index.html: $(SOURCES) $(TEST)
	$(CC) $(WFLAGS) $(GCOVFLAGS) $(TEST) $(SOURCES) -o $(TEST_FILE_COV) $(CHECKFLAGS)
	./$(TEST_FILE_COV)
	lcov -t "$(TEST_FILE_COV)" -o $(TEST_FILE_COV).info -c -d . --no-external
	genhtml -o report $(TEST_FILE_COV).info

gcov_report: report/index.html
	open report/index.html

gcovr_report: $(HEADERS) $(TEST)
	$(CC) $(WFLAGS) $(TEST) $(GCOVFLAGS) -o $(TEST_FILE_COV) $(CHECKFLAGS)
	./$(TEST_FILE_COV)
	gcovr --html --html-details -o report.html
	open report.html

check: leaks cppcheck linter

linter:
	@cp ../materials/linters/.clang-format ./
	@clang-format -n $(TEST) $(HEADERS)
	@rm -f .clang-format

cppcheck:
	cppcheck --std=c++17 --enable=all --language=c++ --suppress=missingIncludeSystem $(SOURCES) $(TEST)

$(TEST_FILE_FOR_LEAKS): $(SOURCES) $(TEST_LEAKS)
	$(CC) $(WFLAGS) $(TEST_LEAKS) $(SOURCES) -o $(TEST_FILE_FOR_LEAKS) $(CHECKFLAGS)

leaks: $(TEST_FILE_FOR_LEAKS)
	$(LEAKS) ./$(TEST_FILE_FOR_LEAKS)

.PHONY: all clean test gcov_report rebuild linter cppcheck leaks check

fff:  #!delete this
	grep ASSERT_ANY_THROW -n */*

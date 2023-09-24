# Ubuntu Makefile
# В терминале необходимо запустить следующие команды:
# sudo apt install lcov
# sudo apt install check

# Mac Makefile
# установить brew https://www.notion.so/Homebrew-goinfre-af3acfc9cfee424481a8a08c204ff272
# brew install lcov

OS=$(shell uname)
CC = gcc
CFLAGS = -Wall -Werror -Wextra
SOURCES = s21_math.c
OBJECTS = $(SOURCES:c=o)
TSOURCES = test.c
TOBJECTS = $(TSOURCES:c=o)

ifeq (${OS}, Linux)
	TESTFLAGS = -lcheck -lm -lpthread -lrt -lsubunit
else
	TESTFLAGS = -lcheck
endif

all: s21_math.a

s21_math.a: 
	$(CC) $(CFLAGS) -c $(SOURCES) 
	ar rcs s21_math.a $(OBJECTS)
	ranlib s21_math.a

cov_library:
	$(CC) $(CFLAGS) --coverage -c $(SOURCES) 
	ar rcs s21_math.a $(OBJECTS)

test: cov_library
	$(CC) $(CFLAGS) -c $(TSOURCES) 
	$(CC) $(TOBJECTS) s21_math.a $(TESTFLAGS) -lgcov -o test 
	./test > test_report.txt

gcov_report: test
	lcov -o s21_math.info -c -d .
	genhtml -o report s21_math.info
	# open report/index.html
clean:
	rm -rf *.o *.a *.gcno *.gcda *.info *.txt report test

rebuild: clean all

## ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ##
##                   COLOR THEME                   ##
## ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ##
DEFAULT=\033[0m 
## ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ##
WHITE_FG=\033[37m 
RED_FG=\033[31m 
GREEN_FG=\033[32m 
YELLOW_FG=\033[33m 
BLUE_FG=\033[34m 
PURPLE_FG=\033[35m 
CYAN_FG=\033[36m 
BLACK_FG=\033[30m 
## ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ##
WHITE_BG=\033[47m 
RED_BG=\033[41m 
GREEN_BG=\033[42m
YELLOW_BG=\033[43m  
BLUE_BG=\033[44m 
PURPLE_BG=\033[45m
CYAN_BG=\033[46m 
BLACK_BG=\033[40m 

## ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ## 
##                   VARIABLES                     ## 
## ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ## 
CC=g++
LIB_NAME=s21_smartcalc_v2.0.h
CC_FLAGS=-Wall -Werror -Wextra -std=c++17
GCOV_FLAGS=-coverage 
VERSION = 2.0
PACKAGE = s21_calc-$(VERSION)
LGTEST_FLAGS = -lgtest -lgtest_main -pthread
SOURCES := $(shell find model/ -name "*.cc" ! -name "*_test*")
ifeq ($(OS), Linux)
  OPEN=xdg-open
else
  OPEN=open
endif

## ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ## 
##                    COMMANDS                     ##
## ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ## 
all: clean
	g++ -c $(SOURCES) -Wall -Werror -Wextra -std=c++17
	g++ *.o model/main.cpp

# install: clean
# 	mkdir build
# 	#cp logic/*.c gui && cp logic/*.h gui
# 	cd build/ && qmake ../view/Calculate.pro && make
# 	open build/Calculate.app

install: clean
	mkdir -p build
	cd build && qmake ../view/Calculate.pro CONFIG+=debug CONFIG+=qml_debug && make
	open build/Calculate.app

uninstall: clean

.PHONY: test
test:
	@echo "\n"
	@echo "$(BLACK_FG)$(GREEN_BG)                                                $(DEFAULT)"
	@echo "$(BLACK_FG)$(GREEN_BG)               CREATE TEST                      $(DEFAULT)"
	@echo "$(BLACK_FG)$(GREEN_BG)                                                $(DEFAULT)\n" 
	g++ -c $(SOURCES)  -Wall -Werror -Wextra -std=c++17
	@$(CC) *.o model/model_test.cpp -o test $(WILD) $(CC_FLAGS) $(LGTEST_FLAGS) -g
	@./test

gcov_report: clean
	@echo "$(BLACK_FG)$(CYAN_BG)                                                $(DEFAULT)"
	@echo "$(BLACK_FG)$(CYAN_BG)               CREATE REPORT                    $(DEFAULT)"
	@echo "$(BLACK_FG)$(CYAN_BG)                                                $(DEFAULT)\n" 
	g++ -c $(SOURCES) $(GCOV_FLAGS) $(CC_FLAGS)
	@$(CC) $(CC_FLAGS) *.o */*_test.cpp $(LGTEST_FLAGS) $(GCOV_FLAGS) -o info
	@./info
	@lcov -t "info" -o gcovreport.info -c -d .
	@lcov --remove gcovreport.info '/usr/*' '*test*' --output-file gcovreport.info
	@genhtml -o report gcovreport.info
	@$(OPEN) report/index.html
	@echo "$(BLACK_FG)$(CYAN_BG)                                                $(DEFAULT)"
	@echo "$(BLACK_FG)$(CYAN_BG)               COMPLETE                         $(DEFAULT)"
	@echo "$(BLACK_FG)$(CYAN_BG)                                                $(DEFAULT)\n" 

style:
	clang-format -style=google -i */*.cc
	clang-format -style=google -i */*.h
	clang-format -style=google -i */*.cpp

clean:
	@rm -rf *.o *.gcda *.gcno *.info
	@rm -rf docs
	@rm -rf build
	@rm -rf html
	@rm -rf latex
	@rm -f info
	@rm -f *.a
	@rm -f *.gz
	@rm -f *.out
	@rm -rf report
	@rm -f test
	@rm -rf *.dSYM
	@echo "$(BLACK_FG)$(CYAN_BG)                                                $(DEFAULT)"
	@echo "$(BLACK_FG)$(CYAN_BG)               CLEAN DONE                       $(DEFAULT)"
	@echo "$(BLACK_FG)$(CYAN_BG)                                                $(DEFAULT)\n" 

.PHONY: git
git: style clean
	rm -rf report
	git add .
	git commit -m "commit"
	git push

dvi: clean
	@mkdir -p docs
	@doxygen Doxyfile
	@mv html latex docs
	@open docs/html/index.html
	@echo "$(BLACK_FG)$(PURPLE_BG)                                                $(DEFAULT)"
	@echo "$(BLACK_FG)$(PURPLE_BG)               CREATE DOXY                      $(DEFAULT)"
	@echo "$(BLACK_FG)$(PURPLE_BG)                                                $(DEFAULT)\n" 

dist:
	mkdir $(PACKAGE)
	cp -r ./controller $(PACKAGE)
	cp -r ./icon $(PACKAGE)
	cp -r ./model $(PACKAGE)
	cp -r ./view $(PACKAGE)
	cp Makefile $(PACKAGE)
	tar -czf $(PACKAGE).tar.gz $(PACKAGE)
	rm -rf $(PACKAGE)

valgrind:
	valgrind --tool=memcheck --leak-check=full --track-origins=yes --show-reachable=yes --num-callers=20 --track-fds=yes ./test
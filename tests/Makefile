NAME = test

LIB= ../lib/liblinal.a

INCLUDE_DIR = ../includes

CXX = g++

CXXFLAGS = -g -I$(INCLUDE_DIR) -I. -std=c++20

LDFLAGS =  -llinal -L../lib/

SRCS = tests.cpp testVector.cpp testMatrix.cpp test00.cpp test01.cpp test02.cpp test03.cpp test04.cpp

$(NAME): $(SRCS) $(LIB)
	@ make -s -C ../
	@ echo "\033[33mCompiling tests\033[m"
	@ $(CXX) $(SRCS) $(CXXFLAGS) -o $(NAME) $(LDFLAGS)
	@ echo " \033[32m Tests compiled\033[m"

run:
	@ ./test

all: $(NAME)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY: clean fclean

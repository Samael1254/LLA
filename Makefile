NAME = lib/liblinal.a

SRCS_DIR = src

BUILD_DIR = build

INCLUDES_DIR = includes

SRCS = Complex.cpp projection.cpp

SRCS := $(addprefix $(SRCS_DIR)/, $(SRCS))

OBJS = $(addprefix build/, $(notdir $(SRCS:.cpp=.o)))

INCLUDES = Vector.hpp Vector.ipp

INCLUDES := $(addprefix $(INCLUDES_DIR)/, $(INCLUDES))

DEP=$(OBJS:.o=.d)

CXX = g++

CXXFLAGS = -Wall -Werror -Wextra -I$(INCLUDES_DIR) -std=c++20

$(NAME): $(OBJS)
	@ mkdir -p lib
	@ ar crs $@ $(OBJS)
	@ echo " \033[32m \033[1mliblinal.a\033[0;32m compiled in \033[1mlib/\033[m"

$(BUILD_DIR)/%.o: $(SRCS_DIR)/%.cpp
	@ echo " \033[33m  Compiling $(notdir $@)...\033[m"
	@ mkdir -p build
	@ $(CXX) $(CXXFLAGS) -c $< -o $@
	@ tput cuu1 && tput el

all: $(NAME)

clean:
	@ echo " \033[33mCleaning\033[m"
	@ rm -f $(OBJS) $(DEP)
	@ rm -df $(BUILD_DIR)
	@ echo " \033[32m Object files cleaned\033[m"

fclean: clean
	@ rm -f $(NAME)
	@ rm -df lib
	@ echo " \033[1;32m liblinal.a\033[0;32m cleaned\033[m"

re: fclean all

test: all
	@ make -s -C tests
	@ make run -s -C tests

.PHONY : clean fclean re all test
-include $(DEP)

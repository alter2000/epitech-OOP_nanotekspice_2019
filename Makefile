##
## EPITECH PROJECT, 2019
## cpp_rush3_2019
## File description:
## automated desc ftw
##

SRC = $(shell find . -name "*.cpp")

DFLAGS = \
		 -fsanitize=address \
		 -fsanitize=alignment \
		 -fsanitize=enum \
		 -fsanitize=undefined \
		 -g

		 # -fsanitize=nullability \

DPL = clang++

NAME = nanotekspice
CPL = g++
CFLAGS = -Wextra -Wall --std=c++11 -g

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CPL) -o $(NAME) $(OBJ) $(shell find . -name '*.hpp') $(LDFLAGS)

debug: $(SRC)
	$(CPL) -o $(NAME) $(SRC) $(shell find . -name '*.hpp') $(DFLAGS) $(LDFLAGS)

clean:
	find . -name 'vgcore.*' -delete
	find . -name '*.gc*' -delete
	find . -name '*.o' -delete

fclean: clean
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

%.o: %.cpp
	$(CPL) $(CFLAGS) -o $@ -c $<

.PHONY: all clean fclean re

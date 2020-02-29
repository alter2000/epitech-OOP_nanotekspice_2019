##
## EPITECH PROJECT, 2019
## cpp_rush3_2019
## File description:
## automated desc ftw
##

SRC = $(shell find . -type f -name "*.cpp")

DFLAGS = \
		 -fsanitize=address \
		 -fsanitize=alignment \
		 -fsanitize=enum \
		 -fsanitize=undefined \
		 -fsanitize=nullability
DPL = clang++

NAME = nanotekspice
CPL = g++
CFLAGS = -Wextra -Wall --std=c++11

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CPL) -o $(NAME) $(OBJ) $(LDFLAGS)

debug: $(SRC)
	$(CPL) -o $(NAME) $(SRC) $(LDFLAGS)

clean:
	$(foreach var, $(OBJ), if [ -e $(var) ] ; then rm -f $(var) ; fi;)
	rm -f vgcore.*

fclean: clean
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

%.o: %.c
	$(CPL) $(CFLAGS) -o $@ -c $<

.PHONY: all clean fclean re

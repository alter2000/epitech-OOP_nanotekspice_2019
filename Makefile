##
## EPITECH PROJECT, 2019
## cpp_rush3_2019
## File description:
## automated desc ftw
##

SRC = $(shell find . -name "*.cpp")

DFLAGS=-Wall -Wextra --std=c++11 -g -ggdb3
		 # -fsanitize=address \
		 # -fsanitize=alignment \
		 # -fsanitize=enum \
		 # -fsanitize=undefined \

		 # -fsanitize=nullability \

DPL = g++

NAME = nanotekspice
CPL = g++
CFLAGS = -Wextra -Wall --std=c++11 -g -rdynamic

DOBJ=$(SRC:.cpp=-d.o)
OBJ=$(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CPL) -o $(NAME) $(OBJ) $(shell find . -name '*.hpp') $(LDFLAGS)

debug: $(SRC)
	$(DPL) -o $(NAME) $(DOBJ) $(shell find . -name '*.hpp') $(LDFLAGS)

clean:
	find . -name 'vgcore.*' -delete
	find . -name '*.gc*' -delete
	find . -name '*.o' -delete

fclean: clean
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

%.d.o: %.cpp
	$(DPL) $(DFLAGS) -o $@ -c $<

%.o: %.cpp
	$(CPL) $(CFLAGS) -o $@ -c $<

.PHONY: all clean fclean re

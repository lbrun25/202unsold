##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC = src/Parser.cpp	\
	  src/Unsold.cpp	\
	  src/main.cpp


NAME = 202unsold

CXXFLAGS += -std=c++11
CXXFLAGS +=	-W -Wall -Wextra
CXXFLAGS +=	-I./include/

RM = rm -f

OBJ = $(SRC:.cpp=.o)

CC = g++

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(CFLAGS) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re⏎

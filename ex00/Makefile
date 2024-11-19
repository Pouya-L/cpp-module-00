# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/13 14:11:07 by plashkar          #+#    #+#              #
#    Updated: 2024/11/19 13:17:46 by plashkar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

CC = c++

STANDARD_FLAGS = -Wall -Werror -Wextra -std=c++98 -g

SRC = \
	megaphone.cpp

OBJ = $(SRC:.cpp=.o)

%.o: %.cpp
	@$(CC) $(STANDARD_FLAGS) -o $@ -c $<

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Compiling $@"
	@$(CC) $(STANDARD_FLAGS) $(OBJ) -o $(NAME) > /dev/null
	@echo "megaphone has been created."

clean:
	@rm -f $(OBJ)
	@echo Object files have been deleted.

fclean: clean
	@rm -f $(NAME)
	@echo All created files have been deleted.

re: fclean all

v: all clean
	@echo

.PHONY: fclean clean all re

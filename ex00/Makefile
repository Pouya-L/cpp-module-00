# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plashkar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/13 14:11:07 by plashkar          #+#    #+#              #
#    Updated: 2024/06/07 13:14:21 by plashkar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

CC = c++

STANDARD_FLAGS = -Wall -Werror -Wextra -std=c++98 -g

philo_LIB = philo.a

SRC = \
	megaphone.cpp

OBJ = $(SRC:.c=.o)

%.o: %.c
	@$(CC) $(STANDARD_FLAGS) -o $@ -c $<

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Compiling $@"
	@$(CC) $(STANDARD_FLAGS) $(OBJ) -o $(NAME) > /dev/null
	@echo "megaphone has been created."

clean:
	@rm -f src/*.o
	@echo Object files have been deleted.

fclean: clean
	@rm -f $(philo_LIB)
	@rm -f $(NAME)
	@echo All created files have been deleted.

re: fclean all

v: all clean

.PHONY: fclean clean all re

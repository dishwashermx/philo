# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/29 13:55:58 by ghwa              #+#    #+#              #
#    Updated: 2024/02/02 17:05:49 by ghwa             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
FILES = main.c cleanup.c initall.c routine.c
SRC = $(addprefix src/, $(FILES))
OBJ = $(SRC:%.c=%.o)
FLAGS = -Werror -Wextra -Wall -ggdb -g3 -pthread -fsanitize=address 
CC = cc

all: $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -I . -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f src/*.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
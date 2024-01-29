# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/29 13:55:58 by ghwa              #+#    #+#              #
#    Updated: 2024/01/29 14:38:54 by ghwa             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
FILES = philo.c
SRC = $(addprefix src\, $(FILES))
OBJ = $(SRC: .c=.o)
FLAGS = -Werror -Wextra -Wall -ggdb -g3 -fsanitize=address
CC = cc
LIBFT = (../libft/libft.a)

all: $(NAME)

libft: $(LIBFT)

$(LIBFT):
	@make -C ${LIBFT} re

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -I . -o $(NAME) $(LIBFT)
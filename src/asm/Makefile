# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybitton <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/21 15:49:01 by ybitton           #+#    #+#              #
#    Updated: 2017/12/21 15:49:43 by unli-yaw         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC =		gcc

NAME =		asm

CFLAGS =	-Wall -Werror -Wextra

SRC =		list.c main.c launch.c scan.c create.c ft_strsplit2.c set_data.c error.c error2.c parse.c parser.c print.c macro.c macro2.c macro3.c \

OBJ =		$(SRC:.c=.o)

all:		$(NAME)

$(NAME):
			@$(CC) $(CFLAGS) -I ../../libft -c $(SRC)
			@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L ../../libft -lft
			@echo "\033[0;36mCompilation of ASM is done !\033[0;m"


clean:
			@rm -rf $(OBJ)

fclean:		clean
			@rm -rf $(NAME)
			@echo "\033[0;32mAll is cleaned !\033[0;m"

re:			fclean all

.PHONY: all, re, fclean, clean

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybitton <ybitton@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/24 14:20:47 by ybitton           #+#    #+#              #
#    Updated: 2017/12/21 15:07:05 by ybitton          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAGS = -g -Wall -Wextra -Werror
CC = gcc
OBJ = ft_abs.o ft_putchar.o ft_putstr.o ft_strlen.o ft_strdup.o ft_strsdup.o ft_memalloc.o ft_memdel.o ft_strnew.o ft_strdel.o ft_strclr.o ft_striter.o ft_striteri.o ft_strmap.o ft_strmapi.o ft_strequ.o ft_strnequ.o ft_strsub.o ft_strjoin.o ft_strjoin_free.o ft_strtrim.o ft_strsplit.o ft_itoa.o ft_putendl.o ft_putnbr.o ft_putchar_fd.o ft_putstr_fd.o ft_putstr_spec.o ft_putendl_fd.o ft_putnbr_fd.o ft_putnbr_endl.o ft_memset.o ft_bzero.o ft_memcpy.o ft_memccpy.o ft_memmove.o ft_memchr.o ft_endianness.o ft_tostr.o ft_memcmp.o ft_strcpy.o ft_strncpy.o ft_strcat.o ft_strncat.o ft_strlcat.o ft_strchr.o ft_strrchr.o ft_strstr.o ft_strnstr.o ft_strcmp.o ft_strncmp.o ft_atoi.o ft_isalpha.o ft_isdigit.o ft_isalnum.o ft_isascii.o ft_isprint.o ft_toupper.o ft_tolower.o ft_lstnew.o ft_lstdelone.o ft_lstdel.o ft_lstadd.o ft_lstiter.o ft_lstmap.o ft_capitalize.o ft_countwords.o ft_strndup.o ft_itoamax.o ft_printf.o ft_printf_base.o ft_printf_flags.o ft_printf_get.o ft_printf_init.o ft_printf_ldtoa.o ft_printf_list.o ft_printf_norm.o ft_printf_norm1.o ft_printf_pars.o ft_printf_preci.o ft_printf_resol_bonus.o ft_printf_resol_easy.o ft_printf_resol_ld.o ft_printf_resol_nb.o ft_printf_wspe.o ft_printf_color.o ft_wordtotab.o get_next_line.o ft_strcute.o ft_isspace.o ft_strisspace.o ft_strisalpha.o ft_strisnumeric.o

all: $(NAME)

%.o: %.c
	@$(CC) $(FLAGS) -c -o $@ $<

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\033[0;35m"Libft compilated !"\033[0;m"

clean:
	@/bin/rm -f *.o

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean fclean reaa

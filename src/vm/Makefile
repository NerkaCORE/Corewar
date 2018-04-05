# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: unli-yaw <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/21 15:48:25 by unli-yaw          #+#    #+#              #
#    Updated: 2017/12/21 15:48:29 by unli-yaw         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corewar

FLAGS = -Wall -Werror -Wextra

vpath %.c ./ ./Instructions/

SRC = corewar.c \
	parsing.c \
	end.c \
	init_data.c \
	create_list.c \
	display.c \
	tools.c \
	tools_2.c \
	tools_3.c \
	display_infos_box.c \
	turn_by_slowmode.c \
	add_and_sub.c \
	and_or_xor.c \
	direct_value.c \
	fork_lfork_aff.c \
	indirect_value.c \
	instruction.c \
	instruction_2.c \
	ld_ldi.c \
	live_zjump.c \
	lld_lldi.c \
	parameters.c \
	parameters_2.c \
	st_sti.c \
	exit.c

OBJS	= $(SRC:.c=.o)
O2		= $(addprefix $(OPATH), $(OBJS))
LIBFT	= ../../libft/
OPATH	= ../../obj/vm/
INC		= ../../include/vm/
LINC	= ../../include/libft/printf/
LIBINC	= $(LIBFT)$(LINC)
LIB		= $(LIBFT)libft.a

all: $(NAME)

$(NAME): $(O2)
	@gcc $(FLAGS) $(O2) -L$(LIBFT) -lncurses -lft -I$(INC) -o $@
	@echo "\033[0;31m"Corewar generated !"\033[0;m"

$(OPATH)%.o: %.c
	@gcc $(FLAGS) -I $(INC) -I $(LIBINC) -o $@ -c $<

clean:
	@rm -f $(O2)

fclean: clean
	@rm -f $(NAME)
	@echo "\033[0;32m"Executable deleted !"\033[0;m"
	@make fclean -C $(LIBFT)

re: fclean all

.PHONY : all, clean, fclean, re

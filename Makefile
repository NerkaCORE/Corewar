# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: unli-yaw <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/21 15:48:14 by unli-yaw          #+#    #+#              #
#    Updated: 2018/02/10 15:59:33 by gduval           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SUB_MAKEFILES = libft \
				src/asm \
				src/vm \

all:
	@mkdir -p obj/vm
	@make -C libft all
	@make -C src/asm all
	@make -C src/vm all

libft.a:
	@make -C libft all

asm:
	@make -C src/asm all

corewar:
	@make -C src/vm all

clean:
	@-for i in $(SUB_MAKEFILES) ; do \
		make -C $$i clean; \
	done
	@rmdir obj 2> /dev/null || true

fclean: clean
	@for i in $(SUB_MAKEFILES) ; do \
		make -C $$i fclean; \
	done
	@rm -rf obj/vm obj

re: fclean all

.PHONY: all clean fclean re

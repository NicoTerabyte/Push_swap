# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/19 10:44:57 by lnicoter          #+#    #+#              #
#    Updated: 2023/05/22 20:08:11 by lnicoter         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS += --silent
NAME = push_swap

SRC		=	init.c checks.c push_swap_utils.c push_swap.c \
			push.c swap.c rotate.c reverse_rotate.c quick_sort.c\

LIBFT	=	libft/libft.a

OBJ		=	$(SRC:.c=.o)

CC		=	gcc -g

RM		=	rm -f

FLAGS	=	-Wall -Wextra -Werror

$(NAME):	$(OBJ)
			make -C ./libft
			$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)
	@echo "\033[32mCompiled OK!\033[0m"
all:		$(NAME)

clean:
			make clean -C libft
			${RM} $(OBJ)
	@echo "\033[33mclean OK!\033[0m"
fclean: 	clean
			make fclean -C libft
			${RM} $(NAME) $(NAME_BONUS) ${OBJ}

re:			fclean all

.PHONY:		all clean fclean re







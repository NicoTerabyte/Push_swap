# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/19 10:44:57 by lnicoter          #+#    #+#              #
#    Updated: 2023/04/26 00:28:34 by lnicoter         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC		=	big_sort.c checks.c five_sort.c ft_error.c list_utils.c \
			movesone.c movesthree.c movestwo.c push_swap.c three_sort.c \
			list_utils2.c prova.c\

LIBFT	=	libft/libft.a

OBJ		=	$(SRC:.c=.o)

CC		=	gcc

RM		=	rm -f

FLAGS	=	-Wall -Wextra -Werror

$(NAME):	$(OBJ)
			make -C ./libft
			$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)

all:		$(NAME)

clean:
			make clean -C libft
			${RM} $(OBJ)

fclean: 	clean
			make fclean -C libft
			${RM} $(NAME) $(NAME_BONUS) ${OBJ}

re:			fclean all

.PHONY:		all clean fclean re




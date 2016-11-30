# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/03 14:41:23 by cfrouin           #+#    #+#              #
#    Updated: 2016/11/30 17:19:28 by jdebladi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC			=		srcs/main.c \
					srcs/tet_list.c \
					srcs/file.c \
					srcs/check_tetriminos.c \
					srcs/resolve.c \
					srcs/resolve_map.c \
					srcs/ft_puttab.c

NAME		=		fillit

OBJ			=		$(SRC:.c=.o)

CFLAGS		=		-Wextra -Wall -Werror -Iincludes

all:				$(NAME)

%.o: %.c
	@gcc -g -o $@ -c $< $(CFLAGS)

$(NAME):			$(OBJ)
					@gcc -Llibs -lft -o $(NAME) $(OBJ)
					@echo "\033[32mCan you feel it\033[0m"

clean:
					@rm -f $(OBJ)

nclean:				all clean

fclean:				clean
					@rm -f $(NAME)

re:					fclean all

.PHONY:				all clean fclean nclean re

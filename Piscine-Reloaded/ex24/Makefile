# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdebladi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/04 15:04:18 by jdebladi          #+#    #+#              #
#    Updated: 2016/11/04 15:17:40 by jdebladi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
LIB = ar rc
INC_DIR = ./includes/
SRC_DIR = ./srcs
CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR)
NAME = Libft.a
SRC =	$(SRC_DIR)/ft_putchar.c \
		$(SRC_DIR)/ft_putstr.c \
		$(SRC_DIR)/ft_strcmp.c \
		$(SRC_DIR)/ft_strlen.c \
		$(SRC_DIR)/ft_swap.c
OBJ = $(SRC:.c=.o)

.PHONY : clean fclean re all

all: $(NAME)

$(NAME): $(OBJ)
	@$(LIB) $(NAME) $(SRC)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all


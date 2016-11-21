# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdebladi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/04 15:30:14 by jdebladi          #+#    #+#              #
#    Updated: 2016/11/04 16:14:44 by jdebladi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = ft_display_file
SRC = ft_display.c
OBJ = $(SRC:.c=.o)

.PHONY : clean fclean re all

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) -o $(NAME) $(SRC)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

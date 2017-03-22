# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/03 14:41:23 by cfrouin           #+#    #+#              #
#    Updated: 2017/03/20 14:29:58 by jdebladi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = srcs/main.c \
	srcs/tet_list.c \
	srcs/file.c \
	srcs/check_tetriminos.c \
	srcs/resolve.c \
	srcs/resolve_map.c \
	srcs/ft_puttab.c

NAME = fillit

OBJ = $(SRC:.c=.o)

CFLAGS = -Wextra -Wall -Werror -Iincludes

all: $(NAME)

%.o: %.c
	@gcc -g -o $@ -c $< $(CFLAGS)
	@echo "\033[K\033[34mLibft :\033[0m [ Compiling :\033[33m $^\033[0m]\033[1A"

$(NAME): $(OBJ)
	@cd libs && $(MAKE)
	@gcc -Llibs -lft -o $(NAME) $(OBJ)
	@echo "\033[K   \033[32;42m..\033[0m \033[31;41m..\033[0m"
	@echo "\033[38;44m.\033[0m \033[32;42m..\033[0m   \033[31;41m..\033[0m "
	@echo "\033[38;46m.\033[0m \033[35mCan\033[0m"
	@echo "\033[38;43m.\033[0;0m \033[91myou\033[0m  \033[33;43m..\033[0m"
	@echo "\033[38;46m.\033[0m \033[31mfeel\033[0m \033[33;43m..\033[0m"
	@echo "  \033[34mit\033[0m "
	@echo "\033[91;101m.\033[0m       \033[34;44m.\033[0m"
	@echo "\033[91;101m.\033[0m   \033[35;45m.\033[0m   \033[34;44m.\033[0m"
	@echo "\033[91;101m..\033[0m \033[35;45m...\033[0m \033[34;44m..\033[0m"

clean:
	@cd libs && $(MAKE) clean
	@rm -f $(OBJ)

nclean: all clean

fclean: clean
	@cd libs && $(MAKE) fclean
	@rm -f $(NAME)
	@echo "\033[K\033[31m============================\033[0m"
	@echo "\033[31mRemoval\033[00m" [ "Fillit" ] " \033[32mComplete\033[00m"
	@echo "\033[K\033[31m============================\033[0m"

re: fclean all

.PHONY: all clean fclean nclean re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/26 15:29:45 by jdebladi          #+#    #+#              #
#    Updated: 2017/04/23 15:19:09 by jdebladi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = jdebladi.filler

SRC = srcs/filler.c srcs/search.c srcs/display.c srcs/main.c srcs/block.c

OBJ = $(SRC:.c=.o)

INCL = -Iincludes/filler.h

LIBS = -Llibft -lftprintf

CFLAGS = -Wall -Wextra -Werror

%o: %c
	@gcc -g -o $@ -c $< $(CFLAGS) $(INCL)
	@echo "\033[K\x1B[34mCompiling\x1B[00m : \x1B[32m$^\x1B[00m"

$(NAME): $(OBJ)
	@cd libft && make
	@gcc $(LIBS) -g -o $(NAME) $(OBJ)
	@echo "\x1B[K\x1B[32m$(NAME)\x1B[00m : \x1B[34mCreated\x1B[00m"
	@cp -f $(NAME) players/

all: $(NAME)

clean:
	@cd libft && make clean
	@rm -f $(OBJ)
	@echo "\x1B[31mClean\x1B[01m Done\x1B[00m"

fclean: clean
	@rm -f libft/libftprintf.a
	@rm -f players/$(NAME) $(NAME)
	@echo "\x1B[31mFclean\x1B[01m Done\x1B[00m"

mclean: all clean
	@echo "\x1B[K\x1B[33mMake && clean \x1B[01mDone\x1B[0m"

re: fclean all
	@echo "\x1B[32mRe\x1B[01m Done\x1B[0m"

.PHONY: all clean fclean mclean re

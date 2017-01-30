# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/09 13:29:45 by jdebladi          #+#    #+#              #
#    Updated: 2017/01/30 11:28:20 by jdebladi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = srcs/main.c

OBJS = $(SRCS:.c=.o)

INCL = includes/

CFLAGS = -Werror -Wextra -Wall -I$(INCL)

NAME = ft_printf

all: $(NAME)

%.o: %.c
	@echo "\033[K\033[34mLibft :\033[0m [ Compiling :\033[33m $^\033[0m]\033[1A"
	@gcc -g -o $@ -c $< $(CFLAGS)

$(NAME): $(OBJS)
	@cd libft && make
	@gcc -g -o $(NAME) $(OBJS) $(CFLAGS) -Llibft -lft
	@echo "\033[34mCompiling\033[0m" [ $(NAME) ] "\033[K\033[32mSuccessful\033[0m"

clean:
	@cd libft && make clean
	@/bin/rm -f $(OBJS)
	@echo "\033[31mRemoval\033[0m  " [ "fdf/*.o" ] "  \033[32mComplete\033[0m"

fclean: clean
	@cd libft && make fclean
	@/bin/rm -f $(NAME)
	@echo "\033[31mRemoval\033[0m" [ $(NAME) ] "\033[32mComplete\033[0m"

re: fclean all
	@echo "\033[32m*** Let's start anew ***\033[00m"

.PHONY : all clean fclean re

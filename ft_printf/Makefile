# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/09 13:29:45 by jdebladi          #+#    #+#              #
#    Updated: 2017/02/13 14:51:51 by jdebladi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c \
	handlers/printi.c \
	handlers/printl.c \
	handlers/printll.c \
	handlers/prints.c \
	handlers/printls.c \
	handlers/utf8_convert.c \
	Libft/ft_putchar.c

OBJS = $(SRCS:.c=.o)

INCL = includes/

CFLAGS = -Werror -Wextra -Wall -I$(INCL)

NAME = libftprintf.a

all: $(NAME)

%.o: %.c
	@echo "\033[K\033[34mLibft :\033[0m [ Compiling :\033[33m $^\033[0m]\033[1A"
	@gcc -g -o $@ -c $< $(CFLAGS)
	
$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@echo "\033[34mCompiling\033[0m" [ $(NAME) ] "\033[K\033[32mSuccessful\033[0m"

clean:
	@cd Libft && make clean
	@/bin/rm -f $(OBJS)
	@echo "\033[31mRemoval\033[0m  " [ "ft_printf/*.o" ] "  \033[32mComplete\033[0m"

mclean: all clean
	@echo "\033[K\033[32mMake && cleaned\033[00m"

fclean: clean
	@cd Libft && make fclean
	@/bin/rm -f $(NAME)
	@echo "\033[31mRemoval\033[0m" [ $(NAME) ] "\033[32mComplete\033[0m"

re: fclean all
	@echo "\033[K\033[32m*** Let's start anew ***\033[00m"

.PHONY : all clean fclean re

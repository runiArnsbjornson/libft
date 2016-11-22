CC = gcc
SRCS =	bsq.c \
				check_map.c \
				ft_atoi.c \
				ft_display.c \
				ft_putchar.c \
				ft_resolve.c \
				ft_str_nb_line.c \
				ft_strcut.c \
				ft_strdup.c \
				ft_strlen.c \
				ft_split_whitespaces.c
OBJS = $(SRCS:.c=.o)
INCL = bsq.h
NAME = bsq
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) :
	@$(CC) -c $(SRCS)
	@$(CC) -o $(NAME) $(OBJS) -I $(INCL)
	@echo "et hop"

clean :
	@rm -f $(OBJS)

fclean : clean
	@rm -f $(NAME)
	@echo "hop on efface"

re : fclean all
	@echo "et on recommence"

.PHONY : all clean fclean re

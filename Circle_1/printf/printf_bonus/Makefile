CC			= cc

CFLAGS		= -Wall -Wextra -Werror

HEADER 		= ft_printf.h

SRCS 		= ft_printf.c ft_print_str.c ft_print_nbr.c ft_print_ptr.c ft_print_flag.c ft_utils.c


OBJS 		= $(SRCS:c=o)

NAME		= libftprintf.a

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER)

$(NAME): $(OBJS)
	ar rcs $@ $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re:
	make fclean
	make all

bonus : all

.PHONY: all clean fclean re bonus

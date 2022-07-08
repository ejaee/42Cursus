CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
NAME = libft.a
HEADER = libft.h

SRCS = \
ft_atoi.c ft_bzero.c ft_calloc.c ft_itoa.c ft_split.c ft_tolower.c ft_toupper.c \
ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c

SRCS_B = \
ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c \
ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c

OBJS = $(SRCS:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)

ifdef ADD_BONUS
		OBJECTS = $(OBJS) $(OBJS_B)
else
		OBJECTS = $(OBJS)
endif

%o : %c
		$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER)

$(NAME) : $(OBJECTS)
		ar rcs $(NAME) $(OBJECTS)

bonus :
		make ADD_BONUS=1 all

all : $(NAME)

clean :
		$(RM) $(OBJS) $(OBJS_B)

fclean : clean
		$(RM) $(NAME)
re :	fclean all

.PHONY : all clean fclean re bonus

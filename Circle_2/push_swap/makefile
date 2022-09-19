# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ejachoi <ejachoi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/02 10:44:21 by ejachoi           #+#    #+#              #
#    Updated: 2022/09/05 20:14:28 by ejachoi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra

OBJS = \
push_swap.c doubly_linked_list.c  \
operations_1.c operations_2.c operations_3.c \
sort.c sort_sandglass.c \
validate_param.c ft_split.c\

OBJS_CHECKER = \
check_op.c checker.c doubly_linked_list.c \
operations_1.c operations_2.c operations_3.c \
get_next_line.c get_next_line_utils.c \
validate_param.c ft_split.c\

SRCS = $(addprefix mandatory/, $(OBJS))
SRCS_BONUS = $(addprefix bonus/, $(OBJS_CHECKER))
SRCS_FILES = $(SRCS:c=o)
SRCS_BONUS_FILES = $(SRCS_BONUS:c=o)

MAND_DIR = mandatory
BONUS_DIR = bonus

NAME = push_swap
BONUS = checker
RM = rm -rf

%.o : %c
	$(CC) $(CFLAGS) -c $< -I.

$(NAME) : $(SRCS_FILES)
	$(CC) $(CFLAGS) -o $@ $^

$(BONUS) : $(SRCS_BONUS_FILES)
	$(CC) $(CFLAGS) -o $@ $^

all : $(NAME)

bonus : $(BONUS)

clean :
	$(RM) $(SRCS_FILES)
	$(RM) $(SRCS_BONUS_FILES)

fclean : clean
	$(RM) $(NAME)
	$(RM) $(BONUS)

re :
	make fclean
	make all

.PHONY: all clean fclean re bonus

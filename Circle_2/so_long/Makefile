# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ejachoi <ejachoi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/01 13:13:46 by chanwjeo          #+#    #+#              #
#    Updated: 2022/12/26 17:48:05 by ejachoi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long
NAME_BONUS	=	so_long_bonus

CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra
RM			=	rm -rf
MLX			=	-L./mlx -lmlx -framework OpenGL -framework AppKit

INCS_DIR	= ./include/
SRCS_DIR	= ./src/
LIB_DIR		= ./libft/
FUNC_DIR	= ./gnl/
MLX_DIR		= ./mlx/

INCS_BONUS_DIR	= ./include_bonus/
SRCS_BONUS_DIR	= ./src_bonus/

LIB_NAME	=	./libft/libft.a
INCS		=	-I include

SRC			=	reflect_key.c check_file.c init_game.c \
				init_img.c main.c parse_map.c press_key.c \
				put_img.c put_object.c read_file.c utils.c

SRC_BONUS	=	reflect_key_bonus.c check_file_bonus.c init_game_bonus.c \
				init_img_bonus.c main_bonus.c parse_map_bonus.c press_key_bonus.c \
				put_img_bonus.c put_object_bonus.c read_file_bonus.c utils_bonus.c

LIBS		=	$(addprefix $(LIB_DIR), $(LIB_NAME))
SRCS		=	$(addprefix $(SRCS_DIR), $(SRC))
OBJS		=	$(SRCS:.c=.o)

SRCS_BONUS		=	$(addprefix $(SRCS_BONUS_DIR), $(SRC_BONUS))
OBJS_BONUS		=	$(SRCS_BONUS:.c=.o)

FUNC 		=	gnl/gnl.c
OBJS_F		=	$(FUNC:.c=.o)

.c.o :
	$(CC) $(CFLAGS) -I $(INCS_DIR) -o $@ -c $?

$(NAME) : $(OBJS) $(OBJS_F)
	make -C $(LIB_DIR)
	make -C $(MLX_DIR)
	$(CC) -o $(NAME) $(OBJS) $(OBJS_F) -L $(LIB_DIR) -lft -I $(INCS_DIR) $(MLX)

all:			$(NAME)

clean:
	make -C $(LIB_DIR) clean
	make -C $(MLX_DIR) clean
	$(RM) $(OBJS) $(OBJS_F) $(OBJS_BONUS)

fclean: clean
	make -C $(LIB_DIR) fclean
	$(RM) $(NAME) $(NAME_BONUS)

bonus: $(NAME_BONUS)

$(NAME_BONUS) : $(OBJS_BONUS) $(OBJS_F)
	make -C $(LIB_DIR)
	make -C $(MLX_DIR)
	$(CC) -o $(NAME_BONUS) $(OBJS_BONUS) $(OBJS_F) -L $(LIB_DIR) -lft -I $(INCS_BONUS_DIR) $(MLX)

re: fclean all

.PHONY:		all clean fclean bonus re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lchuang <lchuang@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/16 11:11:56 by lchuang           #+#    #+#              #
#    Updated: 2025/06/17 15:34:15 by lchuang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src
SRCS = 	main.c \
		parse_map.c \

OBJ_DIR		=	objs
OBJ 		=	$(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))

UNAME := $(shell uname)

ifeq ($(UNAME), Darwin)
MLX_DIR = mlx/minilibx_opengl_20191021
else
MLX_DIR = mlx/minilibx_mms_20200219
endif

MLX_INC = -I$(MLX_DIR)

ifeq ($(UNAME), Darwin)
MLX_LIB = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
else
MLX_LIB = -L$(MLX_DIR) -lmlx -lXext -lX11
endif

CFLAGS += $(MLX_INC)
LDFLAGS += $(MLX_LIB)

all: $(NAME)

$(NAME): $(OBJ) $(MLX_DIR)/libmlx.a
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(MLX_DIR)/libmlx.a:
	@$(MAKE) -C $(MLX_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

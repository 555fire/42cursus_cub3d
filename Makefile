# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lchuang <lchuang@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/16 11:11:56 by lchuang           #+#    #+#              #
#    Updated: 2025/06/16 13:57:01 by lchuang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src
SRC = $(SRC_DIR)/main.c
OBJ = $(SRC:.c=.o)

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

$(MLX_DIR)/libmlx.a:
	@$(MAKE) -C $(MLX_DIR)

$(NAME): $(MLX_DIR)/libmlx.a $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLX_LIB) -o $(NAME) $(MLX_FLAGS)

clean:
	rm -f $(OBJ)
	@$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)

re: fclean all

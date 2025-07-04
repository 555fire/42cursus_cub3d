# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lchuang <lchuang@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/16 11:11:56 by lchuang           #+#    #+#              #
#    Updated: 2025/07/04 18:34:06 by lchuang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src
SRCS = 	main.c \
		player.c \
		game_utils.c \
		raycast/ray_algo.c \
		raycast/ray_render.c \
		raycast/raycast.c \
		map/map.c \
		map/map_load.c \
		map/map_header.c \
		map/map_parser.c \
		map/map_validate.c \
		map/utils.c \

OBJ_DIR		=	objs
OBJ		=	$(SRCS:.c=.o)
OBJ		:=	$(addprefix $(OBJ_DIR)/, $(OBJ))

LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_INC = -I$(LIBFT_DIR)
LIBFT_LIB = -L$(LIBFT_DIR) -lft

UNAME := $(shell uname)

ifeq ($(UNAME), Darwin)
MLX_DIR = mlx/minilibx_opengl_20191021
else
MLX_DIR = mlx/minilibx_mms_20200219
endif

MLX_INC = -I$(MLX_DIR)

ifeq ($(UNAME), Darwin)
MLX_LIB = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit -lm
else
MLX_LIB = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
endif

CFLAGS += $(MLX_INC)
LDFLAGS += $(MLX_LIB)

all: $(NAME)

$(NAME): $(OBJ) $(MLX_DIR)/libmlx.a  $(LIBFT)
	$(CC) $(CFLAGS) $(LIBFT_LIB) -o $(NAME) $(OBJ) $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(LIBFT_INC) -c $< -o $@

$(MLX_DIR)/libmlx.a:
	@$(MAKE) -C $(MLX_DIR)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(MLX_DIR) clean
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(MLX_DIR) clean
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re

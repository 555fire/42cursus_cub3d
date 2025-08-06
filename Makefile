# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mamiyaza <mamiyaza@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/16 11:11:56 by lchuang           #+#    #+#              #
#    Updated: 2025/08/06 12:36:58 by mamiyaza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes

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


# libft
# LIBFT_DIR = libft/
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_INC = -I$(LIBFT_DIR)
LIBFT_LIB = -L$(LIBFT_DIR) -lft



# MiniLibX
MLX = $(MLX_DIR)/libmlx.a

MLX_ZIP_DIR = mlx
UNAME := $(shell uname)

ifeq ($(UNAME), Darwin)
MLX_ZIP = $(MLX_ZIP_DIR)/minilibx_macos_metal.tgz
else
MLX_ZIP = $(MLX_ZIP_DIR)/minilibx-linux.tgz
endif
# ifeq ($(UNAME), Darwin)
# MLX_ZIP = mlx/minilibx_macos_metal.tgz
# else
# MLX_ZIP = mlx/minilibx-linux.tgz
# endif

ifeq ($(UNAME), Darwin)
# MLX_DIR = mlx/minilibx_opengl_20191021
MLX_DIR = minilibx_mms_20200219
else
MLX_DIR = minilibx-linux
endif

MLX_INC = -I$(MLX_DIR)

ifeq ($(UNAME), Darwin)
MLX_LIB = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
else
MLX_LIB = -L$(MLX_DIR) -lmlx -lXext -lX11
endif


# libm
LIBM_LIB = -lm


CFLAGS += $(MLX_INC)
# LDFLAGS += $(MLX_LIB)
LDFLAGS += $(MLX_LIB) $(LIBFT_LIB) $(LIBM_LIB)



# make
MAKE = make
ALL = all
CLEAN = clean
FCLEAN = fclean
FFCLEAN = ffclean
RE = re
RUN = run


# TEST = test
TEST_H = test_h
TEST_E = test_e
TEST_EE = test_ee

# command
RM = rm -f
RM_DIR = rm -rf

CLEAR = clear


# testcase
TESTCASE1 = map/test1_north.cub
# TESTCASE1 = map/test.cub




$(ALL): $(NAME)

# $(NAME): $(OBJ) $(MLX_DIR)/libmlx.a $(LIBFT)
# $(NAME): $(MLX) $(LIBFT) $(OBJ)
# $(NAME): $(OBJ) $(MLX) $(LIBFT)
$(NAME): $(MLX) $(LIBFT) $(OBJ)
#	$(CC) $(CFLAGS) $(OBJ) $(MLX) $(LIBFT) $(LDFLAGS) -o $@
	$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $@
#	$(CC) $(CFLAGS) $(LIBFT_LIB) $(OBJ) $(LDFLAGS) -o $(NAME)
#	$(CC) $(CFLAGS) $(LIBFT_LIB) -o $(NAME) $(OBJ) $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(LIBFT_INC) -c $< -o $@

# $(MLX_DIR)/libmlx.a:
$(MLX):
#	pwd
#	cd mlx
#	cd ./mlx
#	pwd
	tar -xvzf $(MLX_ZIP)
#	cd ..
	$(MAKE) -C $(MLX_DIR)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(CLEAN):
	$(RM_DIR) $(OBJ_DIR)
#	$(RM_DIR) $(MLX_DIR)
	@if [ -d $(MLX_DIR) ]; then $(MAKE) -C $(MLX_DIR) $(CLEAN); fi
#	$(MAKE) -C $(MLX_DIR) $(CLEAN)
#	$(MAKE) -C $(MLX_DIR) $(CLEAN)
	$(MAKE) -C $(LIBFT_DIR) $(CLEAN)

$(FCLEAN): $(CLEAN)
	$(RM) $(NAME)
#	$(MAKE) -C $(MLX_DIR) $(CLEAN)
#	$(MAKE) -C $(LIBFT_DIR) $(FCLEAN)

$(FFCLEAN): $(FCLEAN)
	$(RM_DIR) $(MLX_DIR)
	$(CLEAR)

$(RE): $(FCLEAN) $(ALL)



$(RUN):
	$(MAKE) $(RE)
	./$(NAME) $(TESTCASE1)
	$(MAKE) $(FCLEAN)



$(TEST_H):
	$(MAKE) $(RE)
	find ./map -name 'test*' -type f -print -exec ./cub3d \{\} \;
	$(MAKE) 

$(TEST_E):
	$(MAKE) $(RE)
	find ./map/invalid_maps -name '*' -type f -print -exec ./cub3d \{\} \;
	$(MAKE) $(FCLEAN)

$(TEST_EE):
	$(MAKE) $(RE)
	find ./map/invalid_maps -name '*invalid_character*' -type f -print -exec ./cub3d \{\} \;
	$(MAKE) $(FCLEAN)



.PHONY: $(ALL) $(CLEAN) $(FCLEAN) $(FFCLEAN) $(RE) $(RUN)

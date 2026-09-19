# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcasadio <dcasadio@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/11 16:11:45 by dcasadio          #+#    #+#              #
#    Updated: 2026/09/18 12:00:00 by dcasadio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = cub3D

CC      = cc
FLAGS   = -Wall -Werror -Wextra

# Traces de debug : `make re DEBUG=1`
ifdef DEBUG
FLAGS  += -g3 -D DEBUG=$(DEBUG)
endif

INCDIR   = ./includes
MLXDIR   = ./minilibx-linux
MLXA     = $(MLXDIR)/libmlx.a
LIBFTDIR = ./libft
LIBFT    = $(LIBFTDIR)/libft.a
SRC_DIR  = ./src

SRC = $(SRC_DIR)/main.c \
      $(SRC_DIR)/utils/ray_utils.c \
      $(SRC_DIR)/window/init_window.c \
      $(SRC_DIR)/game/game.c \
      $(SRC_DIR)/game/img.c \
      $(SRC_DIR)/game/ray.c \
      $(SRC_DIR)/game/textures.c \
      $(SRC_DIR)/hook/hooks.c \
      $(SRC_DIR)/parsing/parsing.c \
      $(SRC_DIR)/parsing/parse_elements.c \
      $(SRC_DIR)/parsing/parse_textures.c \
      $(SRC_DIR)/parsing/parse_colors.c \
      $(SRC_DIR)/parsing/parse_map.c \
      $(SRC_DIR)/parsing/parse_line.c \
      $(SRC_DIR)/parsing/parse_utils.c \
      $(SRC_DIR)/parsing/map_build.c \
      $(SRC_DIR)/parsing/map_validate.c \
      $(SRC_DIR)/parsing/map_utils.c \
      $(SRC_DIR)/parsing/flood_fill.c \
      $(SRC_DIR)/parsing/flood_utils.c \
      $(SRC_DIR)/parsing/color_utils.c \
      $(SRC_DIR)/parsing/texture_check.c

OBJS = $(SRC:.c=.o)

INCLUDES = -I$(MLXDIR) -I$(LIBFTDIR) -I$(INCDIR)
LIBS     = $(LIBFT) -L$(MLXDIR) -lmlx -lXext -lX11 -lm

all: $(NAME)

$(NAME): $(LIBFT) $(MLXA) $(OBJS)
	$(CC) $(FLAGS) $(OBJS) $(INCLUDES) -o $(NAME) $(LIBS)

%.o: %.c $(INCDIR)/game.h
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR) all

$(MLXA):
	$(MAKE) -C $(MLXDIR) all

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFTDIR) clean
	$(MAKE) -C $(MLXDIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re

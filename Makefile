NAME		= cub3D

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g3
CPPFLAGS	= -Iincludes -I$(LIBFT_DIR) -I$(MLX_DIR)

LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a

MLX_DIR		= minilibx-linux
MLX			= $(MLX_DIR)/libmlx.a
MLX_FLAGS	= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

SRC_DIR		= src
OBJ_DIR		= obj

SRCS		= $(SRC_DIR)/main.c \
			  $(SRC_DIR)/parsing/parsing.c

OBJS		= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft $(MLX_FLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR) bonus

$(MLX):
	$(MAKE) -C $(MLX_DIR) all

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re

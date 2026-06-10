CC = cc
FLAGS = -Wall -Werror -Wextra -g3

NAME = cub3D

MLXDIR = ./minilibx-linux
MLXA = $(MLXDIR)/libmlx.a

SRC=./src
DIR_UTILS=$SRC/utils
MAPS=./maps
OBJS = $(SRC:.c=.o)

$(NAME): all

all : $(OBJS) mlx
	$(CC) $(FLAGS) $(OBJS) -I$(MLXDIR) -o $(NAME) -L$(MLXDIR) -lmlx -lXext -lX11 -lm 
%.o : %.c
	$(CC) $(FLAGS) -I$(MLXDIR) -c $< -o $@
mlx :
	make -C $(MLXDIR) all
clean :
	rm -rf $(OBJS)
fclean : clean
	rm -rf $(NAME)
re : fclean all

.PHONY: all clean fclean re mlx

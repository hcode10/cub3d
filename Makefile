CC = cc
FLAGS = -Wall -Werror -Wextra -g3

NAME = cub3D

TEST=./test/main.c
MAIN=./main.c
MLXDIR = ./minilibx-linux
MLXA = $(MLXDIR)/libmlx.a

SRC_DIR = ./src

DIR_UTILS = $SRC_DIR/utils
SRC_UTILS = \

DIR_WINDOW = $SRC_DIR/window
SRC_WINDOW = $DIR_WINDOW/init.c \

SRC = $SRC_UTILS \
	  $SRC_WINDOW \

MAPS = ./maps
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

test: all

.PHONY: all clean fclean re mlx

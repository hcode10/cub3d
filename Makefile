CC = cc
FLAGS = -Wall -Werror -Wextra -g3
NAME = cub3D

MLXDIR = ./minilibx-linux
MLXA = $(MLXDIR)/libmlx.a

SRC_DIR = ./src

#---------   UTILS --------------

DIR_UTILS = $SRC_DIR/utils
SRC_UTILS = \

#--------  WINDOW -----------

DIR_WINDOW = $SRC_DIR/window
SRC_WINDOW = $DIR_WINDOW/init.c \


#-------- ALL THE SOURCES -----
SRC = main.c \
		$SRC_UTILS \
		$SRC_WINDOW \

MAPS = ./maps
OBJS = $(SRC:.c=.o)

#------- TEST CFG ----------

TEST= ./test/main.c \
	  $(SRC_UTILS) \
	  $(SRC_WINDOW) \

TEST_OBJS = $(TEST:.c=.o)

TEST_TARGET = cub3Dtest

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

$(TEST_TARGET) : $(TEST_OBJS) mlx
	$(CC) $(FLAGS) $(OBJS) -I$(MLXDIR) -o $(TEST_TARGET) -L$(MLXDIR) -lmlx -lXext -lX11 -lm 
.PHONY: all clean fclean re mlx

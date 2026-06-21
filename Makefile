CC = cc
FLAGS = -Wall -Werror -Wextra -g3
NAME = cub3D

INCDIR=./includes

MLXDIR = ./minilibx-linux
MLXA = $(MLXDIR)/libmlx.a

LIBFTDIR = ./libft/
LIBFT=$(LIBFTDIR)libft.a

SRC_DIR = ./src


#---------   UTILS --------------

DIR_UTILS = $(SRC_DIR)/utils
SRC_UTILS =  $(DIR_UTILS)/ray_utils.c \

#---------   PARSING --------------

SRC_PARSING = $(SRC_DIR)/parsing


#--------  WINDOW -----------

DIR_WINDOW = $(SRC_DIR)/window
SRC_WINDOW = $(DIR_WINDOW)/init_window.c \
			 $(DIR_WINDOW)/ceilnfloor.c \

#-------- GAME --------

DIR_GAME = $(SRC_DIR)/game
SRC_GAME = $(DIR_GAME)/game.c \
			$(DIR_GAME)/img.c \
			$(DIR_GAME)/ray.c

#-------- ALL THE SOURCES -----
SRC = $(SRC_DIR)/main.c \
        $(SRC_UTILS) \
        $(SRC_WINDOW) \
		$(SRC_GAME) \
	  $(SRC_PARSING)/parsing.c \
	  $(SRC_PARSING)/map_parse.c \
	  $(SRC_PARSING)/map_utils.c \
	  $(SRC_PARSING)/map_validate.c \
	  $(SRC_PARSING)/parsing_utils.c \
	  $(SRC_PARSING)/flood_fill.c \

MAPS = ./maps
OBJS = $(SRC:.c=.o)

#------- TEST CFG ----------

TEST= ./test/main.c \
	  $(SRC_UTILS) \
      $(SRC_PARSING)/parsing.c \
	  $(SRC_WINDOW) \
      $(SRC_GAME) \

TEST_OBJS = $(TEST:.c=.o)

TEST_TARGET = cub3Dtest

$(NAME): all

all : $(OBJS) libft mlx
	$(CC) $(FLAGS) $(OBJS) -I$(MLXDIR) -I$(LIBFTDIR) -I$(INCDIR) -o $(NAME) $(LIBFT) -L$(MLXDIR) -lmlx -lXext -lX11 -lm

libft:
	make -C $(LIBFTDIR) all

mlx :
	make -C $(MLXDIR) all

clean:
	rm -rf $(OBJS)

fclean : clean
	make -C $(MLXDIR) clean
	make -C $(LIBFTDIR) fclean
	rm -rf $(NAME)

re : fclean all
	
test: all

$(TEST_TARGET) : $(TEST_OBJS) libft mlx
	$(CC) $(FLAGS) $(TEST_OBJS) -I$(MLXDIR) -I$(LIBFTDIR) -I$(INCDIR) -o $(TEST_TARGET) $(LIBFT) -L$(MLXDIR) -lmlx -lXext -lX11 -lm 

%.o : %.c
	$(CC) $(FLAGS) -I$(MLXDIR) -I$(LIBFTDIR) -I$(INCDIR) -L$(LIBFT) -c $< -o $@

.PHONY: all clean fclean re mlx libft cub3Dtest

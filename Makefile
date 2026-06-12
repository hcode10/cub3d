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
SRC_UTILS = \

#---------   PARSING --------------

SRC_PARSING = $(SRC_DIR)/parsing


#--------  WINDOW -----------

DIR_WINDOW = $(SRC_DIR)/window
SRC_WINDOW = $(DIR_WINDOW)/init_window.c \
			 $(DIR_WINDOW)/ceilnfloor.c \

#-------- ALL THE SOURCES -----
SRC = $(SRC_DIR)/main.c \
      $(SRC_PARSING)/parsing.c \
        $(SRC_UTILS) \
        $(SRC_WINDOW) \

MAPS = ./maps
OBJS = $(SRC:.c=.o)

#------- TEST CFG ----------

TEST= ./test/main.c \
	  $(SRC_UTILS) \
	  $(SRC_WINDOW) \
      $(SRC_UTILS) \

TEST_OBJS = $(TEST:.c=.o)

TEST_TARGET = cub3Dtest

$(NAME): all

all : $(OBJS) libft mlx
	$(CC) $(FLAGS) $(OBJS) -I$(MLXDIR) -I$(LIBFTDIR) -I$(INCDIR) -o $(NAME) $(LIBFT) -L$(MLXDIR) -lmlx -lXext -lX11 -lm

mlx :
	make -C $(MLXDIR) all

fclean : clean
	make -C $(MLXDIR) fclean
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

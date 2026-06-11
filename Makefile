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

#--------  WINDOW -----------

# DIR_WINDOW = $(SRC_DIR)/window
# SRC_WINDOW = $(DIR_WINDOW)/init.c \

#-------- ALL THE SOURCES -----
SRC = $(SRC_DIR)/main.c \
		$(SRC_UTILS) \
		# $(SRC_WINDOW) \

MAPS = ./maps
OBJS = $(SRC:.c=.o)

#------- TEST CFG ----------

TEST= ./test/main.c \
	  $(SRC_UTILS) \
	  # $(SRC_WINDOW) \

TEST_OBJS = $(TEST:.c=.o)

TEST_TARGET = cub3Dtest

$(NAME): all

all : $(OBJS) libft mlx
	$(CC) $(FLAGS) $(OBJS) -I$(MLXDIR) -I$(INCDIR) -o $(NAME) -L$(LIBFT) -L$(MLXDIR) -lmlx -lXext -lX11 -lm 

%.o : %.c
	$(CC) $(FLAGS) -I$(MLXDIR) -I$(INCDIR) -c $< -o $@
libft:
	make -C $(LIBFT)
mlx :
	make -C $(MLXDIR) all
clean :
	make -C $(MLXDIR) clean
	make -C $(LIBFTDIR) clean
	rm -rf $(OBJS)
fclean : clean
	make -C $(MLXDIR) fclean
	make -C $(LIBFTDIR) fclean
	rm -rf $(NAME)
re : fclean all
	
test: all

$(TEST_TARGET) : $(TEST_OBJS) mlx
	$(CC) $(FLAGS) $(OBJS) -I$(MLXDIR) -I$(INCDIR) -o $(TEST_TARGET) $(LIBFT) -L$(MLXDIR) -lmlx -lXext -lX11 -lm 
.PHONY: all clean fclean re mlx

# SRCS 	= main.c
# OBJS	= $(SRCS:.c=.o)

# NAME	= so_long
# CC		= cc
# RM		= rm -f
# CFLAGS	= -Wall -Wextra	-Werror
# LIBFT	= ./libft/libft.a
# MINILIBX = ./minilibx_opengl/libmlx.a

# INCLUDES = -I/usr/include -Imlx
 
# MLX_DIR = ./mlx
# MLX_LIB = $(MLX_DIR)/libmlx_$(UNAME).a
# MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppkKit

# %.o:%.c
# 	$(CC) $(CFLAGS) -c $< -o $@

# $(NAME): $(OBJS)
# 	$(MAKE) -C ./libft
# 	$(MAKE) -C ./minilibx_opengl
# 	cp libft/libft.a $(NAME)
# 	cp minilibx_opengl/libmlx.a $(NAME)
# 	ar -rcs $(NAME) $(OBJS)

# all: $(NAME)

# clean:
# 	$(MAKE) clean -C ./libft
# 	$(MAKE) clean -C ./minilibx_opengl
# 	$(RM) $(OBJS)

# fclean: clean
# 	$(MAKE) fclean -C ./libft
# 	$(RM) $(NAME)

# re: fclean	all

# .PHONY: all clean fclean re
NAME=so_long
CFLAGS=-Wall -Wextra -Werror
SRCS=main.c
OBJS=$(SRCS:.c=.o)

MINILIBX_DIR := ./minilibx_opengl
MINILIBX := $(MINILIBX_DIR)/libmlx.a

INCLUDES := -I$(MINILIBX_DIR)
LDFLAGS := -L$(MINILIBX_DIR)
LIBS=-lm -lmlx

.PHONY: all
all: $(NAME)

$(NAME): $(OBJS) $(MINILIBX)
	$(CC) $(OBJS) $(LDFLAGS) $(LIBS) -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(MINILIBX):
	$(MAKE) -j4 -C $(MINILIBX_DIR)

.PHONY: clean
clean:
	$(RM) $(OBJS)

.PHONY: fclean
fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(MINILIBX_DIR) clean

.PHONY: re
re: fclean all

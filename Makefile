NAME = so_long
BONUS_NAME = so_long_bonus

# Source files
SOURCES = so_long.c get_next_line.c validate.c setup_game.c play_game.c
OBJECTS = $(SOURCES:.c=.o)

SOURCES_BONUS = ./bonus/so_long_bonus.c ./bonus/get_next_line_bonus.c \
				./bonus/validate_bonus.c ./bonus/setup_game_bonus.c \
				./bonus/play_game_bonus.c
OBJECTS_BONUS = $(SOURCES_BONUS:.c=.o)

# Compiler settings
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
LIBFT = libft/libft.a
MLX = minilibx-linux/libmlx.a

# Targets
ifdef WITH_BONUS
	TARGET_OBJECTS = $(OBJECTS_BONUS)
	TARGET_NAME = $(BONUS_NAME)
else
	TARGET_OBJECTS = $(OBJECTS)
	TARGET_NAME = $(NAME)
endif

all: $(NAME)

bonus: $(BONUS_NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJECTS)
	$(CC) -o $(NAME) $(OBJECTS) -Lminilibx-linux -lmlx -lX11 -lXext -Llibft -lft

$(BONUS_NAME): $(LIBFT) $(MLX) $(OBJECTS_BONUS)
	$(CC) -o $(BONUS_NAME) $(OBJECTS_BONUS) -Lminilibx-linux -lmlx -lX11 -lXext -Llibft -lft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C libft

$(MLX):
	make -C minilibx-linux

clean:
	rm -f $(OBJECTS) $(OBJECTS_BONUS)
	make -C libft clean
	make -C minilibx-linux clean

fclean: clean
	rm -f $(NAME) $(BONUS_NAME) libft/libft.a minilibx-linux/libmlx.a

re: fclean all

.PHONY: all bonus clean fclean re

NAME = so_long
SOURCES = so_long.c get_next_line.c validate.c setup_game.c play_game.c
OBJECTS = $(SOURCES:.c=.o)

SOURCES_BONUS = ./bonus/so_long_bonus.c ./bonus/get_next_line_bonus.c  \
				./bonus/validate_bonus.c ./bonus/setup_game_bonus.c  \
				./bonus/play_game_bonus.c
SOURCE_OBJECTS = $(SOURCES_BONUS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

ifdef WITH_BONUS
	OBJECTS = $(SOURCE_OBJECTS)
endif

all: $(NAME)

bonus: 
	make WITH_BONUS=1

$(NAME): libft $(OBJECTS) minilibx
	gcc -o $@ $(OBJECTS) -Lminilibx_opengl -lmlx -Llibft -lft \
		-framework OpenGL -framework AppKit -lz -g

%.o: %.c
	$(CC) -c -g $? -o $@

minilibx:
	make -C minilibx_opengl

libft:
	make -C libft

clean:
	rm -f $(OBJECTS) $(SOURCE_OBJECTS)
	make -C minilibx_opengl clean
	make -C libft clean

fclean: clean
	rm -f $(NAME) libft/libft.a

re: fclean all

.PHONY: all bonus minilibx libft clean fclean re

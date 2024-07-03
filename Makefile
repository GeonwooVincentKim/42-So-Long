NAME = so_long
SOURCES = so_long.c get_next_line.c validate.c setup_game.c play_game.c
OBJECTS = $(SOURCES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

bonus: $(NAME)

$(NAME): $(OBJECTS) minilibx libft
	gcc -o $@ $(OBJECTS) -Lminilibx_opengl -lmlx -Llibft -lft \
		-framework OpenGL -framework AppKit -lz

%.o: %.c
	$(CC) -c $(CFLAGS) $?

minilibx:
	make -C minilibx_opengl

libft:
	make -C libft

clean:
	rm -f $(OBJECTS)
	make -C minilibx_opengl clean
	make -C libft clean

fclean: clean
	rm -f $(NAME) libft/libft.a

re: fclean all

.PHONY: all bonus minilibx libft clean fclean re

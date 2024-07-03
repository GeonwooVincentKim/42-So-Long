/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwkim <geonwkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 22:26:15 by geonwkim          #+#    #+#             */
/*   Updated: 2024/07/04 01:07:33 by geonwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

# define BUFFER_SIZE 42
# define ESC 53
# define LEFT 0
# define RIGHT 2
# define DOWN 1
# define UP 13

# ifndef MAX_FILE_DESCRIPTOR
#  define MAX_FILE_DESCRIPTOR 256
# endif

typedef struct s_xy
{
	int	x;
	int	y;
}	t_xy;

typedef struct s_player
{
	int		c;
	int		moves;
	t_xy	attempt;
	t_xy	actual;
}	t_player;

typedef struct s_enemy
{
	t_xy	actual;
}	t_enemy;

typedef struct s_map
{
	int		rows;
	int		cols;
	int		c;
	int		e;
	int		p;
	int		v;
	int		diff_cols;
	int		px;
	char	**lines;
}	t_map;

typedef struct s_game
{
	char		**lines;
	void		*o;
	void		*c;
	void		*c2;
	void		*e;
	void		*p;
	void		*p2;
	void		*p3;
	void		*v;
	void		*mlx;
	void		*win;
	t_player	player;
	t_enemy		*enemies;
	t_map		map;
}	t_game;

/* get_next_line.c */
char	*get_next_line(int fd);
// size_t	ft_strlcpy(char *dest, const char *src, size_t dest_size);
// void	*ft_memset(void *ptr, int x, size_t n);

// // get_next_line_utils.c
// char	*ft_strchr(const char *str, int c);
// char	*ft_substr(const char *str, unsigned int start, size_t len);
// size_t	ft_strlen(const char *str);
// char	*ft_strjoin(const char *s1, const char *s2);
// char	*ft_strdup(const char *s);

/* validate.c */
int		is_valid_map(char *file, t_map *map);

/* setup.c */
void	init_g(t_game *g);
void	init_lines_and_images(char *file, t_game *g);
void	init_enemies(t_game *g);
void	put_images(t_game *g);

/* gameplay.c */
void	end_game(t_game *g);
void	move(t_game *g);

#endif

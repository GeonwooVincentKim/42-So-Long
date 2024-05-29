/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwkim <geonwkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 22:26:15 by geonwkim          #+#    #+#             */
/*   Updated: 2024/05/30 02:18:40 by geonwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include	<unistd.h>
# include	<stdio.h>
# include	<stdlib.h>
# include	"mlx.h"

# define WIDTH 1280
# define HEIGHT 721

void	*mlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title);

# define BUFFER_SIZE 42
# define ESC 53
# define LEFT 0
# define RIGHT 2
# define DOWN 1
# define UP 13

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

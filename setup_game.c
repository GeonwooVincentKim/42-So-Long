/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwkim <geonwkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 02:17:22 by geonwkim          #+#    #+#             */
/*   Updated: 2024/11/28 21:39:11 by geonwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include "so_long.h"
#include "minilibx-linux/mlx.h"

static int	update_p_or_v(t_game *g, int i, int j, int k)
{
	if (k >= 0)
	{
		g->enemies[k].actual.x = j;
		g->enemies[k].actual.y = i;
	}
	else
	{
		g->player.attempt.x = j;
		g->player.attempt.y = i;
		g->player.actual.x = j;
		g->player.actual.y = i;
	}
	return (1);
}

void	init_g(t_game *g)
{
	g->player.c = 0;
	g->player.moves = 0;
	g->map.c = 0;
	g->map.e = 0;
	g->map.p = 0;
	g->map.v = 0;
	g->map.diff_cols = 0;
	g->map.px = 32;
}

void	init_lines_and_images(char *file, t_game *g)
{
	int			i;
	char		*line;
	char		**ret;
	const int	fd = open(file, O_RDONLY);

	ret = malloc(sizeof(char *) * (g->map.rows + 1));
	if (!ret)
		return ;
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		ret[i++] = line;
		line = get_next_line(fd);
	}
	ret[i] = 0;
	g->lines = ret;
	g->o = mlx_xpm_file_to_image(g->mlx, "xpm/o.xpm", &g->map.px, &g->map.px);
	g->c = mlx_xpm_file_to_image(g->mlx, "xpm/c1.xpm", &g->map.px, &g->map.px);
	g->c2 = mlx_xpm_file_to_image(g->mlx, "xpm/c2.xpm", &g->map.px, &g->map.px);
	g->e = mlx_xpm_file_to_image(g->mlx, "xpm/e.xpm", &g->map.px, &g->map.px);
	g->p2 = mlx_xpm_file_to_image(g->mlx, "xpm/p1.xpm", &g->map.px, &g->map.px);
	g->p3 = mlx_xpm_file_to_image(g->mlx, "xpm/p2.xpm", &g->map.px, &g->map.px);
	g->p = g->p2;
	g->v = mlx_xpm_file_to_image(g->mlx, "xpm/v.xpm", &g->map.px, &g->map.px);
}

void	init_enemies(t_game *g)
{
	t_enemy	*enemies;

	enemies = malloc(sizeof(t_enemy) * g->map.v);
	if (!enemies)
		return ;
	g->enemies = enemies;
}

void	put_images(t_game *g)
{
	int	i;
	int	j;
	int	k;
	int	(*f)(void *, void *, void *, int x, int y);

	f = mlx_put_image_to_window;
	i = -1;
	k = -1;
	while (++i < g->map.rows)
	{
		j = -1;
		while (++j < g->map.cols)
		{
			if (g->lines[i][j] == '1')
				f(g->mlx, g->win, g->o, j * g->map.px, i * g->map.px);
			else if (g->lines[i][j] == 'C')
				f(g->mlx, g->win, g->c, j * g->map.px, i * g->map.px);
			else if (g->lines[i][j] == 'E')
				f(g->mlx, g->win, g->e, j * g->map.px, i * g->map.px);
			else if (g->lines[i][j] == 'P' && update_p_or_v(g, i, j, -1))
				f(g->mlx, g->win, g->p, j * g->map.px, i * g->map.px);
			else if (g->lines[i][j] == 'V' && update_p_or_v(g, i, j, ++k))
				f(g->mlx, g->win, g->v, j * g->map.px, i * g->map.px);
		}
	}
}

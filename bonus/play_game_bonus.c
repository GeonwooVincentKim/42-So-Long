/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_game_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwkim <geonwkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 02:16:56 by geonwkim          #+#    #+#             */
/*   Updated: 2024/11/28 21:50:52 by geonwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "so_long_bonus.h"
#include "../minilibx-linux/mlx.h"
#include "../libft/libft.h"

static void	move_enemy(t_game *g)
{
	int		k;
	t_enemy	enemy;

	k = -1;
	while (++k < g->map.v)
	{
		enemy = g->enemies[k];
		if (g->lines[enemy.actual.y - 1][enemy.actual.x] == '0' )
			g->lines[enemy.actual.y - 1][enemy.actual.x] = 'V';
		else if (g->lines[enemy.actual.y + 1][enemy.actual.x] == '0')
			g->lines[enemy.actual.y + 1][enemy.actual.x] = 'V';
		else
			continue ;
		g->lines[enemy.actual.y][enemy.actual.x] = '0';
	}
}

static void	animate(t_game *g)
{
	void	*tmp;

	tmp = g->c;
	g->c = g->c2;
	g->c2 = tmp;
	if (g->lines[g->player.attempt.y][g->player.attempt.x] == 'C')
		g->p = g->p3;
	else
		g->p = g->p2;
}

void	end_game(t_game *g)
{
	char	**tmp;

	if (g->lines[g->player.attempt.y][g->player.attempt.x] == 'E' \
			&& g->player.c == g->map.c)
		printf("You win!\n");
	else
		printf("You lose!\n");
	tmp = g->lines;
	while (*tmp)
		free(*tmp++);
	free(g->lines);
	if (g->enemies)
		free(g->enemies);
	free(g->mlx);
	exit(0);
}

void	move(t_game *g)
{
	char	*moves;

	if (g->lines[g->player.attempt.y][g->player.attempt.x] == 'V')
		end_game(g);
	g->lines[g->player.actual.y][g->player.actual.x] = '0';
	move_enemy(g);
	animate(g);
	if (g->lines[g->player.attempt.y][g->player.attempt.x] == 'C')
		g->player.c += 1;
	else if (g->lines[g->player.attempt.y][g->player.attempt.x] == 'E' \
			|| g->lines[g->player.attempt.y][g->player.attempt.x] == 'V')
		end_game(g);
	g->lines[g->player.attempt.y][g->player.attempt.x] = 'P';
	g->player.moves += 1;
	mlx_clear_window(g->mlx, g->win);
	put_images(g);
	moves = ft_itoa(g->player.moves);
	mlx_string_put(g->mlx, g->win, 12, 22, 0x00FFFFFF, moves);
	free(moves);
}

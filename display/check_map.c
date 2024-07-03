/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwkim <geonwkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:28:00 by geonwkim          #+#    #+#             */
/*   Updated: 2024/06/26 16:29:25 by geonwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

int	check_cube_extension(char *str, t_long *sl)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	if (str[i - 1] == 'r' && str[i - 2] == 'e'
		&& str[i - 3] == 'b' && str[i - 4] == '.')
	{
		i = open(str, O_RDONLY);
		if (i == -1)
			showerror(sl, "File Name is not correct");
		else
			close(i);
		return (0);
	}
	showerror(sl, "Files without .ber extension is not accepted");
	return (0);
}

int	flood_and_fill(t_long *sl, int mapy, int mapx)
{
	if (sl->map[mapy][mapx] == 'a' ||
			sl->map[mapy][mapx] == 'c' || sl->map[mapy][mapx] == 'd'
			|| sl->map[mapy][mapx] == 'e' || sl->map[mapy][mapx] == 'f')
	{
		if (checkaround(mapx, mapy, sl) == 0)
			showerror(sl, "Map is not surrounded/closed by wall");
		flood_and_fill2(sl, mapy, mapx);
		flood_and_fill(sl, mapy, mapx + 1);
		flood_and_fill(sl, mapy, mapx - 1);
		flood_and_fill(sl, mapy + 1, mapx);
		flood_and_fill(sl, mapy - 1, mapx);
	}
	return (1);
}

void	floodandfill2(t_long *sl, int mapy, int mapx)
{
	if (sl->map[mapy][mapx] == 'a')
		sl->map[mapy][mapx] = '0';
	if (sl->map[mapy][mapx] == 'c')
		sl->map[mapy][mapx] = 'P';
	if (sl->map[mapy][mapx] == 'd')
	{
		sl->map[mapy][mapx] = 'E';
		sl->exitparse++;
	}
	if (sl->map[mapy][mapx] == 'e')
	{
		sl->map[mapy][mapx] = 'C';
		sl->collectibleparse++;
	}
	if (sl->map[mapy][mapx] == 'f')
		sl->map[mapy][mapx] = 'B';
}

int	checkaround(int mapx, int mapy, t_long *sl)
{
	if (mapy == 0 || mapy == sl->y - 1
		|| mapx == 0 || mapx == sl->x - 1)
		showerror(sl, "Map is not surrounded/closed by walls");
	if (checkifgood(sl->map[mapy + 1][mapx]) == 0)
		return (0);
	if (checkifgood(sl->map[mapy - 1][mapx]) == 0)
		return (0);
	if (checkifgood(sl->map[mapy][mapx + 1]) == 0)
		return (0);
	if (checkifgood(sl->map[mapy][mapx - 1]) == 0)
		return (0);
	return (1);
}

int	checkthewall(t_long *sl)
{
	int	mapx;
	int	mapy;

	mapy = (int)sl->player_x;
	mapx = (int)sl->player_y;
	sl->collectibleparse = 0;
	sl->exitparse = 0;
	floodandfill(sl, mapx, mapy + 1);
	floodandfill(sl, mapx, mapy - 1);
	floodandfill(sl, mapx + 1, mapy);
	floodandfill(sl, mapx, mapy - 1);
	if (sl->collectibleparse != sl->collectibletotal)
		showerror(sl, "Some collectible are out of the map");
	if (sl->exitparse == 0)
		showerror(sl, "Exit is out of the map");
	return (0);
}

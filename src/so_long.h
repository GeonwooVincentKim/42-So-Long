/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwkim <geonwkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 22:26:15 by geonwkim          #+#    #+#             */
/*   Updated: 2024/05/27 23:10:16 by geonwkim         ###   ########.fr       */
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

#endif

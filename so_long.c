/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwkim <geonwkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 02:18:58 by geonwkim          #+#    #+#             */
/*   Updated: 2024/06/26 16:25:58 by geonwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

int	main(int argc, char **argv)
{
	t_long	solong;

	initvar(&solong);
	if (argc == 1)
		showerror(&solong, "Missing map (./so_long maps/intra.ber)");
	if (argc > 2)
		showerror(&solong, "Too many arguments");
	parsing(&solong, argv[1]);
	display(&solong);
	return (0);
}

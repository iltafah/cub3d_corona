/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_positions_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 11:01:40 by iltafah           #+#    #+#             */
/*   Updated: 2020/10/27 13:58:53 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	set_plyr_direction(t_vals *vals, char spawning)
{
	vals->plyr.x_dir = spawning == 'N' ? -1 : vals->plyr.x_dir;
	vals->plyr.y_dir = spawning == 'N' ? 0 : vals->plyr.y_dir;
	vals->cam.x_plane = spawning == 'N' ? 0 : vals->cam.x_plane;
	vals->cam.y_plane = spawning == 'N' ? 0.66 : vals->cam.y_plane;
	vals->plyr.x_dir = spawning == 'S' ? 1 : vals->plyr.x_dir;
	vals->plyr.y_dir = spawning == 'S' ? 0 : vals->plyr.y_dir;
	vals->cam.x_plane = spawning == 'S' ? 0 : vals->cam.x_plane;
	vals->cam.y_plane = spawning == 'S' ? -0.66 : vals->cam.y_plane;
	vals->plyr.x_dir = spawning == 'E' ? 0 : vals->plyr.x_dir;
	vals->plyr.y_dir = spawning == 'E' ? 1 : vals->plyr.y_dir;
	vals->cam.x_plane = spawning == 'E' ? 0.66 : vals->cam.x_plane;
	vals->cam.y_plane = spawning == 'E' ? 0 : vals->cam.y_plane;
	vals->plyr.x_dir = spawning == 'W' ? 0 : vals->plyr.x_dir;
	vals->plyr.y_dir = spawning == 'W' ? -1 : vals->plyr.y_dir;
	vals->cam.x_plane = spawning == 'W' ? -0.66 : vals->cam.x_plane;
	vals->cam.y_plane = spawning == 'W' ? 0 : vals->cam.y_plane;
}

void	set_plyr_position(t_vals *vals)
{
	int		x;
	int		y;

	x = -1;
	while (g_map[++x])
	{
		y = -1;
		while (g_map[x][++y])
		{
			if (g_map[x][y] == 'N' || g_map[x][y] == 'S'
				|| g_map[x][y] == 'E' || g_map[x][y] == 'W')
			{
				vals->plyr.x_pos = x + 0.5;
				vals->plyr.y_pos = y + 0.5;
				set_plyr_direction(vals, g_map[x][y]);
				g_map[x][y] = '0';
				break ;
			}
		}
	}
}

void	set_sprite_position(t_vals *vals)
{
	int			x;
	int			y;

	x = -1;
	while (g_map[++x])
	{
		y = -1;
		while (g_map[x][++y])
		{
			if (g_map[x][y] == '2')
			{
				vals->sprite.x_pos = x + 0.5;
				vals->sprite.y_pos = y + 0.5;
				break ;
			}
		}
	}
}

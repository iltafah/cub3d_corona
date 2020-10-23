/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_positions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 11:01:40 by iltafah           #+#    #+#             */
/*   Updated: 2020/10/23 11:01:41 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	set_plyr_direction(t_vals *vals, char spawning)
{
	PLYR.x_dir = spawning == 'N' ? -1 : PLYR.x_dir;
	PLYR.y_dir = spawning == 'N' ? 0 : PLYR.y_dir;
	CAM.x_plane = spawning == 'N' ? 0 : CAM.x_plane;
	CAM.y_plane = spawning == 'N' ? 0.66 : CAM.y_plane;
	PLYR.x_dir = spawning == 'S' ? 1 : PLYR.x_dir;
	PLYR.y_dir = spawning == 'S' ? 0 : PLYR.y_dir;
	CAM.x_plane = spawning == 'S' ? 0 : CAM.x_plane;
	CAM.y_plane = spawning == 'S' ? -0.66 : CAM.y_plane;
	PLYR.x_dir = spawning == 'E' ? 0 : PLYR.x_dir;
	PLYR.y_dir = spawning == 'E' ? 1 : PLYR.y_dir;
	CAM.x_plane = spawning == 'E' ? 0.66 : CAM.x_plane;
	CAM.y_plane = spawning == 'E' ? 0 : CAM.y_plane;
	PLYR.x_dir = spawning == 'W' ? 0 : PLYR.x_dir;
	PLYR.y_dir = spawning == 'W' ? -1 : PLYR.y_dir;
	CAM.x_plane = spawning == 'W' ? -0.66 : CAM.x_plane;
	CAM.y_plane = spawning == 'W' ? 0 : CAM.y_plane;
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
				PLYR.x_pos = x + 0.5;
				PLYR.y_pos = y + 0.5;
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
				SPRITE.x_pos = x + 0.5;
				SPRITE.y_pos = y + 0.5;
				break ;
			}
		}
	}
}

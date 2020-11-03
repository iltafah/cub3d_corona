/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_positions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 11:01:40 by iltafah           #+#    #+#             */
/*   Updated: 2020/11/02 14:17:35 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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

int		count_sprites_on_the_map(void)
{
	int			count;
	int			x;
	int			y;

	count = 0;
	x = -1;
	while (g_map[++x])
	{
		y = -1;
		while (g_map[x][++y])
			if (g_map[x][y] == '2')
				count++;
	}
	return (count);
}

void	set_sprite_position(t_vals *vals)
{
	int			x;
	int			y;
	int			i;

	vals->sprite.num_of_sprites = count_sprites_on_the_map();
	vals->sprite.x_pos = malloc(sizeof(double) * vals->sprite.num_of_sprites);
	vals->sprite.y_pos = malloc(sizeof(double) * vals->sprite.num_of_sprites);
	vals->sprite.index = malloc(sizeof(int) * vals->sprite.num_of_sprites);
	x = -1;
	i = 0;
	while (g_map[++x])
	{
		y = -1;
		while (g_map[x][++y])
			if (g_map[x][y] == '2')
			{
				vals->sprite.x_pos[i] = x + 0.5;
				vals->sprite.y_pos[i++] = y + 0.5;
			}
	}
}

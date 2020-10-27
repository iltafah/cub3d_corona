/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_walls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 10:43:38 by iltafah           #+#    #+#             */
/*   Updated: 2020/10/23 10:43:40 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	calculate_rayside(t_vals *vals)
{
	vals->ray.x_deltadist = fabs(1 / vals->ray.x_dir);
	vals->ray.y_deltadist = fabs(1 / vals->ray.y_dir);
	if (vals->ray.x_dir < 0)
		vals->ray.x_sidedist = vals->plyr.x_pos - vals->plyr.x_square;
	else
		vals->ray.x_sidedist = vals->plyr.x_square + 1.0 - vals->plyr.x_pos;
	if (vals->ray.y_dir < 0)
		vals->ray.y_sidedist = vals->plyr.y_pos - vals->plyr.y_square;
	else
		vals->ray.y_sidedist = vals->plyr.y_square + 1.0 - vals->plyr.y_pos;
	vals->ray.x_sidedist *= vals->ray.x_deltadist;
	vals->ray.y_sidedist *= vals->ray.y_deltadist;
	vals->ray.x_step = vals->ray.x_dir < 0 ? -1 : 1;
	vals->ray.y_step = vals->ray.y_dir < 0 ? -1 : 1;
}

void	dda_loop(t_vals *vals)
{
	int		hit;

	hit = 0;
	while (hit == 0)
	{
		if (vals->ray.x_sidedist < vals->ray.y_sidedist)
		{
			vals->ray.x_sidedist += vals->ray.x_deltadist;
			vals->plyr.x_square += vals->ray.x_step;
			vals->ray.hit_side = 0;
		}
		else
		{
			vals->ray.y_sidedist += vals->ray.y_deltadist;
			vals->plyr.y_square += vals->ray.y_step;
			vals->ray.hit_side = 1;
		}
		if (g_map[vals->plyr.x_square][vals->plyr.y_square] == '1')
			hit = 1;
	}
}

void	calculate_perpendicular_distance_of_wall_hit(t_vals *vals)
{
	if (vals->ray.hit_side == 0)
	{
		vals->ray.perp_dist = vals->plyr.x_square - vals->plyr.x_pos;
		vals->ray.perp_dist += (1 - vals->ray.x_step) / 2;
		vals->ray.perp_dist /= vals->ray.x_dir;
	}
	else
	{
		vals->ray.perp_dist = vals->plyr.y_square - vals->plyr.y_pos;
		vals->ray.perp_dist += (1 - vals->ray.y_step) / 2;
		vals->ray.perp_dist /= vals->ray.y_dir;
	}
}

void	store_data(t_vals *vals, int x_screen)
{
	int		y_start;
	int		y_end;
	int		color;
	int		*wall_data;

	texture_calculation(vals, &y_start, &y_end);
	wall_data = vals->img.loaded_tex[vals->img.tex_index];
	while (y_start < y_end)
	{
		vals->img.y = (int)vals->img.texpos &
		(vals->img.tex_height[vals->img.tex_index] - 1);
		vals->img.texpos += vals->img.step;
		color = wall_data[vals->img.tex_height[vals->img.tex_index]
		* vals->img.y + vals->img.x];
		vals->img.data[g_win_w * y_start + x_screen] = color;
		y_start++;
	}
}

void	draw_walls(t_vals *vals)
{
	int				x_screen;
	double			x_cam;

	x_screen = -1;
	vals->sprite.z_wall_distance = malloc(sizeof(double) * g_win_w);
	while (++x_screen < g_win_w)
	{
		x_cam = 2 * x_screen / (double)g_win_w - 1;
		vals->ray.x_dir = vals->plyr.x_dir + vals->cam.x_plane * x_cam;
		vals->ray.y_dir = vals->plyr.y_dir + vals->cam.y_plane * x_cam;
		vals->plyr.x_square = (int)vals->plyr.x_pos;
		vals->plyr.y_square = (int)vals->plyr.y_pos;
		calculate_rayside(vals);
		dda_loop(vals);
		calculate_perpendicular_distance_of_wall_hit(vals);
		store_data(vals, x_screen);
		vals->sprite.z_wall_distance[x_screen] = vals->ray.perp_dist;
	}
}

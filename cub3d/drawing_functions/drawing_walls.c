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
	RAY.x_deltadist = fabs(1 / RAY.x_dir);
	RAY.y_deltadist = fabs(1 / RAY.y_dir);
	if (RAY.x_dir < 0)
		RAY.x_sidedist = PLYR.x_pos - PLYR.x_square;
	else
		RAY.x_sidedist = PLYR.x_square + 1.0 - PLYR.x_pos;
	if (RAY.y_dir < 0)
		RAY.y_sidedist = PLYR.y_pos - PLYR.y_square;
	else
		RAY.y_sidedist = PLYR.y_square + 1.0 - PLYR.y_pos;
	RAY.x_sidedist *= RAY.x_deltadist;
	RAY.y_sidedist *= RAY.y_deltadist;
	RAY.x_step = RAY.x_dir < 0 ? -1 : 1;
	RAY.y_step = RAY.y_dir < 0 ? -1 : 1;
}

void	dda_loop(t_vals *vals)
{
	int		hit;

	hit = 0;
	while (hit == 0)
	{
		if (RAY.x_sidedist < RAY.y_sidedist)
		{
			RAY.x_sidedist += RAY.x_deltadist;
			PLYR.x_square += RAY.x_step;
			RAY.hit_side = 0;
		}
		else
		{
			RAY.y_sidedist += RAY.y_deltadist;
			PLYR.y_square += RAY.y_step;
			RAY.hit_side = 1;
		}
		if (g_map[PLYR.x_square][PLYR.y_square] == '1')
			hit = 1;
	}
}

void	calculate_perpendicular_distance_of_wall_hit(t_vals *vals)
{
	if (RAY.hit_side == 0)
	{
		RAY.perp_dist = PLYR.x_square - PLYR.x_pos;
		RAY.perp_dist += (1 - RAY.x_step) / 2;
		RAY.perp_dist /= RAY.x_dir;
	}
	else
	{
		RAY.perp_dist = PLYR.y_square - PLYR.y_pos;
		RAY.perp_dist += (1 - RAY.y_step) / 2;
		RAY.perp_dist /= RAY.y_dir;
	}
}

void	store_data(t_vals *vals, int x_screen)
{
	int		y_start;
	int		y_end;
	int		color;
	int		*wall_data;

	texture_calculation(vals, &y_start, &y_end);
	wall_data = IMG.loaded_tex[IMG.tex_index];
	while (y_start < y_end)
	{
		IMG.y = (int)IMG.texpos & (IMG.tex_height[IMG.tex_index] - 1);
		IMG.texpos += IMG.step;
		color = wall_data[IMG.tex_height[IMG.tex_index] * IMG.y + IMG.x];
		IMG.data[g_win_width * y_start + x_screen] = color;
		y_start++;
	}
}

void	draw_walls(t_vals *vals)
{
	int				x_screen;
	double			x_cam;

	x_screen = -1;
	SPRITE.z_wall_distance = malloc(sizeof(double) * g_win_width);
	while (++x_screen < g_win_width)
	{
		x_cam = 2 * x_screen / (double)g_win_width - 1;
		RAY.x_dir = PLYR.x_dir + CAM.x_plane * x_cam;
		RAY.y_dir = PLYR.y_dir + CAM.y_plane * x_cam;
		PLYR.x_square = (int)PLYR.x_pos;
		PLYR.y_square = (int)PLYR.y_pos;
		calculate_rayside(vals);
		dda_loop(vals);
		calculate_perpendicular_distance_of_wall_hit(vals);
		store_data(vals, x_screen);
		SPRITE.z_wall_distance[x_screen] = RAY.perp_dist;
	}
}

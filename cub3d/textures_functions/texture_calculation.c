/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_calculation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 11:17:04 by iltafah           #+#    #+#             */
/*   Updated: 2020/10/23 11:17:05 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	calculate_x_wall_ray_hit(t_vals *vals, double *wall_x_hit)
{
	if (RAY.hit_side == 0)
		*wall_x_hit = PLYR.y_pos + RAY.perp_dist * RAY.y_dir;
	else
		*wall_x_hit = PLYR.x_pos + RAY.perp_dist * RAY.x_dir;
	*wall_x_hit -= floor((*wall_x_hit));
}

void	which_tex_index(t_vals *vals)
{
	if (RAY.hit_side == 0 && RAY.x_dir > 0)
	{
		IMG.tex_index = 0;
		IMG.x = IMG.tex_width[0] - IMG.x - 1;
	}
	if (RAY.hit_side == 1 && RAY.y_dir < 0)
	{
		IMG.tex_index = 1;
		IMG.x = IMG.tex_width[1] - IMG.x - 1;
	}
	if (RAY.hit_side == 0 && RAY.x_dir < 0)
		IMG.tex_index = 2;
	if (RAY.hit_side == 1 && RAY.y_dir > 0)
		IMG.tex_index = 3;
}

void	calculate_line_height(t_vals *vals, int *y_start, int *y_end)
{
	IMG.line_height = (int)(g_win_height / RAY.perp_dist);
	*y_start = -IMG.line_height / 2 + g_win_height / 2;
	if (*y_start < 0)
		*y_start = 0;
	*y_end = IMG.line_height / 2 + g_win_height / 2;
	if (*y_end >= g_win_height)
		*y_end = g_win_height - 1;
}

void	texture_calculation(t_vals *vals, int *y_start, int *y_end)
{
	int		line_height;
	double	wall_x_hit;
	double	x_ray_dir;
	double	y_ray_dir;

	line_height = IMG.line_height;
	x_ray_dir = RAY.x_dir;
	y_ray_dir = RAY.y_dir;
	calculate_x_wall_ray_hit(vals, &wall_x_hit);
	which_tex_index(vals);
	IMG.x = (int)(wall_x_hit * (double)(IMG.tex_width[IMG.tex_index]));
	calculate_line_height(vals, y_start, y_end);
	IMG.step = 1.0 * IMG.tex_height[IMG.tex_index] / line_height;
	IMG.texpos = *y_start - g_win_height / 2 + line_height / 2;
	IMG.texpos *= IMG.step;
}

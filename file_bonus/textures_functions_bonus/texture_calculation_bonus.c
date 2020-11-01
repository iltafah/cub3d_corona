/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_calculation_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 11:17:04 by iltafah           #+#    #+#             */
/*   Updated: 2020/11/01 14:09:28 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	calculate_x_wall_ray_hit(t_vals *vals, double *wall_x_hit)
{
	if (vals->ray.hit_side == 0)
		*wall_x_hit = vals->plyr.y_pos + vals->ray.perp_dist * vals->ray.y_dir;
	else
		*wall_x_hit = vals->plyr.x_pos + vals->ray.perp_dist * vals->ray.x_dir;
	*wall_x_hit -= floor((*wall_x_hit));
}

void	which_tex_index(t_vals *vals)
{
	if (vals->ray.hit_side == 0 && vals->ray.x_dir > 0)
	{
		vals->img.tex_index = 1;
		vals->img.x = vals->img.tex_width[0] - vals->img.x - 1;
	}
	if (vals->ray.hit_side == 1 && vals->ray.y_dir < 0)
	{
		vals->img.tex_index = 3;
		vals->img.x = vals->img.tex_width[1] - vals->img.x - 1;
	}
	if (vals->ray.hit_side == 0 && vals->ray.x_dir < 0)
		vals->img.tex_index = 0;
	if (vals->ray.hit_side == 1 && vals->ray.y_dir > 0)
		vals->img.tex_index = 2;
}

void	calculate_line_height(t_vals *vals, int *y_start, int *y_end)
{
	vals->img.line_height = (int)(g_win_h / vals->ray.perp_dist);
	*y_start = -vals->img.line_height / 2 + g_win_h / 2;
	if (*y_start < 0)
		*y_start = 0;
	*y_end = vals->img.line_height / 2 + g_win_h / 2;
	if (*y_end >= g_win_h)
		*y_end = g_win_h - 1;
}

void	texture_calculation(t_vals *vals, int *y_start, int *y_end)
{
	int		line_height;
	double	wall_x_hit;
	double	x_ray_dir;
	double	y_ray_dir;

	x_ray_dir = vals->ray.x_dir;
	y_ray_dir = vals->ray.y_dir;
	calculate_x_wall_ray_hit(vals, &wall_x_hit);
	which_tex_index(vals);
	vals->img.x =
	(int)(wall_x_hit * (double)(vals->img.tex_width[vals->img.tex_index]));
	calculate_line_height(vals, y_start, y_end);
	line_height = vals->img.line_height;
	vals->img.step =
	1.0 * vals->img.tex_height[vals->img.tex_index] / line_height;
	vals->img.texpos = *y_start - g_win_h / 2 + line_height / 2;
	vals->img.texpos *= vals->img.step;
}

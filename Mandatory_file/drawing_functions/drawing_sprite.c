/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 10:58:12 by iltafah           #+#    #+#             */
/*   Updated: 2020/11/01 14:08:58 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void			calculate_sprite_width_height(t_vals *vals, double y_trans)
{
	vals->sprite.height = abs((int)(g_win_h / (y_trans)));
	vals->sprite.y_start = -vals->sprite.height / 2 + g_win_h / 2;
	if (vals->sprite.y_start < 0)
		vals->sprite.y_start = 0;
	vals->sprite.y_end = vals->sprite.height / 2 + g_win_h / 2;
	if (vals->sprite.y_end >= g_win_h)
		vals->sprite.y_end = g_win_h - 1;
	vals->sprite.width = abs((int)(g_win_h / (y_trans)));
	vals->sprite.x_start = -vals->sprite.width / 2 + vals->sprite.x_screen;
	if (vals->sprite.x_start < 0)
		vals->sprite.x_start = 0;
	vals->sprite.x_end = vals->sprite.width / 2 + vals->sprite.x_screen;
	if (vals->sprite.x_end >= g_win_w)
		vals->sprite.x_end = g_win_w - 1;
}

void			calculate_tex_x(t_vals *vals, int *tex_x)
{
	*tex_x = (256 * (vals->sprite.x_start -
	(vals->sprite.x_screen - vals->sprite.width / 2)));
	*tex_x = ((*tex_x * vals->img.tex_width[4]) / vals->sprite.width) / 256;
}

int				check_conditions(t_vals *vals, double y_trans)
{
	return (y_trans > 0 && vals->sprite.x_start > 0
	&& vals->sprite.x_start < g_win_w
	&& y_trans < vals->sprite.z_wall_distance[vals->sprite.x_start]);
}

void			store_sprite_data(t_vals *vals, double y_trans)
{
	long int	color;
	int			tex_x;
	int			tex_y;
	int			y;
	int			d;

	while (vals->sprite.x_start < vals->sprite.x_end)
	{
		calculate_tex_x(vals, &tex_x);
		if (check_conditions(vals, y_trans))
		{
			y = vals->sprite.y_start - 1;
			while (++y < vals->sprite.y_end)
			{
				d = y * 256 - g_win_h * 128 + vals->sprite.height * 128;
				tex_y = (int)((d * vals->img.tex_height[4]) /
				vals->sprite.height) / 256;
				color =
				vals->img.loaded_tex[4][vals->img.tex_width[4] * tex_y + tex_x];
				if ((color & 0x00FFFFFF) != 0)
					vals->img.data[g_win_w * y + vals->sprite.x_start] = color;
			}
		}
		vals->sprite.x_start++;
	}
}

void			draw_sprite(t_vals *vals)
{
	double		x_sprite_plyr;
	double		y_sprite_plyr;
	double		x_trans;
	double		y_trans;
	double		invdet;

	x_sprite_plyr = vals->sprite.x_pos - vals->plyr.x_pos;
	y_sprite_plyr = vals->sprite.y_pos - vals->plyr.y_pos;
	invdet = 1.0 / (vals->cam.x_plane * vals->plyr.y_dir -
	vals->plyr.x_dir * vals->cam.y_plane);
	x_trans = (vals->plyr.y_dir * x_sprite_plyr -
	vals->plyr.x_dir * y_sprite_plyr);
	y_trans = (-vals->cam.y_plane * x_sprite_plyr +
	vals->cam.x_plane * y_sprite_plyr);
	x_trans *= invdet;
	y_trans *= invdet;
	vals->sprite.x_screen = (int)(g_win_w / 2 * (1 + x_trans / y_trans));
	calculate_sprite_width_height(vals, y_trans);
	store_sprite_data(vals, y_trans);
	free(vals->sprite.z_wall_distance);
}

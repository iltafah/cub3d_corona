/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 10:58:12 by iltafah           #+#    #+#             */
/*   Updated: 2020/10/16 10:49:22 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void			calculate_sprite_width_height(t_vals *vals, double y_trans)
{
	SPRITE.height = abs((int)(g_win_height / (y_trans)));
	SPRITE.y_start = -SPRITE.height / 2 + g_win_height / 2;
	if (SPRITE.y_start < 0)
		SPRITE.y_start = 0;
	SPRITE.y_end = SPRITE.height / 2 + g_win_height / 2;
	if (SPRITE.y_end >= g_win_height)
		SPRITE.y_end = g_win_height - 1;
	SPRITE.width = abs((int)(g_win_height / (y_trans)));
	SPRITE.x_start = -SPRITE.width / 2 + SPRITE.x_screen;
	if (SPRITE.x_start < 0)
		SPRITE.x_start = 0;
	SPRITE.x_end = SPRITE.width / 2 + SPRITE.x_screen;
	if (SPRITE.x_end >= g_win_width)
		SPRITE.x_end = g_win_width - 1;
}

void			store_sprite_data(t_vals *vals, double y_trans)
{
	long int	color;
	int			tex_x;
	int			tex_y;
	int			y;
	int			d;

	while (SPRITE.x_start < SPRITE.x_end)
	{
		tex_x = (256 * (SPRITE.x_start - (SPRITE.x_screen - SPRITE.width / 2)));
		tex_x = ((tex_x * IMG.tex_width[4]) / SPRITE.width) / 256;
		if (y_trans > 0 && SPRITE.x_start > 0 && SPRITE.x_start < g_win_width
		&& y_trans < SPRITE.z_wall_distance[SPRITE.x_start])
		{
			y = SPRITE.y_start - 1;
			while (++y < SPRITE.y_end)
			{
				d = y * 256 - g_win_height * 128 + SPRITE.height * 128;
				tex_y = (int)((d * IMG.tex_height[4]) / SPRITE.height) / 256;
				color = IMG.loaded_tex[4][IMG.tex_width[4] * tex_y + tex_x];
				if ((color & 0x00FFFFFF) != 0)
					IMG.data[g_win_width * y + SPRITE.x_start] = color;
			}
		}
		SPRITE.x_start++;
	}
}

void			draw_sprite(t_vals *vals)
{
	double		x_sprite_plyr;
	double		y_sprite_plyr;
	double		x_trans;
	double		y_trans;
	double		invdet;

	x_sprite_plyr = SPRITE.x_pos - PLYR.x_pos;
	y_sprite_plyr = SPRITE.y_pos - PLYR.y_pos;
	invdet = 1.0 / (CAM.x_plane * PLYR.y_dir - PLYR.x_dir * CAM.y_plane);
	x_trans = (PLYR.y_dir * x_sprite_plyr - PLYR.x_dir * y_sprite_plyr);
	y_trans = (-CAM.y_plane * x_sprite_plyr + CAM.x_plane * y_sprite_plyr);
	x_trans *= invdet;
	y_trans *= invdet;
	SPRITE.x_screen = (int)(g_win_width / 2 * (1 + x_trans / y_trans));
	calculate_sprite_width_height(vals, y_trans);
	store_sprite_data(vals, y_trans);
	free(SPRITE.z_wall_distance);
}

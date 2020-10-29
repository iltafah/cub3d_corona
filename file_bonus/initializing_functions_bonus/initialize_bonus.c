/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 00:20:04 by iltafah           #+#    #+#             */
/*   Updated: 2020/10/29 13:39:24 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	initialize_cubfile(t_vals *vals)
{
	vals->cubfile.screen_width = 0;
	vals->cubfile.screen_height = 0;
	vals->cubfile.north_tex = 0;
	vals->cubfile.south_tex = 0;
	vals->cubfile.east_tex = 0;
	vals->cubfile.west_tex = 0;
	vals->cubfile.sprite_tex = 0;
	vals->cubfile.floor_color = 0;
	vals->cubfile.cell_color = 0;
	vals->cubfile.keep = 0;
	vals->cubfile.error = 0;
	vals->cubfile.total = 0;
	vals->cubfile.world_map = 0;
}

void	initialize_mlx(t_vals *vals)
{
	vals->mlx.ptr = 0;
	vals->mlx.win_ptr = 0;
	vals->mlx.error = 0;
}

void	initialize_cam(t_vals *vals)
{
	vals->cam.x = 0;
	vals->cam.x_plane = 0;
	vals->cam.y_plane = 0;
}

void	initialize_global_variables(t_vals *vals)
{
	g_win_h = vals->cubfile.screen_height;
	if (g_win_h > 1440)
		g_win_h = 1440;
	g_win_w = vals->cubfile.screen_width;
	if (g_win_w > 2560)
		g_win_w = 2560;
	g_map = vals->cubfile.world_map;
	g_mlx_ptr = mlx_init();
	if (g_mlx_ptr)
	{
		g_mlx_win = mlx_new_window(g_mlx_ptr, g_win_w, g_win_h, "noize");
		if (g_mlx_win == NULL)
			vals->mlx.error = 2;
	}
	else
		vals->mlx.error = 1;
}

void	initialize_struct(t_vals *vals)
{
	initialize_cubfile(vals);
	initialize_mlx(vals);
	initialize_cam(vals);
	initialize_plyr(vals);
	initialize_ray(vals);
	initialize_keys(vals);
}

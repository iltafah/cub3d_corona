/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 00:20:04 by iltafah           #+#    #+#             */
/*   Updated: 2020/03/15 01:52:11 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
}

void	initialize_cam(t_vals *vals)
{
	vals->cam.x = 0;
	vals->cam.x_plane = 0;
	vals->cam.y_plane = 0;
}

void	initialize_global_variables(t_vals *vals)
{
	g_win_height = CUBFILE.screen_height;
	g_win_width = CUBFILE.screen_width;
	g_map = CUBFILE.world_map;
	g_mlx_ptr = mlx_init();
	g_mlx_win = mlx_new_window(g_mlx_ptr, g_win_width, g_win_height, "noize");
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
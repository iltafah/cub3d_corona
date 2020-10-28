/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 11:16:56 by iltafah           #+#    #+#             */
/*   Updated: 2020/10/28 13:49:57 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	load_north_tex(t_vals *vals, int bpp, int size_line, int endian)
{
	int		w;
	int		h;

	vals->img.ptr_to_loaded_tex[0] =
	mlx_xpm_file_to_image(g_mlx_ptr, vals->cubfile.north_tex, &w, &h);
	if (vals->img.ptr_to_loaded_tex == NULL)
	{
		vals->img.tex_width[0] = w;
		vals->img.tex_height[0] = h;
		vals->img.loaded_tex[0] =
		(int *)mlx_get_data_addr(vals->img.ptr_to_loaded_tex[0], &bpp,
		&size_line, &endian);
	}
	else
		vals->mlx.error = 3;
}

void	load_south_tex(t_vals *vals, int bpp, int size_line, int endian)
{
	int		w;
	int		h;

	vals->img.ptr_to_loaded_tex[1] =
	mlx_xpm_file_to_image(g_mlx_ptr, vals->cubfile.south_tex, &w, &h);
	if (vals->img.ptr_to_loaded_tex == NULL)
	{
		vals->img.tex_width[1] = w;
		vals->img.tex_height[1] = h;
		vals->img.loaded_tex[1] =
		(int *)mlx_get_data_addr(vals->img.ptr_to_loaded_tex[1], &bpp,
		&size_line, &endian);
	}
	else
		vals->mlx.error = 3;
}

void	load_east_tex(t_vals *vals, int bpp, int size_line, int endian)
{
	int		w;
	int		h;

	vals->img.ptr_to_loaded_tex[2] =
	mlx_xpm_file_to_image(g_mlx_ptr, vals->cubfile.east_tex, &w, &h);
	if (vals->img.ptr_to_loaded_tex == NULL)
	{
		vals->img.tex_width[2] = w;
		vals->img.tex_height[2] = h;
		vals->img.loaded_tex[2] =
		(int *)mlx_get_data_addr(vals->img.ptr_to_loaded_tex[2], &bpp,
		&size_line, &endian);
	}
	else
		vals->mlx.error = 3;
}

void	load_west_tex(t_vals *vals, int bpp, int size_line, int endian)
{
	int		w;
	int		h;

	vals->img.ptr_to_loaded_tex[3] =
	mlx_xpm_file_to_image(g_mlx_ptr, vals->cubfile.west_tex, &w, &h);
	if (vals->img.ptr_to_loaded_tex == NULL)
	{
		vals->img.tex_width[3] = w;
		vals->img.tex_height[3] = h;
		vals->img.loaded_tex[3] =
		(int *)mlx_get_data_addr(vals->img.ptr_to_loaded_tex[3], &bpp,
		&size_line, &endian);
	}
	else
		vals->mlx.error = 3;
}

void	load_sprite_tex(t_vals *vals, int bpp, int size_line, int endian)
{
	int		w;
	int		h;

	vals->img.ptr_to_loaded_tex[4] =
	mlx_xpm_file_to_image(g_mlx_ptr, vals->cubfile.sprite_tex, &w, &h);
	if (vals->img.ptr_to_loaded_tex == NULL)
	{
		vals->img.tex_width[4] = w;
		vals->img.tex_height[4] = h;
		vals->img.loaded_tex[4] =
		(int *)mlx_get_data_addr(vals->img.ptr_to_loaded_tex[4], &bpp,
		&size_line, &endian);
	}
	else
		vals->mlx.error = 3;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 11:16:56 by iltafah           #+#    #+#             */
/*   Updated: 2020/10/23 11:16:58 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	load_north_tex(t_vals *vals, int bpp, int size_line, int endian)
{
	int		w;
	int		h;

	IMG.ptr_to_loaded_tex[0] =
	mlx_xpm_file_to_image(g_mlx_ptr, CUBFILE.north_tex, &w, &h);
	IMG.tex_width[0] = w;
	IMG.tex_height[0] = h;
	IMG.loaded_tex[0] = (int *)mlx_get_data_addr(IMG.ptr_to_loaded_tex[0], &bpp,
	&size_line, &endian);
}

void	load_south_tex(t_vals *vals, int bpp, int size_line, int endian)
{
	int		w;
	int		h;

	IMG.ptr_to_loaded_tex[1] =
	mlx_xpm_file_to_image(g_mlx_ptr, CUBFILE.south_tex, &w, &h);
	IMG.tex_width[1] = w;
	IMG.tex_height[1] = h;
	IMG.loaded_tex[1] = (int *)mlx_get_data_addr(IMG.ptr_to_loaded_tex[1], &bpp,
	&size_line, &endian);
}

void	load_east_tex(t_vals *vals, int bpp, int size_line, int endian)
{
	int		w;
	int		h;

	IMG.ptr_to_loaded_tex[2] =
	mlx_xpm_file_to_image(g_mlx_ptr, CUBFILE.east_tex, &w, &h);
	IMG.tex_width[2] = w;
	IMG.tex_height[2] = h;
	IMG.loaded_tex[2] = (int *)mlx_get_data_addr(IMG.ptr_to_loaded_tex[2], &bpp,
	&size_line, &endian);
}

void	load_west_tex(t_vals *vals, int bpp, int size_line, int endian)
{
	int		w;
	int		h;

	IMG.ptr_to_loaded_tex[3] =
	mlx_xpm_file_to_image(g_mlx_ptr, CUBFILE.west_tex, &w, &h);
	IMG.tex_width[3] = w;
	IMG.tex_height[3] = h;
	IMG.loaded_tex[3] = (int *)mlx_get_data_addr(IMG.ptr_to_loaded_tex[3], &bpp,
	&size_line, &endian);
}

void	load_sprite_tex(t_vals *vals, int bpp, int size_line, int endian)
{
	int		w;
	int		h;

	IMG.ptr_to_loaded_tex[4] =
	mlx_xpm_file_to_image(g_mlx_ptr, CUBFILE.sprite_tex, &w, &h);
	IMG.tex_width[4] = w;
	IMG.tex_height[4] = h;
	IMG.loaded_tex[4] = (int *)mlx_get_data_addr(IMG.ptr_to_loaded_tex[4], &bpp,
	&size_line, &endian);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 23:48:50 by iltafah           #+#    #+#             */
/*   Updated: 2020/11/03 09:02:26 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	create_screen_img(t_vals *vals)
{
	int		pix;
	int		line;
	int		endian;

	vals->img.ptr = mlx_new_image(g_mlx_ptr, g_win_w, g_win_h);
	if (vals->img.ptr)
		vals->img.data =
		(int*)mlx_get_data_addr(vals->img.ptr, &pix, &line, &endian);
	else
		vals->mlx.error = 4;
}

void	load_textures(t_vals *vals)
{
	int		bpp;
	int		size_line;
	int		endian;
	int		error_count;

	bpp = 0;
	size_line = 0;
	endian = 0;
	error_count = 0;
	vals->img.ptr_to_loaded_tex = malloc(sizeof(void*) * 5);
	vals->img.loaded_tex = malloc(sizeof(int*) * 5);
	vals->img.tex_width = malloc(sizeof(int) * 5);
	vals->img.tex_height = malloc(sizeof(int) * 5);
	load_north_tex(vals, bpp, size_line, endian);
	load_south_tex(vals, bpp, size_line, endian);
	load_east_tex(vals, bpp, size_line, endian);
	load_west_tex(vals, bpp, size_line, endian);
	load_sprite_tex(vals, bpp, size_line, endian);
}

void	handel_hook(t_vals *vals, int screen_shot)
{
	if (!check_whether_there_are_errors_or_not(vals))
	{
		if (screen_shot)
			take_screen_shot(vals);
		else
		{
			mlx_hook(g_mlx_win, 2, (1L << 0), key_pressed, vals);
			mlx_hook(g_mlx_win, 3, (1L << 1), key_released, vals);
			mlx_loop_hook(g_mlx_ptr, update, vals);
			mlx_hook(g_mlx_win, 17, 0, exit_function, vals);
			mlx_loop(g_mlx_ptr);
		}
	}
}

int		open_cub_file(t_vals *vals, char *str, int *fd)
{
	*fd = open(str, O_RDONLY);
	if (*fd == -1)
	{
		ft_putstr("Error\nNo such file\n");
		close(*fd);
		return (*fd);
	}
	return (check_extension(vals, str, "cub", fd));
}

int		main(int argc, char **argv)
{
	t_vals	vals;
	int		screen_shot;
	int		fd;

	if (argc > 1 && argc <= 3)
	{
		screen_shot = 0;
		if ((open_cub_file(&vals, argv[1], &fd)) == -1)
			return (0);
		if (argc == 3 && !check_option(argv[2], fd, &screen_shot))
			return (0);
		initialize_struct(&vals);
		handel_cubfile(fd, &vals);
		close(fd);
		if (check_whether_there_are_errors_or_not(&vals))
			return (0);
		initialize_global_variables(&vals);
		set_plyr_position(&vals);
		set_sprite_position(&vals);
		load_textures(&vals);
		handel_hook(&vals, screen_shot);
	}
	else
		check_arguments(argc);
	return (0);
}

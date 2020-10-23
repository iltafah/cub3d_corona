/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 23:48:50 by iltafah           #+#    #+#             */
/*   Updated: 2020/10/14 09:15:58 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	create_screen_img(t_vals *vals)
{
	int		pix;
	int		line;
	int		endian;

	IMG.ptr = mlx_new_image(g_mlx_ptr, g_win_width, g_win_height);
	IMG.data = (int*)mlx_get_data_addr(IMG.ptr, &pix, &line, &endian);
}

void	load_textures(t_vals *vals)
{
	int		bpp;
	int		size_line;
	int		endian;
	int		error_count;

	error_count = 0;
	IMG.ptr_to_loaded_tex = malloc(sizeof(void*) * 5);
	IMG.loaded_tex = malloc(sizeof(int*) * 5);
	IMG.tex_width = malloc(sizeof(int) * 5);
	IMG.tex_height = malloc(sizeof(int) * 5);
	load_north_tex(vals, bpp, size_line, endian);
	load_south_tex(vals, bpp, size_line, endian);
	load_east_tex(vals, bpp, size_line, endian);
	load_west_tex(vals, bpp, size_line, endian);
	load_sprite_tex(vals, bpp, size_line, endian);
}

void	handel_hook(t_vals *vals, int screenshot)
{
	if (screenshot)
		screen_shot(vals);
	else
	{
		mlx_hook(g_mlx_win, 2, (1L << 0), key_pressed, vals);
		mlx_hook(g_mlx_win, 3, (1L << 1), key_released, vals);
		mlx_loop_hook(g_mlx_ptr, update, vals);
		mlx_hook(g_mlx_win, 17, 0, exit_function, vals);
		mlx_loop(g_mlx_ptr);
	}
}

int		main(int argc, char **argv)
{
	t_vals	vals;
	int		screenshot;
	int		fd;

	if (argc > 1 && argc <= 3)
	{
		screenshot = 0;
		if (argc == 3)
		{
			if (!ft_strcmp("--save", argv[2]))
				screenshot = 1;
			else
			{
				ft_putstr("illegal option ");
				ft_putstr(argv[2]);
				return (0);
			}
		}

		initialize_struct(&vals);
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			ft_putstr("Error\nNo such file\n");
			close(fd);
			return (0);
		}
		handel_cubfile(fd, &vals);
		close(fd);

		if (vals.cubfile.error == 1)
		{
			if (vals.cubfile.world_map)
				free_ptrs_to_str(&vals.cubfile.world_map);
			return (0);
		}
		initialize_global_variables(&vals);
		set_plyr_position(&vals);
		set_sprite_position(&vals);
		/*///////////////////////////////////////////////////////////////////////////////
		printf("%d   %d\n",vals.cubfile.screen_width,vals.cubfile.screen_height);//
		printf("%s\n",vals.cubfile.north_tex);									 //
		printf("%s\n",vals.cubfile.south_tex);								     //
		printf("%s\n",vals.cubfile.east_tex);									     //
		printf("%s\n",vals.cubfile.west_tex);								         //
		printf("%s\n",vals.cubfile.sprite_tex);								     //
		printf("%ld\n",vals.cubfile.floor_color);									 //
		printf("%ld\n",vals.cubfile.cell_color);									 //
		char **ptr = vals.cubfile.world_map;										 //
		for (int i = 0; ptr[i]; i++)												 //
		{																			 //
			ft_putstr(ptr[i]);														 //
			ft_putstr("\n");														 //
		}																			 //
		///////////////////////////////////////////////////////////////////////////////*/
		load_textures(&vals);
		handel_hook(&vals, screenshot);
	}
	else if (argc > 3)
		ft_putstr("so much arguments\n");
	else
		ft_putstr("no map selected\n");
	return (0);
}

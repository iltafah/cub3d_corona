/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_manager_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 10:50:15 by iltafah           #+#    #+#             */
/*   Updated: 2020/10/29 13:36:15 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int		update(t_vals *vals)
{
	create_screen_img(vals);
	if (vals->mlx.error)
		return (0);
	draw_cell(vals);
	draw_floor(vals);
	draw_walls(vals);
	draw_sprite(vals);
	mlx_clear_window(g_mlx_ptr, g_mlx_win);
	mlx_put_image_to_window(g_mlx_ptr, g_mlx_win, vals->img.ptr, 0, 0);
	mlx_destroy_image(g_mlx_ptr, vals->img.ptr);
	vals->img.ptr = NULL;
	move_plyr(vals);
	return (0);
}

int		take_screen_shot(t_vals *vals)
{
	create_screen_img(vals);
	if (vals->mlx.error)
		return (0);
	draw_cell(vals);
	draw_floor(vals);
	draw_walls(vals);
	draw_sprite(vals);
	screen_it(vals);
	mlx_destroy_image(g_mlx_ptr, vals->img.ptr);
	vals->img.ptr = NULL;
	return (0);
}

int		exit_function(t_vals *vals)
{
	int i;

	i = -1;
	while (++i < 5)
		mlx_destroy_image(g_mlx_ptr, vals->img.ptr_to_loaded_tex[i]);
	free(vals->img.ptr_to_loaded_tex);
	vals->img.ptr_to_loaded_tex = NULL;
	free(vals->img.loaded_tex);
	vals->img.loaded_tex = NULL;
	free(vals->img.tex_width);
	vals->img.tex_width = 0;
	free(vals->img.tex_height);
	vals->img.tex_height = 0;
	exit(0);
	mlx_destroy_window(vals->mlx.ptr, vals->mlx.win_ptr);
	free_ptrs_to_str(&vals->cubfile.world_map);
	i = 1;
	while (++i <= 6)
		free_str((char**)which_adresse(i, vals));
	return (0);
}

int		key_pressed(int key, t_vals *vals)
{
	if (key == 13)
		vals->keys.forward = 1;
	if (key == 1)
		vals->keys.backward = 1;
	if (key == 2)
		vals->keys.right = 1;
	if (key == 0)
		vals->keys.left = 1;
	if (key == 124)
		vals->keys.right_rotate = 1;
	if (key == 123)
		vals->keys.left_rotate = 1;
	if (key == 53)
		exit_function(vals);
	return (0);
}

int		key_released(int key, t_vals *vals)
{
	if (key == 13)
		vals->keys.forward = 0;
	if (key == 1)
		vals->keys.backward = 0;
	if (key == 2)
		vals->keys.right = 0;
	if (key == 0)
		vals->keys.left = 0;
	if (key == 124)
		vals->keys.right_rotate = 0;
	if (key == 123)
		vals->keys.left_rotate = 0;
	return (0);
}

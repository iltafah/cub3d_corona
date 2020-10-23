#include "cub3d.h"

int		update(t_vals *vals)
{
	create_screen_img(vals);
	draw_cell(vals);
	draw_floor(vals);
	draw_walls(vals);
	draw_sprite(vals);
	mlx_clear_window(g_mlx_ptr, g_mlx_win);
	mlx_put_image_to_window(g_mlx_ptr, g_mlx_win, IMG.ptr, 0, 0);
	mlx_destroy_image(g_mlx_ptr, IMG.ptr);
	IMG.ptr = NULL;
	move_plyr(vals);
	return (0);
}

int		screen_shot(t_vals *vals)
{
	create_screen_img(vals);
	draw_cell(vals);
	draw_floor(vals);
	draw_walls(vals);
	draw_sprite(vals);
	screen_it(vals);
	mlx_destroy_image(g_mlx_ptr, IMG.ptr);
	IMG.ptr = NULL;
	return (0);
}

int		exit_function(t_vals *vals)
{
	int i;

	i = -1;
	while (++i < 5)
		mlx_destroy_image(g_mlx_ptr, IMG.ptr_to_loaded_tex[i]);
	free(IMG.ptr_to_loaded_tex);
	IMG.ptr_to_loaded_tex = NULL;
	//////////
	free(IMG.loaded_tex);
	IMG.loaded_tex = NULL;
	///////////
	free(IMG.tex_width);
	IMG.tex_width = 0;
	free(IMG.tex_height);
	IMG.tex_height = 0;
	////////
	if (IMG.ptr)
	{
		free(IMG.ptr);
		IMG.ptr = NULL;
	}

	exit(0);
	mlx_destroy_window(vals->mlx.ptr, vals->mlx.win_ptr);
	free_ptrs_to_str(&vals->cubfile.world_map);
	return (0);
}

int		key_pressed(int key, t_vals *vals)
{
	if (key == 13)
		KEY.forward = 1;
	if (key == 1)
		KEY.backward = 1;
	if (key == 2)
		KEY.right = 1;
	if (key == 0)
		KEY.left = 1;
	if (key == 124)
		KEY.right_rotate = 1;
	if (key == 123)
		KEY.left_rotate = 1;
	if (key == 53)
		exit_function(vals);
	return (0);
}

int		key_released(int key, t_vals *vals)
{
	if (key == 13)
		KEY.forward = 0;
	if (key == 1)
		KEY.backward = 0;
	if (key == 2)
		KEY.right = 0;
	if (key == 0)
		KEY.left = 0;
	if (key == 124)
		KEY.right_rotate = 0;
	if (key == 123)
		KEY.left_rotate = 0;
	return (0);
}

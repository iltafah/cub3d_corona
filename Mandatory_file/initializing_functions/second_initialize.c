/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_initialize.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 11:05:56 by iltafah           #+#    #+#             */
/*   Updated: 2020/11/03 09:13:55 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	initialize_plyr(t_vals *vals)
{
	vals->plyr.x_dir = 0;
	vals->plyr.y_dir = 0;
	vals->plyr.x_pos = 0;
	vals->plyr.y_pos = 0;
	vals->plyr.x_square = 0;
	vals->plyr.y_square = 0;
}

void	initialize_ray(t_vals *vals)
{
	vals->ray.hit_side = 0;
	vals->ray.perp_dist = 0;
	vals->ray.x_deltadist = 0;
	vals->ray.y_deltadist = 0;
	vals->ray.x_dir = 0;
	vals->ray.y_dir = 0;
	vals->ray.x_sidedist = 0;
	vals->ray.y_sidedist = 0;
	vals->ray.x_step = 0;
	vals->ray.y_step = 0;
}

void	initialize_keys(t_vals *vals)
{
	vals->keys.forward = 0;
	vals->keys.backward = 0;
	vals->keys.right = 0;
	vals->keys.left = 0;
	vals->keys.right_rotate = 0;
	vals->keys.left_rotate = 0;
}

void	initialize_img(t_vals *vals)
{
	vals->img.ptr = 0;
	vals->img.ptr_to_loaded_tex = 0;
	vals->img.data = 0;
	vals->img.loaded_tex = 0;
	vals->img.tex_width = 0;
	vals->img.tex_height = 0;
	vals->img.tex_index = 0;
	vals->img.line_height = 0;
	vals->img.x = 0;
	vals->img.y = 0;
	vals->img.width = 0;
	vals->img.height = 0;
	vals->img.texpos = 0;
	vals->img.step = 0;
	vals->img.red = 0;
	vals->img.green = 0;
	vals->img.blue = 0;
}

void	initialize_sprite(t_vals *vals)
{
	vals->sprite.x_pos = 0;
	vals->sprite.y_pos = 0;
	vals->sprite.num_of_sprites = 0;
	vals->sprite.x_pos = 0;
	vals->sprite.y_pos = 0;
	vals->sprite.index = 0;
	vals->sprite.z_wall_distance = 0;
	vals->sprite.width = 0;
	vals->sprite.height = 0;
	vals->sprite.x_start = 0;
	vals->sprite.y_start = 0;
	vals->sprite.x_end = 0;
	vals->sprite.y_end = 0;
	vals->sprite.x_screen = 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_initialize.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 11:05:56 by iltafah           #+#    #+#             */
/*   Updated: 2020/10/23 11:05:57 by iltafah          ###   ########.fr       */
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

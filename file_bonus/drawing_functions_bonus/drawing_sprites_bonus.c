/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_sprites_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 12:47:20 by iltafah           #+#    #+#             */
/*   Updated: 2020/11/03 09:04:00 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	calculate_distance(t_vals *vals, double **distance)
{
	int		i;

	i = 0;
	*distance = malloc(sizeof(double) * vals->sprite.num_of_sprites);
	while (i < vals->sprite.num_of_sprites)
	{
		vals->sprite.index[i] = i;
		(*distance)[i] = ((vals->plyr.x_pos - vals->sprite.x_pos[i])
				* (vals->plyr.x_pos - vals->sprite.x_pos[i])) +
			((vals->plyr.y_pos - vals->sprite.y_pos[i])
			* (vals->plyr.y_pos - vals->sprite.y_pos[i]));
		i++;
	}
}

void	sort_sprites(t_vals *vals)
{
	int		i;
	int		j;
	int		keep;
	double	*distance;

	calculate_distance(vals, &distance);
	i = -1;
	while (++i < vals->sprite.num_of_sprites)
	{
		j = i + 1;
		while (j < vals->sprite.num_of_sprites)
		{
			if (distance[i] < distance[j])
			{
				keep = vals->sprite.index[i];
				vals->sprite.index[i] = vals->sprite.index[j];
				vals->sprite.index[j] = keep;
				keep = distance[i];
				distance[i] = distance[j];
				distance[j] = keep;
			}
			j++;
		}
	}
	free(distance);
}

void	draw_sprites(t_vals *vals)
{
	int		i;

	sort_sprites(vals);
	i = 0;
	while (i < vals->sprite.num_of_sprites)
	{
		draw_sprite(vals, i);
		i++;
	}
	free(vals->sprite.z_wall_distance);
}

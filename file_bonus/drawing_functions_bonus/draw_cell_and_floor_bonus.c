/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_cell_and_floor_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 10:43:18 by iltafah           #+#    #+#             */
/*   Updated: 2020/10/27 13:58:40 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	draw_cell(t_vals *vals)
{
	int		y_cell_start;
	int		y_cell_end;
	int		x;

	y_cell_start = 0;
	y_cell_end = g_win_h / 2;
	while (y_cell_start < y_cell_end)
	{
		x = 0;
		while (x < g_win_w)
		{
			vals->img.data[g_win_w * y_cell_start + x] =
			vals->cubfile.cell_color;
			x++;
		}
		y_cell_start++;
	}
}

void	draw_floor(t_vals *vals)
{
	int		y_floor_start;
	int		y_floor_end;
	int		x;

	y_floor_start = g_win_h / 2;
	y_floor_end = g_win_h;
	while (y_floor_start < y_floor_end)
	{
		x = 0;
		while (x < g_win_w)
		{
			vals->img.data[g_win_w * y_floor_start + x] =
			vals->cubfile.floor_color;
			x++;
		}
		y_floor_start++;
	}
}

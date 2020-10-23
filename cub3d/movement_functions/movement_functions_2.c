/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_functions_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 11:14:16 by iltafah           #+#    #+#             */
/*   Updated: 2020/10/23 11:14:17 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	move_forward(t_vals *vals, double *xdir, double *ydir)
{
	double	movespeed;
	double	*xpos;
	double	*ypos;

	movespeed = 0.05;
	xpos = &PLYR.x_pos;
	ypos = &PLYR.y_pos;
	if (g_map[(int)(*xpos + *xdir * movespeed)][(int)(*ypos)] == '0')
		*xpos += *xdir * movespeed;
	if (g_map[(int)(*xpos)][(int)(*ypos + *ydir * movespeed)] == '0')
		*ypos += *ydir * movespeed;
}

void	move_backward(t_vals *vals, double *xdir, double *ydir)
{
	double	movespeed;
	double	*xpos;
	double	*ypos;

	movespeed = 0.05;
	xpos = &PLYR.x_pos;
	ypos = &PLYR.y_pos;
	if (g_map[(int)(*xpos - *xdir * movespeed)][(int)(*ypos)] == '0')
		*xpos -= *xdir * movespeed;
	if (g_map[(int)(*xpos)][(int)(*ypos - *ydir * movespeed)] == '0')
		*ypos -= *ydir * movespeed;
}

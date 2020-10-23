/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_functions_1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 11:14:06 by iltafah           #+#    #+#             */
/*   Updated: 2020/10/23 11:14:08 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	move_right(t_vals *vals)
{
	double	movespeed;
	double	*xpos;
	double	*ypos;

	movespeed = 0.05;
	xpos = &PLYR.x_pos;
	ypos = &PLYR.y_pos;
	if (g_map[(int)(*xpos + CAM.x_plane * movespeed)][(int)(*ypos)] == '0')
		*xpos += CAM.x_plane * movespeed;
	if (g_map[(int)(*xpos)][(int)(*ypos + CAM.y_plane * movespeed)] == '0')
		*ypos += CAM.y_plane * movespeed;
}

void	move_left(t_vals *vals)
{
	double	movespeed;
	double	*xpos;
	double	*ypos;

	movespeed = 0.05;
	xpos = &PLYR.x_pos;
	ypos = &PLYR.y_pos;
	if (g_map[(int)(*xpos - CAM.x_plane * movespeed)][(int)(*ypos)] == '0')
		*xpos -= CAM.x_plane * movespeed;
	if (g_map[(int)(*xpos)][(int)(*ypos - CAM.y_plane * movespeed)] == '0')
		*ypos -= CAM.y_plane * movespeed;
}

void	rotate_right(double *xdir, double *ydir, double *xplane, double *yplane)
{
	double rotspeed;
	double old_value;

	rotspeed = 0.05;
	old_value = *xdir;
	*xdir = *xdir * cos(-rotspeed) - *ydir * sin(-rotspeed);
	*ydir = old_value * sin(-rotspeed) + *ydir * cos(-rotspeed);
	old_value = *xplane;
	*xplane = *xplane * cos(-rotspeed) - *yplane * sin(-rotspeed);
	*yplane = old_value * sin(-rotspeed) + *yplane * cos(-rotspeed);
}

void	rotate_left(double *xdir, double *ydir, double *xplane, double *yplane)
{
	double rotspeed;
	double old_value;

	rotspeed = 0.05;
	old_value = *xdir;
	*xdir = *xdir * cos(rotspeed) - *ydir * sin(rotspeed);
	*ydir = old_value * sin(rotspeed) + *ydir * cos(rotspeed);
	old_value = *xplane;
	*xplane = *xplane * cos(rotspeed) - *yplane * sin(rotspeed);
	*yplane = old_value * sin(rotspeed) + *yplane * cos(rotspeed);
}

void	move_plyr(t_vals *vals)
{
	double *xdir;
	double *ydir;
	double *xplane;
	double *yplane;

	xdir = &PLYR.x_dir;
	ydir = &PLYR.y_dir;
	xplane = &CAM.x_plane;
	yplane = &CAM.y_plane;
	if (KEY.forward)
		move_forward(vals, xdir, ydir);
	if (KEY.backward)
		move_backward(vals, xdir, ydir);
	if (KEY.right)
		move_right(vals);
	if (KEY.left)
		move_left(vals);
	if (KEY.right_rotate)
		rotate_right(xdir, ydir, xplane, yplane);
	if (KEY.left_rotate)
		rotate_left(xdir, ydir, xplane, yplane);
}

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
	xpos = &vals->plyr.x_pos;
	ypos = &vals->plyr.y_pos;
	if (g_map[(int)(*xpos + vals->cam.x_plane * movespeed)][(int)(*ypos)]
	== '0')
		*xpos += vals->cam.x_plane * movespeed;
	if (g_map[(int)(*xpos)][(int)(*ypos + vals->cam.y_plane * movespeed)]
	== '0')
		*ypos += vals->cam.y_plane * movespeed;
}

void	move_left(t_vals *vals)
{
	double	movespeed;
	double	*xpos;
	double	*ypos;

	movespeed = 0.05;
	xpos = &vals->plyr.x_pos;
	ypos = &vals->plyr.y_pos;
	if (g_map[(int)(*xpos - vals->cam.x_plane * movespeed)][(int)(*ypos)]
	== '0')
		*xpos -= vals->cam.x_plane * movespeed;
	if (g_map[(int)(*xpos)][(int)(*ypos - vals->cam.y_plane * movespeed)]
	== '0')
		*ypos -= vals->cam.y_plane * movespeed;
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

	xdir = &vals->plyr.x_dir;
	ydir = &vals->plyr.y_dir;
	xplane = &vals->cam.x_plane;
	yplane = &vals->cam.y_plane;
	if (vals->keys.forward)
		move_forward(vals, xdir, ydir);
	if (vals->keys.backward)
		move_backward(vals, xdir, ydir);
	if (vals->keys.right)
		move_right(vals);
	if (vals->keys.left)
		move_left(vals);
	if (vals->keys.right_rotate)
		rotate_right(xdir, ydir, xplane, yplane);
	if (vals->keys.left_rotate)
		rotate_left(xdir, ydir, xplane, yplane);
}

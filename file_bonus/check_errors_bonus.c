/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 13:01:54 by iltafah           #+#    #+#             */
/*   Updated: 2020/10/28 13:49:28 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int		check_option(char *str, int fd, int *screen_shot)
{
	if (!ft_strcmp("--save", str))
		*screen_shot = 1;
	else
	{
		ft_putstr("illegal option ");
		ft_putstr(str);
		close(fd);
		return (0);
	}
	return (*screen_shot);
}

void	check_arguments(int argc)
{
	if (argc > 3)
		ft_putstr("so much arguments\n");
	else
		ft_putstr("no map selected\n");
}

int		check_whether_there_are_errors_or_not(t_vals *vals)
{
	int		i;

	i = 1;
	if (vals->cubfile.error == 1 || vals->mlx.error == 1)
	{
		if (vals->cubfile.world_map)
			free_ptrs_to_str(&vals->cubfile.world_map);
		while (++i <= 6)
			free_str((char**)which_adresse(i, vals));
	}
	if (vals->mlx.error == 1)
		ft_putstr("fails to set up the connection to the graphical system\n");
	else if (vals->mlx.error == 2)
		ft_putstr("couldn't open the window for some reason 'NULL' :3\n");
	else if (vals->mlx.error == 3)
		ft_putstr("faild to load textures for some reason ;) 'NULL'\n");
	return (vals->cubfile.error + vals->mlx.error);
}

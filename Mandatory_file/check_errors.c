/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 13:01:54 by iltafah           #+#    #+#             */
/*   Updated: 2020/10/24 13:02:00 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

int		check_wheter_there_are_errors_or_not(t_vals *vals)
{
	if (vals->cubfile.error == 1)
		if (vals->cubfile.world_map)
			free_ptrs_to_str(&vals->cubfile.world_map);
	return (vals->cubfile.error);
}

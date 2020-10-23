/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handel_file_error.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 08:04:22 by iltafah           #+#    #+#             */
/*   Updated: 2020/03/13 08:47:11 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		handel_file_error(int num, t_vals *vals)
{
	if (vals->cubfile.error == 0)
	{
		vals->cubfile.error = 1;
		if (num == 0)
			ft_putstr("Error\ndata input error\n");
		else if (num == 1)
			ft_putstr("Error\nduplicated data\n");
		else if (num == 2)
			ft_putstr("Error\nmissing data\n");
		else if (num == 3)
			ft_putstr("Error\ncolor format not valid\n");
		else if (num == 4)
			ft_putstr("Error\nmap not found\n");
		else if (num == 5)
			ft_putstr("Error\nin surruonding walls or spawninng chars\n");
		else if (num == 6)
			ft_putstr("Error\nthere is no spawning characters\n");
		else if (num == 7)
			ft_putstr("Error\nempty path\n");
		else if (num == 8)
			ft_putstr("Error\npath doesn't exsist\n");
		else if (num == 9)
			ft_putstr("Error\nresolution format not valid\n");
	}
}

void		check_paths(t_vals *vals, char **ptr)
{
	int		fd;

	fd = open(*ptr, O_RDONLY);
	if (fd == -1)
		handel_file_error(8, vals);
	close(fd);
}

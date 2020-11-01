/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 13:01:54 by iltafah           #+#    #+#             */
/*   Updated: 2020/11/01 10:53:38 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int		check_option(char *str, int fd, int *screen_shot)
{
	if (!ft_strcmp("--save", str))
		*screen_shot = 1;
	else
	{
		ft_putstr("Error\nillegal option ");
		ft_putstr(str);
		close(fd);
		return (0);
	}
	return (*screen_shot);
}

void	check_arguments(int argc)
{
	if (argc > 3)
		ft_putstr("Error\nso much arguments\n");
	else
		ft_putstr("Error\nno map selected\n");
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
		ft_putstr("Error\nfaild set up connection to the graphical system\n");
	else if (vals->mlx.error == 2)
		ft_putstr("Error\ncouldn't open the window for some reason :3\n");
	else if (vals->mlx.error == 3)
		ft_putstr("Error\nfaild to load textures for some reason ;)\n");
	return (vals->cubfile.error + vals->mlx.error);
}

int		check_extension(t_vals *vals, char *path_name, char *extension, int *fd)
{
	int	len;

	len = ft_strlen(path_name) - 1;
	while (len && is_space(path_name[len]))
		len--;
	while (len && path_name[len] != '.')
		len--;
	if (path_name[len] == '.' && !ft_strcmp(path_name + ++len, extension))
		return (1);
	ft_putstr("Error\nin the file extension : '");
	ft_putstr(path_name + --len);
	ft_putstr("' it has to be '.cub'\n");
	vals->cubfile.error = 1;
	close(*fd);
	return (-1);
}

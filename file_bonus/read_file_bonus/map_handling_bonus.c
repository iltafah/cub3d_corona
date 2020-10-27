/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handling_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 07:29:07 by iltafah           #+#    #+#             */
/*   Updated: 2020/10/27 13:59:09 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	map_file_to_str(char *line, t_vals *vals, int fd)
{
	int		num;
	int		is_space;

	ft_double_strjoin(&vals->cubfile.keep, line, "|");
	is_space = 0;
	while ((num = get_next_line(fd, &line)) >= 0)
	{
		if (num == 0 && !*line)
			break ;
		if (is_space == 0)
			is_space = line_is_space(line) ? 1 : 0;
		else
			is_space = line_is_space(line) ? 1 : -1;
		if ((!line_is_map(line) && is_space == 0) || is_space == -1)
		{
			handel_file_error(0, vals);
			free_str(&vals->cubfile.keep);
			return ;
		}
		if (is_space == 0)
			ft_double_strjoin(&vals->cubfile.keep, line, "|");
		free_str(&line);
	}
	vals->cubfile.world_map = ft_split(vals->cubfile.keep, '|');
	check_map(vals->cubfile.world_map, vals);
}

int		check_surrounding(char **map, int i, int j)
{
	return ((i != 0 && j != 0 && map[i + 1])
			&& !my_chrcmp(map[i][j + 1], " \0", 2)
			&& !my_chrcmp(map[i][j - 1], " \0", 2)
			&& !my_chrcmp(map[i + 1][j], " \0", 2)
			&& !my_chrcmp(map[i - 1][j], " \0", 2));
}

void	check_map(char **map, t_vals *vals)
{
	int		i;
	int		j;
	int		two_spawning;

	i = -1;
	two_spawning = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (two_spawning > 1 || ((map[i][j] == '0' || map[i][j] == '2'
							|| map[i][j] == 'N' || map[i][j] == 'S'
							|| map[i][j] == 'E' || map[i][j] == 'W')
							&& !check_surrounding(map, i, j)))
				handel_file_error(5, vals);
			else if (map[i][j] == 'N' || map[i][j] == 'S'
					|| map[i][j] == 'E' || map[i][j] == 'W')
				two_spawning += 1;
		}
	}
	if (two_spawning == 0)
		handel_file_error(6, vals);
}

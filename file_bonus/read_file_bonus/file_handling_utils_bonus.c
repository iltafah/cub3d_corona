/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_handling_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 07:42:24 by iltafah           #+#    #+#             */
/*   Updated: 2020/10/27 13:59:05 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int		missing_data(char *data)
{
	while (*data)
	{
		if (*data == '0')
			return (1);
		data++;
	}
	return (0);
}

int		line_is_map(char *line)
{
	if (!*line || line_is_space(line))
		return (0);
	while (*line)
	{
		if (*line != 'N' && *line != 'S' && *line != 'E' && *line != 'W'
				&& !is_space(*line) && !is_digit(*line))
			return (0);
		line++;
	}
	return (1);
}

void	**which_adresse(int value, t_vals *vals)
{
	if (value == 2)
		return ((void**)&vals->cubfile.north_tex);
	if (value == 3)
		return ((void**)&vals->cubfile.south_tex);
	if (value == 4)
		return ((void**)&vals->cubfile.west_tex);
	if (value == 5)
		return ((void**)&vals->cubfile.east_tex);
	if (value == 6)
		return ((void**)&vals->cubfile.sprite_tex);
	if (value == 7)
		return ((void**)&vals->cubfile.floor_color);
	if (value == 8)
		return ((void**)&vals->cubfile.cell_color);
	return (NULL);
}

char	*key_words(int n)
{
	if (n == 1)
		return ("R");
	else if (n == 2)
		return ("NO");
	else if (n == 3)
		return ("SO");
	else if (n == 4)
		return ("WE");
	else if (n == 5)
		return ("EA");
	else if (n == 6)
		return ("S");
	else if (n == 7)
		return ("F");
	else if (n == 8)
		return ("C");
	return ("@");
}

int		my_strcmp(char *s1, char *s2, int n)
{
	int		i;

	i = 0;
	if (s1[i] == '@')
		return (-1);
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	if (s1[i] == '\0' && (is_space(s2[i]) || !s2[i]))
		return (n);
	return (my_strcmp(key_words(n + 1), s2, n + 1));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 08:02:11 by iltafah           #+#    #+#             */
/*   Updated: 2020/11/03 09:34:07 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	resolution_fill(char *line, t_vals *vals)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (!is_digit(*line))
		line++;
	while (line[i])
	{
		if (is_digit(line[i]) && is_space(line[i - 1]))
			count++;
		if (!is_digit(line[i]) && !is_space(line[i]))
			handel_file_error(9, vals);
		i++;
	}
	if (count != 2)
		handel_file_error(9, vals);
	if (is_digit(*line))
		vals->cubfile.screen_width = my_atoi(&line);
	while (is_space(*line))
		line++;
	if (is_digit(*line))
		vals->cubfile.screen_height = my_atoi(&line);
}

void	path_fill(char *line, int value, t_vals *vals)
{
	char	**ptr;

	ptr = (char**)which_adresse(value, vals);
	while (!is_space(*line) && *line)
		line++;
	while (is_space(*line))
		line++;
	if (!*line)
	{
		handel_file_error(7, vals);
		return ;
	}
	*ptr = ft_strdup("");
	*ptr = ft_strjoin(*ptr, line);
	check_paths(vals, ptr);
}

void	color_fill(char *line, int value, t_vals *vals)
{
	long int	*ptr;
	int			r;
	int			g;
	int			b;

	ptr = (long int*)which_adresse(value, vals);
	while (!is_space(*line))
		line++;
	while (is_space(*line))
		line++;
	if (!scan_line(line, " \t\v\n\f\r,0123456789")
	|| count_line(line, ',') != 2)
	{
		handel_file_error(3, vals);
		return ;
	}
	r = my_atoi(&line);
	skip_line(&line, " \t\v\n\f\r,");
	g = my_atoi(&line);
	skip_line(&line, " \t\v\n\f\r,");
	b = my_atoi(&line);
	*ptr = (r << 16) + (g << 8) + b;
	if (!line_is_space(line) || r > 255 || g > 255 || b > 255)
		handel_file_error(3, vals);
}

void	which_element(char *line, t_vals *vals, char (*data)[8])
{
	int			value;

	value = my_strcmp(key_words(1), line, 1);
	if (value > 0)
	{
		if ((*data)[value - 1] == '0')
			(*data)[value - 1] = '1';
		else
			handel_file_error(1, vals);
	}
	else
		handel_file_error(0, vals);
	if (value == 1)
		resolution_fill(line, vals);
	else if (value >= 2 && value <= 6)
		path_fill(line, value, vals);
	else if (value == 7 || value == 8)
		color_fill(line, value, vals);
}

void	handel_cubfile(int fd, t_vals *vals)
{
	char		*line;
	int			num;
	static char	data[8] = "00000000";

	while ((num = get_next_line(fd, &line)) >= 0)
	{
		if (my_strcmp(key_words(1), line, 1) >= 0)
			which_element(line, vals, &data);
		else if (line_is_map(line))
		{
			if (!missing_data(data))
				map_file_to_str(line, vals, fd);
			else
				handel_file_error(2, vals);
			free_array((void*)&line);
			return ;
		}
		else if (!line_is_space(line))
			handel_file_error(0, vals);
		if (!check_errors(vals, num, &line))
			return ;
	}
}

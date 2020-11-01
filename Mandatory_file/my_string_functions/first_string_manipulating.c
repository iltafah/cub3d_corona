/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_string_manipulating.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 07:58:56 by iltafah           #+#    #+#             */
/*   Updated: 2020/10/30 10:19:04 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		is_digit(char d)
{
	if (d >= '0' && d <= '9')
		return (1);
	return (0);
}

int		is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\v'
		|| c == '\n' || c == '\f' || c == '\r');
}

int		line_is_digits(char *line)
{
	while (*line)
	{
		if (!is_digit(*line) && !is_space(*line))
			return (0);
		line++;
	}
	return (1);
}

int		line_is_space(char *line)
{
	while (*line)
	{
		if (!is_space(*line))
			return (0);
		line++;
	}
	return (1);
}

int		count_line(char *line, char c)
{
	int		count;

	count = 0;
	while (*line)
	{
		if (*line == c)
			count++;
		line++;
	}
	return (count);
}

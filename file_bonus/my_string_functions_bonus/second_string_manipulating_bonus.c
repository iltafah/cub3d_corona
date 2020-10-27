/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_string_manipulating_bonus.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 07:59:10 by iltafah           #+#    #+#             */
/*   Updated: 2020/10/27 13:59:00 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int		my_atoi(char **str)
{
	int		num;

	num = 0;
	while (**str >= '0' && **str <= '9')
		num = (num * 10) + (*(*str)++ - '0');
	return (num);
}

int		my_chrcmp(char c, char *str, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

int		scan_line(char *line, char *set)
{
	int		i;

	while (*line)
	{
		i = 0;
		while (set[i])
		{
			if (*line == set[i])
				break ;
			i++;
		}
		if (!set[i])
			return (0);
		line++;
	}
	return (1);
}

void	ft_double_strjoin(char **str, char *s1, char *s2)
{
	if (!*str)
		*str = ft_strdup("");
	*str = ft_strjoin(*str, s1);
	*str = ft_strjoin(*str, s2);
	return ;
}

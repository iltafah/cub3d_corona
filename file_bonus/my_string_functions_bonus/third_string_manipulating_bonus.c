/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   third_string_manipulating_bonus.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 11:43:07 by iltafah           #+#    #+#             */
/*   Updated: 2020/11/03 09:43:22 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	free_array(void **array)
{
	free(*array);
	*array = NULL;
}

void	free_ptrs_to_str(char ***array)
{
	int i;

	i = 0;
	while ((*array)[i])
	{
		free_array((void*)&(*array)[i]);
		i++;
	}
	free((*array));
	*array = NULL;
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*s1;
	char		*s2;

	if (dst == 0 && src == 0)
		return (0);
	s1 = (char*)dst;
	s2 = (char*)src;
	while (n-- != 0)
	{
		*s1 = *s2;
		s1++;
		s2++;
	}
	return (dst);
}

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char *a1;
	unsigned char *a2;

	a1 = (unsigned char*)s1;
	a2 = (unsigned char*)s2;
	while (*a1 && *a2)
	{
		if (*a1 != *a2)
			return (*a1 - *a2);
		a1++;
		a2++;
	}
	return (*a1 - *a2);
}

void	skip_line(char **line, char *set)
{
	int		i;

	while (**line)
	{
		i = -1;
		while (set[++i])
		{
			if (**line == set[i])
				break ;
		}
		if (!set[i])
			return ;
		(*line)++;
	}
}

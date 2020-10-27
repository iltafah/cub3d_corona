/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   third_string_manipulating.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 11:43:07 by iltafah           #+#    #+#             */
/*   Updated: 2020/10/15 11:43:16 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_str(char **str)
{
	free(*str);
	*str = NULL;
}

void	free_ptrs_to_str(char ***array)
{
	int i;

	i = 0;
	while ((*array)[i])
	{
		free_str(&(*array)[i]);
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

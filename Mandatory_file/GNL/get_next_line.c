/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 03:44:32 by iltafah           #+#    #+#             */
/*   Updated: 2019/12/18 21:19:06 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		is_n(char *str)
{
	while (*str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

void	free_it(char **str)
{
	free(*str);
	*str = NULL;
}

int		fill_line(int fd, char **line, char **content)
{
	char	*tmp;
	int		end;

	end = 0;
	while (content[fd][end] != '\n' && content[fd][end] != '\0')
		end++;
	if (content[fd][end] == '\n')
	{
		*line = ft_substr(content[fd], 0, end);
		tmp = ft_strdup(content[fd] + end + 1);
		free(content[fd]);
		content[fd] = tmp;
	}
	else if (content[fd][end] == '\0')
	{
		*line = ft_strdup(content[fd]);
		free_it(&content[fd]);
		return (0);
	}
	return (1);
}

int		e_error(int size, int fd, char **line)
{
	char	buffer;

	if (fd < 0 || fd > 4864 || size <= 0 || !line)
		return (-1);
	if (read(fd, &buffer, 0) < 0)
		return (-1);
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static char *content[4864];
	char		*buffer;
	char		*tmp;
	int			r;
	int			e;

	r = 0;
	if ((e = e_error(BUFFER_SIZE, fd, line)) != 1)
		return (e);
	if (!(buffer = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	if (!content[fd])
		content[fd] = ft_strdup("");
	if (!is_n(content[fd]))
		while (((r = read(fd, buffer, BUFFER_SIZE)) > 0))
		{
			buffer[r] = '\0';
			tmp = ft_strjoin(content[fd], buffer);
			free(content[fd]);
			content[fd] = tmp;
			if (is_n(buffer))
				break ;
		}
	free(buffer);
	return (fill_line(fd, line, content));
}

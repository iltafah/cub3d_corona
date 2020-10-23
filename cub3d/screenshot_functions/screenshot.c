/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 09:52:50 by iltafah           #+#    #+#             */
/*   Updated: 2020/10/16 09:52:56 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	set_bit_map_file_header(t_vals *vals)
{
	static char file_type[3] = "BM";

	FILE_HEADER.file_type = file_type;
	FILE_HEADER.pixel_data_offset = 54;
	FILE_HEADER.file_size = 54 + INFO_HEADER.img_size;
}

void	set_bit_map_info_header(t_vals *vals)
{
	INFO_HEADER.img_width = g_win_width;
	INFO_HEADER.img_height = g_win_height;
	INFO_HEADER.bits_per_pixel = 24;
	INFO_HEADER.width_in_bytes = (INFO_HEADER.img_width * 3);
	if (INFO_HEADER.width_in_bytes % 4 != 0)
		INFO_HEADER.width_in_bytes += INFO_HEADER.width_in_bytes % 4;
	INFO_HEADER.img_size = INFO_HEADER.width_in_bytes * INFO_HEADER.img_height;
	INFO_HEADER.info_header_size = 40;
	INFO_HEADER.planes = 1;
}

void	copy_data_to_header(t_vals *vals, unsigned char *header)
{
	ft_memcpy(header, "BM", 2);
	ft_memcpy(header + 2, &FILE_HEADER.file_size, 4);
	ft_memcpy(header + 10, &FILE_HEADER.pixel_data_offset, 4);
	ft_memcpy(header + 14, &INFO_HEADER.info_header_size, 4);
	ft_memcpy(header + 18, &INFO_HEADER.img_width, 4);
	ft_memcpy(header + 22, &INFO_HEADER.img_height, 4);
	ft_memcpy(header + 26, &INFO_HEADER.planes, 2);
	ft_memcpy(header + 28, &INFO_HEADER.bits_per_pixel, 2);
	ft_memcpy(header + 34, &INFO_HEADER.img_size, 4);
}

void	store_pixels_to_buffer(t_vals *vals, unsigned char *buf)
{
	int row;
	int col;
	int x;
	int y;

	row = INFO_HEADER.img_height - 1;
	x = 0;
	while (row >= 0)
	{
		y = 0;
		col = 0;
		while (col < INFO_HEADER.img_width)
		{
			TEMP.red = (vals->img.data[x * g_win_width + y] >> 16) & 0xFF;
			TEMP.green = (vals->img.data[x * g_win_width + y] >> 8) & 0xFF;
			TEMP.blue = vals->img.data[x * g_win_width + y] & 0xFF;
			buf[row * INFO_HEADER.width_in_bytes + col * 3 + 0] = TEMP.blue;
			buf[row * INFO_HEADER.width_in_bytes + col * 3 + 1] = TEMP.green;
			buf[row * INFO_HEADER.width_in_bytes + col * 3 + 2] = TEMP.red;
			col++;
			y++;
		}
		row--;
		x++;
	}
}

void	screen_it(t_vals *vals)
{
	int						fd;
	unsigned char			*buf;
	static unsigned char	header[54];

	set_bit_map_info_header(vals);
	set_bit_map_file_header(vals);
	copy_data_to_header(vals, header);
	buf = malloc(INFO_HEADER.img_size);
	store_pixels_to_buffer(vals, buf);
	fd = open("./screen.bmp", O_CREAT | O_RDWR);
	write(fd, header, 54);
	write(fd, buf, INFO_HEADER.img_size);
	close(fd);
	free(buf);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 09:52:50 by iltafah           #+#    #+#             */
/*   Updated: 2020/10/27 12:46:12 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	set_bit_map_file_header(t_vals *vals)
{
	static char file_type[3] = "BM";

	vals->file_header.file_type = file_type;
	vals->file_header.pixel_data_offset = 54;
	vals->file_header.file_size = 54 + vals->inf_header.img_size;
}

void	set_bit_map_inf_header(t_vals *vals)
{
	vals->inf_header.img_width = g_win_w;
	vals->inf_header.img_height = g_win_h;
	vals->inf_header.bits_per_pixel = 24;
	vals->inf_header.w_byte = (vals->inf_header.img_width * 3);
	if (vals->inf_header.w_byte % 4 != 0)
		vals->inf_header.w_byte += vals->inf_header.w_byte % 4;
	vals->inf_header.img_size =
	vals->inf_header.w_byte * vals->inf_header.img_height;
	vals->inf_header.inf_header_size = 40;
	vals->inf_header.planes = 1;
}

void	copy_data_to_header(t_vals *vals, unsigned char *header)
{
	ft_memcpy(header, "BM", 2);
	ft_memcpy(header + 2, &vals->file_header.file_size, 4);
	ft_memcpy(header + 10, &vals->file_header.pixel_data_offset, 4);
	ft_memcpy(header + 14, &vals->inf_header.inf_header_size, 4);
	ft_memcpy(header + 18, &vals->inf_header.img_width, 4);
	ft_memcpy(header + 22, &vals->inf_header.img_height, 4);
	ft_memcpy(header + 26, &vals->inf_header.planes, 2);
	ft_memcpy(header + 28, &vals->inf_header.bits_per_pixel, 2);
	ft_memcpy(header + 34, &vals->inf_header.img_size, 4);
}

void	store_pixels_to_buffer(t_vals *vals, unsigned char *buf)
{
	unsigned int row;
	unsigned int col;
	unsigned int x;
	unsigned int y;

	row = vals->inf_header.img_height - 1;
	x = 0;
	while (row >= 0)
	{
		y = 0;
		col = 0;
		while (col < vals->inf_header.img_width)
		{
			vals->tmp.red = (vals->img.data[x * g_win_w + y] >> 16) & 0xFF;
			vals->tmp.green = (vals->img.data[x * g_win_w + y] >> 8) & 0xFF;
			vals->tmp.blue = vals->img.data[x * g_win_w + y] & 0xFF;
			buf[row * vals->inf_header.w_byte + col * 3 + 0] = vals->tmp.blue;
			buf[row * vals->inf_header.w_byte + col * 3 + 1] = vals->tmp.green;
			buf[row * vals->inf_header.w_byte + col * 3 + 2] = vals->tmp.red;
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

	set_bit_map_inf_header(vals);
	set_bit_map_file_header(vals);
	copy_data_to_header(vals, header);
	buf = malloc(vals->inf_header.img_size);
	store_pixels_to_buffer(vals, buf);
	fd = open("./screen.bmp", O_CREAT | O_RDWR);
	write(fd, header, 54);
	write(fd, buf, vals->inf_header.img_size);
	close(fd);
	free(buf);
}

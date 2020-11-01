/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   third_initialize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 11:52:46 by iltafah           #+#    #+#             */
/*   Updated: 2020/10/30 11:53:48 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	initialize_file_header(t_vals *vals)
{
	vals->file_header.file_type = 0;
	vals->file_header.file_size = 0;
	vals->file_header.pixel_data_offset = 0;
}

void	initialize_inf_header(t_vals *vals)
{
	vals->inf_header.inf_header_size = 0;
	vals->inf_header.img_width = 0;
	vals->inf_header.img_height = 0;
	vals->inf_header.planes = 0;
	vals->inf_header.bits_per_pixel = 0;
	vals->inf_header.img_size = 0;
	vals->inf_header.w_byte = 0;
}

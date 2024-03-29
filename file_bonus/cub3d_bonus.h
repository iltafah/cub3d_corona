/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 15:05:51 by iltafah           #+#    #+#             */
/*   Updated: 2020/11/03 09:43:48 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "GNL_bonus/get_next_line_bonus.h"
# include <mlx.h>

int		g_win_w;
int		g_win_h;
void	*g_mlx_ptr;
void	*g_mlx_win;
char	**g_map;

typedef struct		s_cubfile
{
	int				screen_width;
	int				screen_height;
	char			*north_tex;
	char			*south_tex;
	char			*west_tex;
	char			*east_tex;
	char			*sprite_tex;
	long int		floor_color;
	long int		cell_color;
	char			*keep;
	char			**world_map;
	int				error;
	int				total;
}					t_cubfile;

typedef	struct		s_mlx
{
	void			*ptr;
	void			*win_ptr;
	int				error;
}					t_mlx;

typedef	struct		s_plyr
{
	int				x_square;
	int				y_square;
	double			x_pos;
	double			y_pos;
	double			x_dir;
	double			y_dir;
}					t_plyr;

typedef	struct		s_cam
{
	double			x_plane;
	double			y_plane;
	double			x;
}					t_cam;

typedef	struct		s_rays
{
	int				hit_side;
	int				x_step;
	int				y_step;
	double			x_dir;
	double			y_dir;
	double			x_sidedist;
	double			y_sidedist;
	double			x_deltadist;
	double			y_deltadist;
	double			perp_dist;
}					t_rays;

typedef	struct		s_keys
{
	int				forward;
	int				backward;
	int				right;
	int				left;
	int				right_rotate;
	int				left_rotate;
}					t_keys;

typedef	struct		s_img
{
	void			*ptr;
	void			**ptr_to_loaded_tex;
	int				*data;
	int				**loaded_tex;
	int				*tex_width;
	int				*tex_height;
	int				tex_index;
	int				line_height;
	int				x;
	int				y;
	int				width;
	int				height;
	double			texpos;
	double			step;
	int				red;
	int				green;
	int				blue;
}					t_img;

typedef	struct		s_sprite
{
	double			*x_pos;
	double			*y_pos;
	int				*index;
	int				num_of_sprites;
	double			*z_wall_distance;
	int				width;
	int				height;
	int				x_start;
	int				y_start;
	int				x_end;
	int				y_end;
	int				x_screen;
}					t_sprite;

typedef	struct		s_file_header
{
	char			*file_type;
	int32_t			file_size;
	int32_t			pixel_data_offset;
}					t_file_header;

typedef	struct		s_inf_header
{
	u_int32_t		inf_header_size;
	u_int32_t		img_width;
	u_int32_t		img_height;
	uint16_t		planes;
	uint16_t		bits_per_pixel;
	uint32_t		img_size;
	int				w_byte;
}					t_inf_header;

typedef	struct		s_vals
{
	t_cubfile		cubfile;
	t_mlx			mlx;
	t_plyr			plyr;
	t_cam			cam;
	t_rays			ray;
	t_keys			keys;
	t_img			img;
	t_sprite		sprite;
	t_file_header	file_header;
	t_inf_header	inf_header;
}					t_vals;

void				create_screen_img(t_vals *vals);
void				calculate_perpendicular_distance_of_wall_hit(t_vals *vals);
void				calculate_sprite_width_height(t_vals *vals, double y_trans);
void				check_paths(t_vals *vals, char **ptr);
int					check_option(char *str, int fd, int *screen_shot);
int					check_extension(t_vals *v, char *path, char *ext, int *fd);
void				check_arguments(int	argc);
int					check_whether_there_are_errors_or_not(t_vals *vals);
int					check_errors(t_vals *vals, int num, char **line);
int					count_line(char *line, char c);
void				check_map(char **world_map, t_vals *vals);
void				calculate_rayside(t_vals *vals);
void				dda_loop(t_vals *vals);
void				draw_walls(t_vals *vals);
void				draw_cell(t_vals *vals);
void				draw_floor(t_vals *vals);
void				draw_sprite(t_vals *vals, int i);
void				draw_sprites(t_vals *vals);
int					exit_function(t_vals *vals);
void				ft_putstr(char *str);
int					ft_strcmp(const char *s1, const char *s2);
void				free_array(void **array);
void				free_ptrs_to_str(char ***array);
char				**ft_split(char const *s, char c);
void				ft_double_strjoin(char **str, char *s1, char *s2);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				handel_cubfile(int fd, t_vals *vals);
void				handel_repeat(char *line, t_vals *vals);
void				handel_file_error(int num, t_vals *vals);
int					is_digit(char d);
void				initialize_plyr(t_vals *vals);
void				initialize_ray(t_vals *vals);
void				initialize_keys(t_vals *vals);
void				initialize_struct(t_vals *vals);
int					is_space(char c);
void				initialize_global_variables(t_vals *vals);
void				initialize_img(t_vals *vals);
void				initialize_sprite(t_vals *vals);
void				initialize_file_header(t_vals *vals);
void				initialize_inf_header(t_vals *vals);
int					key_pressed(int key, t_vals *vals);
int					key_released(int key, t_vals *vals);
char				*key_words(int n);
int					line_is_space(char *line);
int					line_is_digits(char *line);
int					line_is_map(char *line);
void				load_north_tex(t_vals *v, int b, int size, int endi);
void				load_south_tex(t_vals *v, int b, int size, int endi);
void				load_east_tex(t_vals *v, int b, int size, int endi);
void				load_west_tex(t_vals *v, int b, int size, int endi);
void				load_sprite_tex(t_vals *v, int b, int size, int endi);
int					my_atoi(char **str);
int					my_strcmp(char *s1, char *s2, int n);
void				**which_adresse(int value, t_vals *vals);
int					missing_data(char *data);
int					my_chrcmp(char c, char *str, int len);
void				map_file_to_str(char *line, t_vals *vals, int fd);
void				move_plyr(t_vals *vals);
void				move_forward(t_vals *vals, double *xdir, double *ydir);
void				move_backward(t_vals *vals, double *xdir, double *ydir);
int					scan_line(char *line, char *set);
void				set_sprite_position(t_vals *vals);
void				set_plyr_position(t_vals *vals);
void				screen_it(t_vals *vals);
void				skip_line(char **line, char *set);
void				store_sprite_data(t_vals *vals, double y_trans);
void				store_data(t_vals *vals, int x_screen);
int					take_screen_shot(t_vals *vals);
void				texture_calculation(t_vals *vals, int *y_start, int *y_end);
int					update(t_vals *vals);
#endif

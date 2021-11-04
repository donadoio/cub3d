/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/21 18:38:26 by idonado       #+#    #+#                 */
/*   Updated: 2021/11/03 19:59:54 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define WINWIDTH 1024
# define WINHEIGHT 768
# define ROTATE_SPEED 0.05
# define MOVE_SPEED 0.28
# define PI 3.1415926435
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <libft.h>
# include <fcntl.h>
# include <mlx.h>
# include <math.h>
# include <keycodes_osx.h>

typedef enum e_bool{
	False,
	True
}		t_bool;

typedef struct s_img_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}				t_img_data;

typedef struct s_mlx_vars
{
	void	*mlx;
	void	*mlx_window;
}				t_mlx_vars;

typedef struct s_parse_data
{
	int		map_fd;
	int		direction_set;
	int		main_img_set;
	int		text_one_set;
	int		text_two_set;
	int		text_three_set;
	int		text_four_set;
	int		ceiling_set;
	int		floor_set;
	int		map_set;
	int		all_set;
	char	*line;
}				t_parse_data;

typedef struct s_data
{
	t_mlx_vars		*mlx;
	t_img_data		*img;
	t_img_data		*texture_1;
	t_img_data		*texture_2;
	t_img_data		*texture_3;
	t_img_data		*texture_4;
	t_img_data		*loaded_texture;
	t_parse_data	parse_data;
	int				**map;
	int				map_begin;
	int				map_height;
	int				map_width;
	int				ceiling_color;
	int				floor_color;
	int				vert_line_color;
	char			**rgb;
	int				r;
	int				g;
	int				b;
	char			*temp;
	char			*error;
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			time;
	double			old_time;
	double			move_speed;
	double			rot_speed;
	double			camera_x;
	double			ray_dir_x;
	double			ray_dir_y;
	int				map_x;
	int				map_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			perp_wall_dist;
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
	int				line_height;
	int				draw_start;
	int				draw_end;
	int				x;
	double			wall_x;
	int				tex_x;
	int				tex_y;
	int				y;
	int				d;
	int				i;
	int				text_number;
}				t_data;

void	map_check_init(char **argv, t_data *data);
void	pre_map_check(t_data *data);
void	grab_map(char **argv, t_data *data);
void	invalid_line_exit(t_data *data, char *msg, int free_line);
void	check_ceiling(t_data *data, int *action);
void	check_north(t_data *data, int *action);
void	check_south(t_data *data, int *action);
void	check_west(t_data *data, int *action);
void	check_east(t_data *data, int *action);
void	check_floor(t_data *data, int *action);
void	check_ceiling(t_data *data, int *action);
int		structs_init(t_data *data);
int		delete_structs(t_data *data, int count);
void	delete_and_destroy_all(t_data *data);
void	check_map_filepath(char **argv, t_data *data);
void	exit_delete_map(t_data *data, int last, int free_line);
void	free_temp_and_exit(t_data *data, int **tempmap);
void	set_north(t_data *data, int x, int y, int *map_line);
void	set_south(t_data *data, int x, int y, int *map_line);
void	set_east(t_data *data, int x, int y, int *map_line);
void	set_west(t_data *data, int x, int y, int *map_line);
int		fix_temp_path(char *temp);
int		valid_last_rgb(char *blue);
int		rgb_to_hex(char *decimals, t_data *data);
void	safe_exit(t_data *data, char *msg);
void	handle_temp_alloc_fail(t_data *data, int **tempmap, int i, int flag);
void	free_tempmap(t_data *data, int **tempmap);
int		**fill_map_check(t_data *data, int **tempmap, int i, int j);
void	check_map(t_data *data);

void	free_split(char **words);
int		ft_str_isnum(char *str);
int		create_trgb(int t, int r, int g, int b);

int		keypressed(int keycode, t_data	*data);
void	rotate(t_data *data, double rotate_speed);
void	down_pressed(t_data *data);
void	up_pressed(t_data *data);

int		check_next_pos_down_x(t_data *data);
int		check_next_pos_down_y(t_data *data);
int		check_next_pos_up_x(t_data *data);
int		check_next_pos_up_y(t_data *data);
int		check_next_pos_left_x(t_data *data);
int		check_next_pos_left_y(t_data *data);
int		check_next_pos_right_x(t_data *data);
int		check_next_pos_right_y(t_data *data);

void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color);
void	draw_vertical_line(t_data *data, int x, int begin, int end);
int		render_next_frame(t_data *data);
void	texture_setter(t_data *data);
void	vertical_line_calc(t_data *data);
void	draw_window_line(t_data *data);

#endif

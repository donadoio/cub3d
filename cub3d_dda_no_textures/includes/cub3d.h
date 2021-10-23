/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/21 18:38:26 by idonado       #+#    #+#                 */
/*   Updated: 2021/10/23 21:21:03 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define WINWIDTH 1024
# define WINHEIGHT 768
# define MAPLENGTH 24
# define mapWidth 24
# define mapHeight 24
# define ROTATE_SPEED 0.04
# define MOVE_SPEED 0.14
# define PI 3.1415926435
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <libft.h>
# include <fcntl.h>
# include <mlx.h>
# include <math.h>

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

typedef struct s_data
{
	t_mlx_vars	*mlx;
	t_img_data	*img;
	int			**map;

	// position and direction variables
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;

	// camera plane variables
	double	plane_x;
	double	plane_y;

	//used for fps (?)
	double	time;
	double	old_time;
	double	move_speed;
	double	rot_speed;
}				t_data;

//console stuff
void	print_map(t_data *data);

//Graphic stuff
void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color);
int		draw_line(t_data *data, int beginX, int beginY, int endX, int endY, int color);
void	draw_vertical_line(t_data *data, int x, int begin, int end, int color);
void	clear_screen(t_data *data);


#endif
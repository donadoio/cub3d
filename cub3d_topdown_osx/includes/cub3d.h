/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/21 18:38:26 by idonado       #+#    #+#                 */
/*   Updated: 2021/10/22 20:52:09 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define WINWIDTH 512
# define WINHEIGHT 478
# define MAPLENGTH 24
# define BLOCKSIZEWIDTH WINWIDTH / MAPLENGTH
# define BLOCKSIZEHEIGHT WINHEIGHT / MAPLENGTH
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

	float	pos_x;
	float	pos_y;

	float	pdx;
	float	pdy;
	float	pa;
}				t_data;

//console stuff
void	print_map(t_data *data);

//Graphic stuff
void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color);
int		draw_line(t_data *data, int beginX, int beginY, int endX, int endY, int color);

//topdown stuff
void	draw_player(t_data *data, float pos_x, float pos_y);
void	clear_player(t_data *data, float pos_x, float pos_y);
void	draw_map(t_data *data);

#endif
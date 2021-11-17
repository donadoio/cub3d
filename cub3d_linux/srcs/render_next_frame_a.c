/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_next_frame_a.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/03 16:47:49 by idonado       #+#    #+#                 */
/*   Updated: 2021/11/03 19:27:10 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	draw_vertical_line(t_data *data, int x, int begin, int end)
{
	while (begin < end)
	{
		my_mlx_pixel_put(data->img, x, begin, data->vert_line_color);
		begin++;
	}
	return ;
}

//Initial calculations..
//Calculate ray position and direction 
//set map_x and map_y to area in map using pos_x and pos_y
//Calculate distance to next X line and Y line
//Initializing hit to 0 for future DDA algorithm
static void	init_calc_one(t_data *data)
{
	data->camera_x = 2 * data->x / (double)WINWIDTH - 1;
	data->ray_dir_x = data->dir_x + data->plane_x * data->camera_x;
	data->ray_dir_y = data->dir_y + data->plane_y * data->camera_x;
	data->map_x = (int)data->pos_x;
	data->map_y = (int)data->pos_y;
	if (data->ray_dir_x == 0)
		data->delta_dist_x = 1e30;
	else
		data->delta_dist_x = fabs(1 / data->ray_dir_x);
	if (data->ray_dir_y == 0)
		data->delta_dist_y = 1e30;
	else
		data->delta_dist_y = fabs(1 / data->ray_dir_y);
	data->hit = 0;
	return ;
}

//Calculate Initial side distance to next X_step or Y_step for DDA algorithm
static void	init_calc_two(t_data *data)
{
	if (data->ray_dir_x < 0)
	{
		data->step_x = -1;
		data->side_dist_x = (data->pos_x - data->map_x) * data->delta_dist_x;
	}
	else
	{
		data->step_x = 1;
		data->side_dist_x = (data->map_x + \
1.0 - data->pos_x) * data->delta_dist_x;
	}
	if (data->ray_dir_y < 0)
	{
		data->step_y = -1;
		data->side_dist_y = (data->pos_y - data->map_y) * data->delta_dist_y;
	}
	else
	{
		data->step_y = 1;
		data->side_dist_y = (data->map_y + 1.0 - \
data->pos_y) * data->delta_dist_y;
	}
	return ;
}

//Digital Diferential Analizer
//this just jumps to the next nearest line, could be x or y and then
//checks if that square is occupied by 1 (wall hit)
static void	dda_algorithm(t_data *data)
{
	while (data->hit == 0)
	{
		if (data->side_dist_x < data->side_dist_y)
		{
			data->side_dist_x += data->delta_dist_x;
			data->map_x += data->step_x;
			data->side = 0;
		}
		else
		{
			data->side_dist_y += data->delta_dist_y;
			data->map_y += data->step_y;
			data->side = 1;
		}
		if (data->map[data->map_x][data->map_y] > 0)
			data->hit = 1;
	}
	return ;
}

int	render_next_frame(t_data *data)
{
	data->text_number = 5;
	data->x = 0;
	while (data->x < WINWIDTH)
	{
		init_calc_one(data);
		init_calc_two(data);
		dda_algorithm(data);
		texture_setter(data);
		vertical_line_calc(data);
		draw_window_line(data);
		my_mlx_pixel_put(data->img, data->x, data->draw_end, 0x00000000);
		data->x++;
	}
	mlx_put_image_to_window(data->mlx->mlx, data->mlx->mlx_window, \
data->img->img, 0, 0);
	return (0);
}

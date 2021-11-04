/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_pressed_b.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/03 17:52:33 by idonado       #+#    #+#                 */
/*   Updated: 2021/11/03 18:02:14 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	rotate(t_data *data, double rotate_speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->dir_x;
	data->dir_x = data->dir_x * cos(-rotate_speed) - \
data->dir_y * sin(-rotate_speed);
	data->dir_y = old_dir_x * sin(-rotate_speed) + \
data->dir_y * cos(-rotate_speed);
	old_plane_x = data->plane_x;
	data->plane_x = data->plane_x * cos(-rotate_speed) - \
data->plane_y * sin(-rotate_speed);
	data->plane_y = old_plane_x * sin(-rotate_speed) + \
data->plane_y * cos(-rotate_speed);
	render_next_frame(data);
}

void	down_pressed(t_data *data)
{
	if (data->map[(int)(data->pos_x - data->dir_x * \
MOVE_SPEED)][(int)(data->pos_y)] == 0 && check_next_pos_down_x(data) == 1)
		data->pos_x = data->pos_x - data->dir_x * MOVE_SPEED;
	if (data->map[(int)(data->pos_x)][(int)(data->pos_y - \
data->dir_y * MOVE_SPEED)] == 0 && check_next_pos_down_y(data) == 1)
		data->pos_y = data->pos_y - data->dir_y * MOVE_SPEED;
	render_next_frame(data);
	return ;
}

void	up_pressed(t_data *data)
{
	if (data->map[(int)(data->pos_x + data->dir_x * \
MOVE_SPEED)][(int)(data->pos_y)] == 0 && check_next_pos_up_x(data) == 1)
		data->pos_x = data->pos_x + data->dir_x * MOVE_SPEED;
	if (data->map[(int)(data->pos_x)][(int)(data->pos_y + \
data->dir_y * MOVE_SPEED)] == 0 && check_next_pos_up_y(data) == 1)
		data->pos_y = data->pos_y + data->dir_y * MOVE_SPEED;
	render_next_frame(data);
	return ;
}

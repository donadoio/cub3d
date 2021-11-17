/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_pressed_a.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/03 18:05:47 by idonado       #+#    #+#                 */
/*   Updated: 2021/11/03 20:00:17 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	left_pressed(t_data *data)
{
	double	look_dir_x;
	double	look_dir_y;

	look_dir_x = data->dir_y;
	look_dir_y = data->dir_x;
	if (data->map[(int)(data->pos_x - look_dir_x * \
MOVE_SPEED)][(int)(data->pos_y)] == 0 && check_next_pos_left_x(data) == 1)
		data->pos_x -= look_dir_x * MOVE_SPEED;
	if (data->map[(int)(data->pos_x)][(int)(data->pos_y + look_dir_y * \
MOVE_SPEED)] == 0 && check_next_pos_left_y(data) == 1)
		data->pos_y += look_dir_y * MOVE_SPEED;
	render_next_frame(data);
	return ;
}

static void	right_pressed(t_data *data)
{
	double	look_dir_x;
	double	look_dir_y;

	look_dir_x = data->dir_y;
	look_dir_y = data->dir_x;
	if (data->map[(int)(data->pos_x + look_dir_x * \
MOVE_SPEED)][(int)(data->pos_y)] == 0 && check_next_pos_right_x(data) == 1)
		data->pos_x += look_dir_x * MOVE_SPEED;
	if (data->map[(int)(data->pos_x)][(int)(data->pos_y - \
look_dir_y * MOVE_SPEED)] == 0 && check_next_pos_right_y(data) == 1)
		data->pos_y -= look_dir_y * MOVE_SPEED;
	render_next_frame(data);
	return ;
}

static void	rotate_left(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->dir_x;
	data->dir_x = data->dir_x * cos(ROTATE_SPEED) - \
data->dir_y * sin(ROTATE_SPEED);
	data->dir_y = old_dir_x * sin(ROTATE_SPEED) + \
data->dir_y * cos(ROTATE_SPEED);
	old_plane_x = data->plane_x;
	data->plane_x = data->plane_x * cos(ROTATE_SPEED) - \
data->plane_y * sin(ROTATE_SPEED);
	data->plane_y = old_plane_x * sin(ROTATE_SPEED) + \
data->plane_y * cos(ROTATE_SPEED);
	render_next_frame(data);
	return ;
}

static void	rotate_right(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->dir_x;
	data->dir_x = data->dir_x * cos(-ROTATE_SPEED) - \
data->dir_y * sin(-ROTATE_SPEED);
	data->dir_y = old_dir_x * sin(-ROTATE_SPEED) + \
data->dir_y * cos(-ROTATE_SPEED);
	old_plane_x = data->plane_x;
	data->plane_x = data->plane_x * cos(-ROTATE_SPEED) - \
data->plane_y * sin(-ROTATE_SPEED);
	data->plane_y = old_plane_x * sin(-ROTATE_SPEED) + \
data->plane_y * cos(-ROTATE_SPEED);
	render_next_frame(data);
	return ;
}

int	keypressed(int keycode, t_data	*data)
{
	if (keycode == UP_KEY)
	{
		up_pressed(data);
	}
	else if (keycode == DOWN_KEY)
		down_pressed(data);
	else if (keycode == LEFT_KEY)
		left_pressed(data);
	else if (keycode == RIGHT_KEY)
		right_pressed(data);
	else if (keycode == LEFT_ROTATE)
		rotate_left(data);
	else if (keycode == RIGHT_ROTATE)
		rotate_right(data);
	else if (keycode == ESC_KEY)
		safe_exit(data, "Bye!");
	if (data->dir_x == 0 || data->dir_x == 1 || data->dir_x == -1 || \
data->dir_y == 0 || data->dir_y == 1 || data->dir_y == -1 )
		rotate(data, 0.001);
	return (0);
}

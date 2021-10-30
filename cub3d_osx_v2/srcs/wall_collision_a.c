/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   wall_collision_a.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/29 18:23:32 by idonado       #+#    #+#                 */
/*   Updated: 2021/10/29 22:46:11 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	check_next_pos_down_x(t_data *data)
{
	int		temp_int;
	float	temp_float;
	float	value;
	int		pos_next;

	value = data->pos_x - data->dir_x * MOVE_SPEED;
	temp_int = (int)value;
	temp_float = value - (float)temp_int;
	if (data->dir_x > 0)
	{
		pos_next = (int)data->pos_x - 1;
	}
	else
	{
		pos_next = (int)data->pos_x + 1;
	}
	if ((int)data->pos_x == (int)value && data->map[pos_next][(int)data->pos_y] == 1)
	{
		printf("Near wall \n");
		if (pos_next > (int)data->pos_x && temp_float > 0.75)
		{
			printf("Denied move up to x %f\n", value);
			return (0);
		}
		else if (pos_next < (int)data->pos_x && temp_float < 0.25)
		{
			printf("Denied move up to x %f\n", value);
			return (0);
		}
	}
	return (1);
}

int	check_next_pos_down_y(t_data *data)
{
	int		temp_int;
	float	temp_float;
	float	value;
	int		pos_next;

	value = data->pos_y - data->dir_y * MOVE_SPEED;
	temp_int = (int)value;
	temp_float = value - (float)temp_int;
	if (data->dir_y > 0)
	{
		printf("facing east?\n");
		pos_next = (int)data->pos_y - 1;
	}
	else
	{
		printf("facing west?\n");
		pos_next = (int)data->pos_y + 1;
	}
	if ((int)data->pos_y == (int)value && data->map[(int)data->pos_x][pos_next] == 1)
	{
		if (pos_next > (int)data->pos_y && temp_float > 0.75)
		{
			printf("Denied move up to y %f\n", value);
			return (0);
		}
		else if (pos_next < (int)data->pos_y && temp_float < 0.25)
		{
			printf("Denied move up to y %f\n", value);
			return (0);
		}
	}
	return (1);
}

int	check_next_pos_up_x(t_data *data)
{
	int		temp_int;
	float	temp_float;
	float	value;
	int		pos_next;

	value = data->pos_x + data->dir_x * MOVE_SPEED;
	temp_int = (int)value;
	temp_float = value - (float)temp_int;
	if (data->dir_x > 0)
	{
		pos_next = (int)data->pos_x + 1;
	}
	else
	{
		pos_next = (int)data->pos_x - 1;
	}
	if ((int)data->pos_x == (int)value && data->map[pos_next][(int)data->pos_y] == 1)
	{
		printf("Near wall \n");
		if (pos_next > (int)data->pos_x && temp_float > 0.75)
		{
			printf("Denied move up to x %f\n", value);
			return (0);
		}
		else if (pos_next < (int)data->pos_x && temp_float < 0.25)
		{
			printf("Denied move up to x %f\n", value);
			return (0);
		}
	}
	return (1);
}

int	check_next_pos_up_y(t_data *data)
{
	int		temp_int;
	float	temp_float;
	float	value;
	int		pos_next;

	value = data->pos_y + data->dir_y * MOVE_SPEED;
	temp_int = (int)value;
	temp_float = value - (float)temp_int;
	if (data->dir_y > 0)
	{
		printf("facing east?\n");
		pos_next = (int)data->pos_y + 1;
	}
	else
	{
		printf("facing west?\n");
		pos_next = (int)data->pos_y - 1;
	}
	if ((int)data->pos_y == (int)value && data->map[(int)data->pos_x][pos_next] == 1)
	{
		if (pos_next > (int)data->pos_y && temp_float > 0.75)
		{
			printf("Denied move up to y %f\n", value);
			return (0);
		}
		else if (pos_next < (int)data->pos_y && temp_float < 0.25)
		{
			printf("Denied move up to y %f\n", value);
			return (0);
		}
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_check_e.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/03 18:17:49 by idonado       #+#    #+#                 */
/*   Updated: 2021/11/03 18:17:54 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	set_north(t_data *data, int x, int y, int *map_line)
{
	data->pos_x = x;
	data->pos_y = y;
	map_line[y] = 0;
	data->parse_data.direction_set = 1;
	data->dir_x = -1;
	data->dir_y = 0;
	data->plane_x = 0;
	data->plane_y = 0.66;
	return ;
}

void	set_south(t_data *data, int x, int y, int *map_line)
{
	data->pos_x = x;
	data->pos_y = y;
	map_line[y] = 0;
	data->parse_data.direction_set = 1;
	data->dir_y = 0;
	data->plane_x = 0;
	data->dir_x = 1;
	data->plane_y = -0.66;
	return ;
}

void	set_east(t_data *data, int x, int y, int *map_line)
{
	data->pos_x = x;
	data->pos_y = y;
	map_line[y] = 0;
	data->parse_data.direction_set = 1;
	data->dir_x = 0;
	data->dir_y = 1;
	data->plane_y = 0;
	data->plane_x = 0.66;
	return ;
}

void	set_west(t_data *data, int x, int y, int *map_line)
{
	data->pos_x = x;
	data->pos_y = y;
	map_line[y] = 0;
	data->parse_data.direction_set = 1;
	data->dir_x = 0;
	data->dir_y = -1;
	data->plane_y = 0;
	data->plane_x = -0.66;
	return ;
}

void	exit_delete_map(t_data *data, int last, int free_line)
{
	int	i;

	i = 0;
	while (i <= last)
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
	invalid_line_exit(data, "Error: Invalid map", free_line);
}

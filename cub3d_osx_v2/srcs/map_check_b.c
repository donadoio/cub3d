/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_check_b.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/02 15:29:44 by idonado       #+#    #+#                 */
/*   Updated: 2021/11/02 19:35:29 by idonado       ########   odam.nl         */
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

void	copy_map_line(t_data *data, int *map_line, int x)
{
	int	i;

	i = 0;
	while (data->parse_data.line[i] != '\0')
	{
		if (data->parse_data.direction_set == 0 && data->parse_data.line[i] == 'N')
			set_north(data, x, i, map_line);
		else if (data->parse_data.direction_set == 0 && data->parse_data.line[i] == 'S')
			set_south(data, x, i, map_line);
		else if (data->parse_data.direction_set == 0 && data->parse_data.line[i] == 'W')
			set_west(data, x, i, map_line);
		else if (data->parse_data.direction_set == 0 && data->parse_data.line[i] == 'E')
			set_east(data, x, i, map_line);
		else if (data->parse_data.line[i] == '0' || data->parse_data.line[i] == ' ')
			map_line[i] = 0;
		else if (data->parse_data.line[i] == '1')
			map_line[i] = 1;
		else
			exit_delete_map(data, i, 1);
		i++;
	}
	while (i < data->map_width)
	{
		map_line[i] = 0;
		i++;
	}
	return ;
}

void	grab_map(char **argv, t_data *data)
{
	int	i;

	data->map = malloc(sizeof(int *) * (data->map_height + 1));
	data->map[data->map_height] = NULL;
	check_map_filepath(argv, data);
	i = 0;
	while (i < data->map_begin)
	{
		get_next_line(data->parse_data.map_fd, &data->parse_data.line);
		if (i + 1 < data->map_begin)
			free(data->parse_data.line);
		i++;
	}
	printf("First map line: %s\n", data->parse_data.line);
	data->map[0] = malloc(sizeof(int) * data->map_width);
	copy_map_line(data, data->map[0], 0);
	free(data->parse_data.line);
	i = 1;
	while (i < data->map_height)
	{
		get_next_line(data->parse_data.map_fd, &data->parse_data.line);
		data->map[i] = malloc(sizeof(int) * data->map_width);
		copy_map_line(data, data->map[i], i);
		free(data->parse_data.line);
		i++;
	}
	printf("Null terminated array: %p\n", data->map[i]);
	if (data->parse_data.direction_set == 0)
		exit_delete_map(data, i, 0);
	print_map(data);
	close(data->parse_data.map_fd);
}

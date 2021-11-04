/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_check_b.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/02 15:29:44 by idonado       #+#    #+#                 */
/*   Updated: 2021/11/04 17:58:35 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	copy_map_line_b(t_data *data, int *map_line, int x, int i)
{
	if (data->parse_data.direction_set == 0 && data->parse_data.line[i] == 'N')
		set_north(data, x, i, map_line);
	else if (data->parse_data.direction_set == 0 && \
data->parse_data.line[i] == 'S')
		set_south(data, x, i, map_line);
	else if (data->parse_data.direction_set == 0 && \
data->parse_data.line[i] == 'W')
		set_west(data, x, i, map_line);
	else if (data->parse_data.direction_set == 0 && \
data->parse_data.line[i] == 'E')
		set_east(data, x, i, map_line);
	else if (data->parse_data.line[i] == '0' || \
data->parse_data.line[i] == ' ')
		map_line[i] = 0;
	else if (data->parse_data.line[i] == '1')
		map_line[i] = 1;
	else
		exit_delete_map(data, x, 1);
}

void	copy_map_line(t_data *data, int *map_line, int x)
{
	int	i;

	i = 0;
	while (data->parse_data.line[i] != '\0')
	{
		copy_map_line_b(data, map_line, x, i);
		i++;
	}
	while (i < data->map_width)
	{
		map_line[i] = 0;
		i++;
	}
	return ;
}

static void	grab_map_b(t_data *data)
{
	int	i;

	i = 1;
	while (i < data->map_height)
	{
		get_next_line(data->parse_data.map_fd, &data->parse_data.line);
		data->map[i] = malloc(sizeof(int) * data->map_width);
		copy_map_line(data, data->map[i], i);
		free(data->parse_data.line);
		i++;
	}
	if (data->parse_data.direction_set == 0)
		exit_delete_map(data, i, 0);
	close(data->parse_data.map_fd);
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
	data->map[0] = malloc(sizeof(int) * data->map_width);
	copy_map_line(data, data->map[0], 0);
	free(data->parse_data.line);
	grab_map_b(data);
}

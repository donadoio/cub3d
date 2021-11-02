/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_check_a.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/01 16:13:36 by idonado       #+#    #+#                 */
/*   Updated: 2021/11/02 21:53:20 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include <fcntl.h>

void	check_map_filepath(char **argv, t_data *data)
{
	data->parse_data.map_fd = open(argv[1], O_RDONLY);
	if (data->parse_data.map_fd < 0)
	{
		delete_structs(data, 6);
		printf("Error: Map file path not found or unable to open!\n");
		exit(1);
	}
	return ;
}

int	is_mapline(char *str)
{
	int	i;
	int	map_content;

	i = 0;
	map_content = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '1' || str[i] == '0')
			map_content++;
		i++;
	}
	if (map_content > 0)
		return (1);
	else
		return (0);
}

void	get_map_height(t_data *data)
{
	int gnl_return;

	data->map_height = 0;
	data->map_width = (int)ft_strlen(data->parse_data.line);
	gnl_return = 0;
	while (is_mapline(data->parse_data.line))
	{
		free(data->parse_data.line);
		gnl_return = get_next_line(data->parse_data.map_fd, &data->parse_data.line);
		if ((int)ft_strlen(data->parse_data.line) > data->map_width)
			data->map_width = (int)ft_strlen(data->parse_data.line);
		data->map_height++;
	}
	while (gnl_return != 0)
	{
		free(data->parse_data.line);
		gnl_return = get_next_line(data->parse_data.map_fd, &data->parse_data.line);
		if (ft_strlen(data->parse_data.line) != 0)
			invalid_line_exit(data, "Garbage or non-empty lines after unverified map.", 1);
	}
	free(data->parse_data.line);
	return ;
}

void	grab_map_height(t_data *data)
{
	int gnl_return;

	gnl_return = 1;
	data->map_height = 0;
	if (is_mapline(data->parse_data.line))
		get_map_height(data);
	else
	{
		data->map_begin++;
		while (!is_mapline(data->parse_data.line) && gnl_return != 0 && ft_strlen(data->parse_data.line) == 0)
		{
			data->map_begin++;
			free(data->parse_data.line);
			gnl_return = get_next_line(data->parse_data.map_fd, &data->parse_data.line);
		}
		if (gnl_return == 0)
			invalid_line_exit(data, "Missing map in mapfile.cub", 1);
		else
			get_map_height(data);
	}
	close(data->parse_data.map_fd);
	printf("Map height: %d\nMapBegins on line: %d\n", data->map_height, data->map_begin);
	return ;
}

void	map_check_init(char **argv, t_data *data)
{
	check_map_filepath(argv, data);
	pre_map_check(data);
	grab_map_height(data);
	grab_map(argv, data);
	check_map(data);
	return ;
}

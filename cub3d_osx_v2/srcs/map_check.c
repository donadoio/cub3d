/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_check.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/01 16:13:36 by idonado       #+#    #+#                 */
/*   Updated: 2021/11/01 17:32:38 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include <fcntl.h>

static void	check_map_filepath(char **argv, t_data *data)
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

void	map_check(char **argv, t_data *data)
{
	check_map_filepath(argv, data);
	pre_map_check(data);
	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pre_map_check_e.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/03 18:53:55 by idonado       #+#    #+#                 */
/*   Updated: 2021/11/03 19:15:06 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	floor_ceiling_rgb(t_data *data, int *action, char c)
{
	if (c == 'C')
	{
		data->ceiling_color = rgb_to_hex(data->temp, data);
		data->parse_data.ceiling_set = 1;
		*action = 1;
	}
	else if (c == 'F')
	{
		data->floor_color = rgb_to_hex(data->temp, data);
		data->parse_data.floor_set = 1;
		*action = 1;
	}
	return ;
}

void	check_ceiling(t_data *data, int *action)
{
	data->error = "Error: Invalid line on RGB color for ceiling.";
	data->temp = data->parse_data.line;
	while (*data->temp == ' ')
		data->temp++;
	if (*data->temp == 'C')
	{
		data->temp++;
		if (*data->temp != ' ')
			invalid_line_exit(data, data->error, 1);
		while (*data->temp == ' ')
			data->temp++;
		if (ft_isdigit(*data->temp))
		{
			if (rgb_to_hex(data->temp, data) > 0)
			{
				floor_ceiling_rgb(data, action, 'C');
				return ;
			}
			else
				invalid_line_exit(data, data->error, 1);
		}
		else
			invalid_line_exit(data, data->error, 1);
	}
}

void	check_floor(t_data *data, int *action)
{
	data->error = "Error: Invalid line on RGB color for floor.";
	data->temp = data->parse_data.line;
	while (*data->temp == ' ')
		data->temp++;
	if (*data->temp == 'F')
	{
		data->temp++;
		if (*data->temp != ' ')
			invalid_line_exit(data, data->error, 1);
		while (*data->temp == ' ')
			data->temp++;
		if (ft_isdigit(*data->temp))
		{
			if (rgb_to_hex(data->temp, data) > 0)
			{
				floor_ceiling_rgb(data, action, 'F');
				return ;
			}
			else
				invalid_line_exit(data, data->error, 1);
		}
		else
			invalid_line_exit(data, data->error, 1);
	}
}

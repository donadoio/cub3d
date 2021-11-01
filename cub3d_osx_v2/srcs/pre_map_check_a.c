/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pre_map_check_a.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/01 17:32:21 by idonado       #+#    #+#                 */
/*   Updated: 2021/11/01 20:18:24 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	invalid_line_exit(t_data *data, char *msg)
{
	if (msg != NULL)
		printf("%s\n", msg);
	free(data->parse_data.line);
	close(data->parse_data.map_fd);
	delete_and_destroy_all(data);
	exit (1);
}

int	rgb_to_hex(char *decimals)
{
	char	**rgb;
	int		r;
	int		g;
	int		b;
	int		i;

	i = 0;
	rgb = ft_split(decimals, ',');
	while (rgb[i])
	{
		if (ft_str_isnum(rgb[i]) == 0)
		{
			printf("r g or b isn't a number?\n");
			free_split(rgb);
			return (-1);
		}
		if (i == 0)
			r = ft_atoi(rgb[i]);
		else if (i == 1)
			g = ft_atoi(rgb[i]);
		else if (i == 2)
			b = ft_atoi(rgb[i]);
		if (ft_atoi(rgb[i]) < 0 || ft_atoi(rgb[i]) > 255)
		{
			free_split(rgb);
			printf("smaller tahn 0 or bigger than 255?\n");
			return (-1);
		}
		i++;
	}
	free_split(rgb);
	if (i != 3)
	{
		printf("splitted more than 3?\n");
		return (-1);
	}
	else
		return (create_trgb(0, r, g, b));
}

void	check_ceiling_floor(t_data *data, int *action)
{
	char	*temp;

	temp = data->parse_data.line;
	while (*temp == ' ')
		temp++;
	if (*temp == 'C')
	{
		temp++;
		if (*temp != ' ')
			invalid_line_exit(data, "Error: Invalid line on RGB color for ceiling.");
		while (*temp == ' ')
			temp++;
		if (ft_isdigit(*temp))
		{
			if (rgb_to_hex(temp) > 0)
			{
				data->ceiling_color = rgb_to_hex(temp);
				data->parse_data.ceiling_set = 1;
				*action = 1;
				return ;
			}
			else
				invalid_line_exit(data, "Error: Invalid line on RGB color for ceiling.");
		}
		else
			invalid_line_exit(data, "Error: Invalid line on RGB color for ceiling.");
	}
	else if (*temp == 'F')
	{
		temp++;
		if (*temp != ' ')
			invalid_line_exit(data, "Error: Invalid line on RGB color for floor.");
		while (*temp == ' ')
			temp++;
		if (ft_isdigit(*temp))
		{
			if (rgb_to_hex(temp) > 0)
			{
				data->floor_color = rgb_to_hex(temp);
				data->parse_data.floor_set = 1;
				*action = 1;
				return ;
			}
			else
				invalid_line_exit(data, "Error: Invalid line on RGB color for floor.");
		}
		else
			invalid_line_exit(data, "Error: Invalid line on RGB color for floor.");
	}
	return ;	
}

void	pre_map_check(t_data *data)
{
	int	action;

	while (data->parse_data.all_set == 0 && get_next_line(data->parse_data.map_fd, &data->parse_data.line) != 0)
	{
		printf("Line-> %s\n", data->parse_data.line);


		action = 0;	
		if (ft_strlen(data->parse_data.line) != 0 && (data->parse_data.ceiling_set == 0 || data->parse_data.floor_set == 0))
			check_ceiling_floor(data, &action);

		if (data->parse_data.ceiling_set == 1 && data->parse_data.floor_set == 1)
			data->parse_data.all_set = 1;
			
		if (action == 0 && data->parse_data.all_set == 0 && ft_strlen(data->parse_data.line) != 0)
		{
			printf("Error, garbage or empty lines with spaces in mapfile.cub\n");
			exit (0);
		}
		free(data->parse_data.line);
		if (data->parse_data.all_set == 1)
			return ;
	}
	free(data->parse_data.line);
}
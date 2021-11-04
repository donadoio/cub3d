/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pre_map_check_a.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/01 17:32:21 by idonado       #+#    #+#                 */
/*   Updated: 2021/11/03 16:17:38 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	invalid_line_exit(t_data *data, char *msg, int free_line)
{
	if (msg != NULL)
		printf("%s\n", msg);
	if (free_line)
		free(data->parse_data.line);
	close(data->parse_data.map_fd);
	delete_and_destroy_all(data);
	system("leaks cub3d");
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
			return (-1);
		}
		i++;
	}
	free_split(rgb);
	if (i != 3)
		return (-1);
	else
		return (create_trgb(0, r, g, b));
}

void	check_ceiling(t_data *data, int *action)
{
	char	*temp;

	temp = data->parse_data.line;
	while (*temp == ' ')
		temp++;
	if (*temp == 'C')
	{
		temp++;
		if (*temp != ' ')
			invalid_line_exit(data, "Error: Invalid line on RGB color for ceiling.", 1);
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
				invalid_line_exit(data, "Error: Invalid line on RGB color for ceiling.", 1);
		}
		else
			invalid_line_exit(data, "Error: Invalid line on RGB color for ceiling.", 1);
	}
	return ;	
}

void	check_floor(t_data *data, int *action)
{
	char	*temp;

	temp = data->parse_data.line;
	while (*temp == ' ')
		temp++;
	if (*temp == 'F')
	{
		temp++;
		if (*temp != ' ')
			invalid_line_exit(data, "Error: Invalid line on RGB color for floor.", 1);
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
				invalid_line_exit(data, "Error: Invalid line on RGB color for floor.", 1);
		}
		else
			invalid_line_exit(data, "Error: Invalid line on RGB color for floor.", 1);
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
		if (ft_strlen(data->parse_data.line) != 0 && data->parse_data.ceiling_set == 0)
			check_ceiling(data, &action);
		if (ft_strlen(data->parse_data.line) != 0 && data->parse_data.floor_set == 0)
			check_floor(data, &action);
		if (ft_strlen(data->parse_data.line) != 0 && data->parse_data.text_one_set == 0)
			check_north(data, &action);
		if (ft_strlen(data->parse_data.line) != 0 && data->parse_data.text_two_set == 0)
			check_south(data, &action);
		if (ft_strlen(data->parse_data.line) != 0 && data->parse_data.text_three_set == 0)
			check_west(data, &action);
		if (ft_strlen(data->parse_data.line) != 0 && data->parse_data.text_four_set == 0)
			check_east(data, &action);
		data->map_begin++;
		if (data->parse_data.ceiling_set == 1 && data->parse_data.floor_set == 1 && data->parse_data.text_one_set == 1 && data->parse_data.text_two_set == 1 && data->parse_data.text_three_set == 1 && data->parse_data.text_four_set == 1)
			data->parse_data.all_set = 1;
			
		if (action == 0 && data->parse_data.all_set == 0 && ft_strlen(data->parse_data.line) != 0)
		{
			invalid_line_exit(data, "Error, garbage or extra info or empty lines with spaces in mapfile.cub", 1);
			exit (0);
		}
		free(data->parse_data.line);
	}
	if (data->parse_data.all_set != 1)
		invalid_line_exit(data, "Invalid or incomplete data in map file.", 1);
	else
		get_next_line(data->parse_data.map_fd, &data->parse_data.line);
}
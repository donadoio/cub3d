/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pre_map_check_a.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/01 17:32:21 by idonado       #+#    #+#                 */
/*   Updated: 2021/11/04 17:59:11 by idonado       ########   odam.nl         */
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
	exit (1);
}

int	valid_last_rgb(char *blue)
{
	int	i;

	i = 0;
	if (!ft_isdigit(blue[i]))
		return (0);
	while (ft_isdigit(blue[i]))
		i++;
	while (blue[i] == ' ')
		i++;
	if (blue[i] != '\0')
		return (0);
	else
		return (1);
}

static void	pre_map_check_b(t_data *data, int *action)
{
	if (ft_strlen(data->parse_data.line) != 0 && \
data->parse_data.ceiling_set == 0)
		check_ceiling(data, action);
	if (ft_strlen(data->parse_data.line) != 0 && \
data->parse_data.floor_set == 0)
		check_floor(data, action);
	if (ft_strlen(data->parse_data.line) != 0 && \
data->parse_data.text_one_set == 0)
		check_north(data, action);
	if (ft_strlen(data->parse_data.line) != 0 && \
data->parse_data.text_two_set == 0)
		check_south(data, action);
	if (ft_strlen(data->parse_data.line) != 0 && \
data->parse_data.text_three_set == 0)
		check_west(data, action);
	if (ft_strlen(data->parse_data.line) != 0 && \
data->parse_data.text_four_set == 0)
		check_east(data, action);
	data->map_begin++;
	if (data->parse_data.ceiling_set == 1 && data->parse_data.floor_set == \
1 && data->parse_data.text_one_set == 1 && data->parse_data.text_two_set == \
1 && data->parse_data.text_three_set == 1 && \
data->parse_data.text_four_set == 1)
		data->parse_data.all_set = 1;
	return ;
}

void	pre_map_check(t_data *data)
{
	int	action;

	while (data->parse_data.all_set == 0 && \
get_next_line(data->parse_data.map_fd, &data->parse_data.line) != 0)
	{
		action = 0;
		pre_map_check_b(data, &action);
		if (action == 0 && data->parse_data.all_set == \
0 && ft_strlen(data->parse_data.line) != 0)
			invalid_line_exit(data, "Error, \
garbage or extra info or empty lines with spaces in mapfile.cub", 1);
		free(data->parse_data.line);
	}
	if (data->parse_data.all_set != 1)
		invalid_line_exit(data, "Invalid or incomplete data in map file.", 1);
	else
		get_next_line(data->parse_data.map_fd, &data->parse_data.line);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pre_map_check_c.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/03 18:30:07 by idonado       #+#    #+#                 */
/*   Updated: 2021/11/03 18:36:04 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	check_north_b(t_data *data, char *temp)
{
	data->texture_1->img = mlx_xpm_file_to_image(data->mlx->mlx, \
	temp, &data->texture_1->width, \
	&data->texture_1->height);
	if (data->texture_1->img == NULL)
		invalid_line_exit(data, "Error: Invalid North wall \
texture location.", 1);
	data->texture_1->addr = mlx_get_data_addr(data->texture_1->img, \
&data->texture_1->bits_per_pixel, \
&data->texture_1->line_length, &data->texture_1->endian);
	data->parse_data.text_one_set = 1;
	return ;
}

void	check_north(t_data *data, int *action)
{
	char	*temp;

	temp = data->parse_data.line;
	while (*temp == ' ')
		temp++;
	if (*temp == 'N' && ft_strlen(temp) > 2)
	{
		temp++;
		if (*temp != 'O')
			return ;
		temp++;
		if (*temp != ' ')
			invalid_line_exit(data, "Error: Invalid line on North Texture.", 1);
		while (*temp == ' ')
			temp++;
		if (!fix_temp_path(temp))
			invalid_line_exit(data, \
"Error: Invalid north wall texture location.", 1);
		check_north_b(data, temp);
		*action = 1;
	}
	return ;
}

static void	check_south_b(t_data *data, char *temp)
{
	data->texture_2->img = mlx_xpm_file_to_image(data->mlx->mlx, \
	temp, &data->texture_2->width, \
	&data->texture_2->height);
	if (data->texture_2->img == NULL)
		invalid_line_exit(data, "Error: \
Invalid south wall texture location.", 1);
	data->texture_2->addr = mlx_get_data_addr(data->texture_2->img, \
&data->texture_2->bits_per_pixel, \
&data->texture_2->line_length, &data->texture_2->endian);
	data->parse_data.text_two_set = 1;
	return ;
}

void	check_south(t_data *data, int *action)
{
	char	*temp;

	temp = data->parse_data.line;
	while (*temp == ' ')
		temp++;
	if (*temp == 'S' && ft_strlen(temp) > 2)
	{
		temp++;
		if (*temp != 'O')
			return ;
		temp++;
		if (*temp != ' ')
			invalid_line_exit(data, "Error: \
Invalid line on South Texture.", 1);
		while (*temp == ' ')
			temp++;
		if (!fix_temp_path(temp))
			invalid_line_exit(data, "Error: \
Invalid east wall texture location.", 1);
		check_south_b(data, temp);
		*action = 1;
	}
	return ;
}

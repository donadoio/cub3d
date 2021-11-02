/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pre_map_check_b.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/01 17:33:48 by idonado       #+#    #+#                 */
/*   Updated: 2021/11/02 19:20:08 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

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
		data->texture_1->img = mlx_xpm_file_to_image(data->mlx->mlx, \
		temp, &data->texture_1->width, \
		&data->texture_1->height);
		if (data->texture_1->img == NULL)
			invalid_line_exit(data, "Error: Invalid North wall texture location.", 1);
		data->texture_1->addr = mlx_get_data_addr(data->texture_1->img, &data->texture_1->bits_per_pixel, &data->texture_1->line_length, &data->texture_1->endian);
		data->parse_data.text_one_set = 1;
		*action = 1;
	}
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
			invalid_line_exit(data, "Error: Invalid line on South Texture.", 1);
		while (*temp == ' ')
			temp++;
		data->texture_2->img = mlx_xpm_file_to_image(data->mlx->mlx, \
		temp, &data->texture_2->width, \
		&data->texture_2->height);
		if (data->texture_2->img == NULL)
			invalid_line_exit(data, "Error: Invalid south wall texture location.", 1);
		data->texture_2->addr = mlx_get_data_addr(data->texture_2->img, &data->texture_2->bits_per_pixel, &data->texture_2->line_length, &data->texture_2->endian);
		data->parse_data.text_two_set = 1;
		*action = 1;
	}
	return ;
}

void	check_west(t_data *data, int *action)
{
	char	*temp;

	temp = data->parse_data.line;
	while (*temp == ' ')
		temp++;
	if (*temp == 'W' && ft_strlen(temp) > 2)
	{
		temp++;
		if (*temp != 'E')
			return ;
		temp++;
		if (*temp != ' ')
			invalid_line_exit(data, "Error: Invalid line on west Texture.", 1);
		while (*temp == ' ')
			temp++;
		data->texture_3->img = mlx_xpm_file_to_image(data->mlx->mlx, \
		temp, &data->texture_3->width, \
		&data->texture_3->height);
		if (data->texture_3->img == NULL)
			invalid_line_exit(data, "Error: Invalid west wall texture location.", 1);
		data->texture_3->addr = mlx_get_data_addr(data->texture_3->img, &data->texture_3->bits_per_pixel, &data->texture_3->line_length, &data->texture_3->endian);
		data->parse_data.text_three_set = 1;
		*action = 1;
	}
	return ;
}

void	check_east(t_data *data, int *action)
{
	char	*temp;

	temp = data->parse_data.line;
	while (*temp == ' ')
		temp++;
	if (*temp == 'E' && ft_strlen(temp) > 2)
	{
		temp++;
		if (*temp != 'A')
			return ;
		temp++;
		if (*temp != ' ')
			invalid_line_exit(data, "Error: Invalid line on east Texture.", 1);
		while (*temp == ' ')
			temp++;
		data->texture_4->img = mlx_xpm_file_to_image(data->mlx->mlx, \
		temp, &data->texture_4->width, \
		&data->texture_4->height);
		if (data->texture_4->img == NULL)
			invalid_line_exit(data, "Error: Invalid east wall texture location.", 1);
		data->texture_4->addr = mlx_get_data_addr(data->texture_4->img, &data->texture_4->bits_per_pixel, &data->texture_4->line_length, &data->texture_4->endian);
		data->parse_data.text_four_set = 1;
		*action = 1;
	}
	return ;
}
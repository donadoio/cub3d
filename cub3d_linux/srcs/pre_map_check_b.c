/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pre_map_check_b.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/01 17:33:48 by idonado       #+#    #+#                 */
/*   Updated: 2021/11/03 18:39:14 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	fix_temp_path(char *temp)
{
	int	i;

	i = 0;
	while (temp[i] && temp[i] != ' ')
		i++;
	if (temp[i] == ' ')
	{
		temp[i] = '\0';
		i++;
		while (temp[i] == ' ')
			i++;
	}
	if (temp[i] == '\0')
		return (1);
	else
		return (0);
}

static void	check_west_b(t_data *data, char *temp)
{
	data->texture_3->img = mlx_xpm_file_to_image(data->mlx->mlx, \
	temp, &data->texture_3->width, \
	&data->texture_3->height);
	if (data->texture_3->img == NULL)
		invalid_line_exit(data, "Error: \
Invalid west wall texture location.", 1);
	data->texture_3->addr = mlx_get_data_addr(data->texture_3->img, \
&data->texture_3->bits_per_pixel, \
&data->texture_3->line_length, &data->texture_3->endian);
	data->parse_data.text_three_set = 1;
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
			invalid_line_exit(data, "Error: \
Invalid line on west Texture.", 1);
		while (*temp == ' ')
			temp++;
		if (!fix_temp_path(temp))
			invalid_line_exit(data, "Error: \
Invalid east wall texture location.", 1);
		check_west_b(data, temp);
		*action = 1;
	}
	return ;
}

static void	check_east_b(t_data *data, char *temp)
{
	data->texture_4->img = mlx_xpm_file_to_image(data->mlx->mlx, \
	temp, &data->texture_4->width, \
	&data->texture_4->height);
	if (data->texture_4->img == NULL)
		invalid_line_exit(data, "Error: \
Invalid east wall texture location.", 1);
	data->texture_4->addr = mlx_get_data_addr(data->texture_4->img, \
&data->texture_4->bits_per_pixel, \
&data->texture_4->line_length, &data->texture_4->endian);
	data->parse_data.text_four_set = 1;
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
			invalid_line_exit(data, "Error: \
Invalid line on east Texture.", 1);
		while (*temp == ' ')
			temp++;
		if (!fix_temp_path(temp))
			invalid_line_exit(data, "Error: \
Invalid east wall texture location.", 1);
		check_east_b(data, temp);
		*action = 1;
	}
	return ;
}

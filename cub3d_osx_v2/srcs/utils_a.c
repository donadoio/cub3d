/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils_a.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/01 16:56:17 by idonado       #+#    #+#                 */
/*   Updated: 2021/11/02 18:50:35 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	ft_str_isnum(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	free_split(char **words)
{
	int	i;

	i = 0;
	while (words[i])
	{
		free(words[i]);
		i++;
	}
	free(words[i]);
	free(words);
	return ;
}

int	delete_structs(t_data *data, int count)
{
	if (count > 0)
		free(data->mlx);
	if (count > 1)
		free(data->img);
	if (count > 2)
		free(data->texture_1);
	if (count > 3)
		free(data->texture_2);
	if (count > 4)
		free(data->texture_3);
	if (count > 5)
		free(data->texture_4);
	free(data);
	return (0);
}

void	delete_and_destroy_all(t_data *data)
{
	if (data->parse_data.text_one_set == 1)
		mlx_destroy_image(data->mlx->mlx, data->texture_1->img);
	if (data->parse_data.text_two_set == 1)
		mlx_destroy_image(data->mlx->mlx, data->texture_2->img);
	if (data->parse_data.text_three_set == 1)
		mlx_destroy_image(data->mlx->mlx, data->texture_3->img);
	if (data->parse_data.text_four_set == 1)
		mlx_destroy_image(data->mlx->mlx, data->texture_4->img);
	if (data->parse_data.main_img_set == 1)
	{
		mlx_destroy_image(data->mlx->mlx, data->img->img);
		delete_structs(data, 6);
	}
	return ;
}
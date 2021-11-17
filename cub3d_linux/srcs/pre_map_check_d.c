/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pre_map_check_d.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/03 18:41:12 by idonado       #+#    #+#                 */
/*   Updated: 2021/11/03 18:56:55 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static int	rgb_to_hex_b(t_data *data, int *current)
{
	int	i;

	i = *current;
	if (ft_str_isnum(data->rgb[i]) == 0 && i != 2)
		return (0);
	if (i == 2 && !valid_last_rgb(data->rgb[i]))
		return (0);
	if (i == 0)
		data->r = ft_atoi(data->rgb[i]);
	else if (i == 1)
		data->g = ft_atoi(data->rgb[i]);
	else if (i == 2)
		data->b = ft_atoi(data->rgb[i]);
	if (ft_atoi(data->rgb[i]) < 0 || ft_atoi(data->rgb[i]) > 255)
		return (0);
	return (1);
}

int	rgb_to_hex(char *decimals, t_data *data)
{
	int		i;

	i = 0;
	data->rgb = ft_split(decimals, ',');
	while (data->rgb[i])
	{
		if (!rgb_to_hex_b(data, &i))
		{
			free_split(data->rgb);
			return (-1);
		}
		i++;
	}
	free_split(data->rgb);
	if (i != 3)
		return (-1);
	else
		return (create_trgb(0, data->r, data->g, data->b));
}

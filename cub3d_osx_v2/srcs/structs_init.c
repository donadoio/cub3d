/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   structs_init.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/30 18:04:11 by idonado       #+#    #+#                 */
/*   Updated: 2021/10/30 18:16:13 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static int	structs_fail(t_data *data, int count)
{
	free(data);
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
	return (0);
}


int	structs_init(t_data *data)
{
	data->mlx = malloc(sizeof(t_mlx_vars));
	if (data->mlx == NULL)
		return (structs_fail(data, 0));
	data->img = malloc(sizeof(t_img_data));
	if (data->img == NULL)
		return (structs_fail(data, 1));
	data->texture_1 = malloc(sizeof(t_img_data));
	if (data->texture_1 == NULL)
		return (structs_fail(data, 2));
	data->texture_2 = malloc(sizeof(t_img_data));
	if (data->texture_2 == NULL)
		return (structs_fail(data, 3));
	data->texture_3 = malloc(sizeof(t_img_data));
	if (data->texture_3 == NULL)
		return (structs_fail(data, 4));
	data->texture_4 = malloc(sizeof(t_img_data));
	if (data->texture_4 == NULL)
		return (structs_fail(data, 5));
	return (1);
}

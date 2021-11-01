/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   structs_init.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/30 18:04:11 by idonado       #+#    #+#                 */
/*   Updated: 2021/11/01 17:06:47 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	parse_data_init(t_data *data)
{
	data->parse_data.main_img_set = 0;
	data->parse_data.text_one_set = 0;
	data->parse_data.text_two_set = 0;
	data->parse_data.text_three_set = 0;
	data->parse_data.text_four_set = 0;
	data->parse_data.ceiling_set = 0;
	data->parse_data.floor_set = 0;
	data->parse_data.map_set = 0;
	data->parse_data.all_set = 0;
}

int	structs_init(t_data *data)
{
	parse_data_init(data);
	data->mlx = malloc(sizeof(t_mlx_vars));
	if (data->mlx == NULL)
		return (delete_structs(data, 0));
	data->img = malloc(sizeof(t_img_data));
	if (data->img == NULL)
		return (delete_structs(data, 1));
	data->texture_1 = malloc(sizeof(t_img_data));
	if (data->texture_1 == NULL)
		return (delete_structs(data, 2));
	data->texture_2 = malloc(sizeof(t_img_data));
	if (data->texture_2 == NULL)
		return (delete_structs(data, 3));
	data->texture_3 = malloc(sizeof(t_img_data));
	if (data->texture_3 == NULL)
		return (delete_structs(data, 4));
	data->texture_4 = malloc(sizeof(t_img_data));
	if (data->texture_4 == NULL)
		return (delete_structs(data, 5));
	return (1);
}

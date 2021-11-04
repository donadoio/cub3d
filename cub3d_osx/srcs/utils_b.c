/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils_b.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/03 19:26:00 by idonado       #+#    #+#                 */
/*   Updated: 2021/11/03 20:00:32 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	safe_exit(t_data *data, char *msg)
{
	if (msg != NULL)
		printf("%s\n", msg);
	delete_and_destroy_all(data);
	exit (0);
}

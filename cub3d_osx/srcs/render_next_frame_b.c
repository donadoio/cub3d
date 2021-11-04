/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_next_frame_b.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/03 17:39:45 by idonado       #+#    #+#                 */
/*   Updated: 2021/11/03 17:44:15 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

//Checks which wall the ray hits to 'load' the necessary
//texture to the loaded texture image pointer
void	texture_setter(t_data *data)
{
	if (0 > data->step_x && data->side == 0 && data->text_number != 1)
	{
		data->loaded_texture = data->texture_1;
		data->text_number = 1;
	}
	else if (0 <= data->step_x && data->side == 0 && data->text_number != 2)
	{
		data->loaded_texture = data->texture_2;
		data->text_number = 2;
	}
	else if (data->side == 1)
	{
		if (0 > data->step_y && data->text_number != 3)
		{
			data->loaded_texture = data->texture_3;
			data->text_number = 3;
		}
		else if (0 <= data->step_y && data->text_number != 4)
		{
			data->loaded_texture = data->texture_4;
			data->text_number = 4;
		}
	}
	return ;
}

//Fetches the height of the vertical line to be drawn on the window and saves
//where the wall begins and ends to use when drawing
void	vertical_line_calc(t_data *data)
{
	if (data->side == 0)
		data->perp_wall_dist = (data->side_dist_x - data->delta_dist_x);
	else
		data->perp_wall_dist = (data->side_dist_y - data->delta_dist_y);
	data->line_height = (int)(WINHEIGHT / data->perp_wall_dist);
	data->draw_start = (-data->line_height / 2) + (WINHEIGHT / 2);
	if (data->draw_start < 0)
		data->draw_start = 0;
	data->draw_end = (data->line_height / 2) + (WINHEIGHT / 2);
	if (data->draw_end >= WINHEIGHT)
		data->draw_end = WINHEIGHT - 1;
	return ;
}

//Called by draw_window_line to draw the pixel from the needed texture
static void	draw_window_line_text(t_data *data)
{
	if (data->draw_start < data->draw_end && data->draw_end >= 0 && \
data->draw_start >= 0)
	{
		while (data->y < data->draw_end)
		{
			data->d = data->y * 256 - WINHEIGHT * 128 + data->line_height * 128;
			data->tex_y = ((data->d * data->loaded_texture->height) / \
data->line_height) / 256;
			data->i = 0;
			while (data->i < 3)
			{
				data->img->addr[data->y * data->img->line_length + data->x * \
data->img->bits_per_pixel / 8 + data->i] = \
data->loaded_texture->addr[data->tex_y * \
data->loaded_texture->line_length + data->tex_x * \
data->loaded_texture->bits_per_pixel / 8 + data->i];
				data->i++;
			}
			data->y++;
		}
	}
}

//Draws the actual vertical line using all the values stored
//before moving on to the next x coordinate of the window
void	draw_window_line(t_data *data)
{
	data->vert_line_color = data->ceiling_color;
	if (0 < data->draw_start && data->draw_start >= 0)
		draw_vertical_line(data, data->x, 0, data->draw_start);
	if (data->side == 0)
		data->wall_x = data->pos_y + data->perp_wall_dist * data->ray_dir_y;
	else
		data->wall_x = data->pos_x + data->perp_wall_dist * data->ray_dir_x;
	data->wall_x = data->wall_x - floor(data->wall_x);
	data->tex_x = (int)(data->wall_x * (double)data->loaded_texture->width);
	if (data->side == 0 && data->ray_dir_x > 0)
		data->tex_x = data->loaded_texture->width - data->tex_x - 1;
	if (data->side == 1 && data->ray_dir_y < 0)
		data->tex_x = data->loaded_texture->width - data->tex_x - 1;
	data->y = data->draw_start;
	draw_window_line_text(data);
	data->vert_line_color = data->floor_color;
	if (data->draw_end < WINHEIGHT && data->draw_end >= 0)
		draw_vertical_line(data, data->x, data->draw_end, (WINHEIGHT));
}

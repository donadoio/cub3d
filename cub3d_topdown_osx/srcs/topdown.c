#include <cub3d.h>

void	clear_player(t_data *data, float pos_x, float pos_y)
{
	int	i;
	int	j;

	i = -5;
	while (i < 5)
	{
		j = -5;
		while (j < 5)
		{
			my_mlx_pixel_put(data->img, pos_x + i, pos_y + j, 0x00000000);
			j++;
		}
		i++;
	}
	return ;
}

void	draw_player(t_data *data, float pos_x, float pos_y)
{
	int	i;
	int	j;

	i = -5;
	while (i < 5)
	{
		j = -5;
		while (j < 5)
		{
			my_mlx_pixel_put(data->img, pos_x + i, pos_y + j, 0x0000FFFF);
			j++;
		}
		i++;
	}
	return ;
}

static void	draw_wall_block(t_data *data, int x, int y)
{
	int x1;
	int y1;

	x1 = x * BLOCKSIZEWIDTH - 1;
	y1 = y * BLOCKSIZEHEIGHT - 1;
	x = x1 - BLOCKSIZEWIDTH - 1;
	y = y1 - BLOCKSIZEHEIGHT - 1;
	while (x <= x1)
	{
		y = y1 - BLOCKSIZEHEIGHT - 1;
		while (y <= y1)
		{
			my_mlx_pixel_put(data->img, x, y, 0x00FFFFFF);
			y++;
		}
		x++;
	}
	return ;
}

void	draw_map(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	x = 0;

	while (y < 24)
	{
		x = 0;
		while (x < 24)
		{
			if (data->map[y][x] == 1)
			{
				draw_wall_block(data, x + 1, y + 1);
			}
			x++;
		}
		y++;
	}
	return ;
}
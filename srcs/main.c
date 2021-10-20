/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/21 19:12:50 by idonado       #+#    #+#                 */
/*   Updated: 2021/10/20 20:26:38 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include <keycodes_osx.h>

int	render_next_frame(t_img_data	*img)
{
	(void)img;
	return (0);
}

int	keypressed(int keycode, t_img_data	*img)
{
	(void)img;
	if (keycode == UP_KEY)
	{
		printf("UP");
	}
	else if (keycode == DOWN_KEY)
	{
		printf("DOWN");
	}
	else if (keycode == LEFT_KEY)
	{
		printf("LEFT");
	}
	else if (keycode == RIGHT_KEY)
	{
		printf("RIGHT");
	}
	return (0);
}

//void	draw_map(t_mlx_vars mlx, t_img_data img, int **worldmap)
//{
//	int i;
//
//	i = 0;
//	
//}

void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_wall(t_data *data, int x, int y, int sq)
{
	int x1;
	int y1;

	x1 = x * sq;
	y1 = y * sq;
	x = x1 - sq;
	y = y1 - sq;
	while (x <= x1)
	{
		y = y1 - sq;
		while (y <= y1)
		{
			my_mlx_pixel_put(data->img, x, y, 0x00FFFFFF);
			y++;
		}
		x++;
	}
	return ;
}

void	draw_map(t_data *data, int	**worldmap)
{
	int	sq_width;
	int	sq_height;
	int	x;
	int	y;

	sq_width = 800 / 24;
	sq_height = 800 / 24;
	x = 0;
	(void)worldmap;
	while (x <= 24)
	{
		y = 0;
		while (y < 24)
		{
			if (worldmap[y][x] == 1)
			{
				draw_wall(data, x + 1, y + 1, sq_height);
			}
			//if (x == 0 || y == 0 || x == 799 || y == 799 || (y % sq_height  == 0) || (x % sq_width  == 0))
			//	my_mlx_pixel_put(data->img, x, y, 0x00F1F1F1);
			y++;
		}
		x++;
	}
}

int	**build_map(void)
{
	int	**worldmap;
	int	i;
	int	j;

	worldmap = malloc(sizeof(int *) * 24);
	i = 0;
	while (i < 24)
	{
		j = 0;
		worldmap[i] = malloc(sizeof(int) * 24);
		while (j < 24)
		{
			if (i == 0 || i == 23 || j == 0 || j == 23)
				worldmap[i][j] = 1;
			else
				worldmap[i][j] = 0;
			j++;
		}
		i++;
	}
	i = 0;
	j = 0;
	while (i < 24)
	{
		j = 0;
		while (j < 24)
		{
			printf("%d", worldmap[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	return (worldmap);
}

int	main(void)
{
	t_data	*data;
	int **worldmap;
	
	worldmap = NULL;
	worldmap = build_map();
	data = malloc(sizeof(t_data));
	data->mlx = malloc(sizeof(t_mlx_vars));
	data->img = malloc(sizeof(t_img_data));

	data->mlx->mlx = mlx_init();
	data->mlx->mlx_window = mlx_new_window(data->mlx->mlx, 800, 800, "cub3d");
	data->img->img = mlx_new_image(data->mlx->mlx, 800, 800);
	data->img->addr = mlx_get_data_addr(data->img->img, &data->img->bits_per_pixel, &data->img->line_length, &data->img->endian);
	draw_map(data, worldmap);
	mlx_put_image_to_window(data->mlx->mlx, data->mlx->mlx_window, data->img->img, 0, 0);
	mlx_loop(data->mlx->mlx);
	return (0);
}

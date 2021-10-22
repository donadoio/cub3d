/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/21 19:12:50 by idonado       #+#    #+#                 */
/*   Updated: 2021/10/22 21:04:20 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include <keycodes_osx.h>

#define mapWidth 24
#define mapHeight 24


int	render_next_frame(t_data *data)
{
	draw_player(data, data->pos_x, data->pos_y);
	draw_line(data, data->pos_x, data->pos_y, data->pdx, data->pdy, 0x0000FFFF);
	mlx_put_image_to_window(data->mlx->mlx, data->mlx->mlx_window, data->img->img, 0, 0);
	usleep(500);
	return (0);
}

int	keypressed(int keycode, t_data	*data)
{
	if (keycode == UP_KEY)
	{
		printf("UP\n");
		clear_player(data, data->pos_x, data->pos_y);
		data->pos_y -= 5;
	}
	else if (keycode == DOWN_KEY)
	{
		printf("DOWN\n");
		clear_player(data, data->pos_x, data->pos_y);
		data->pos_y += 5;
	}
	else if (keycode == LEFT_KEY)
	{
		printf("LEFT\n");
		clear_player(data, data->pos_x, data->pos_y);
		data->pos_x -= 5;
	}
	else if (keycode == RIGHT_KEY)
	{
		printf("RIGHT\n");
		clear_player(data, data->pos_x, data->pos_y);
		data->pos_x += 5;
	}
	else if (keycode == 123)
	{
		data->pa -= 0.1;
		if (data->pa < 0)
			data->pa += 2 * PI;
		data->pdx = cos(data->pa) * 25;
		data->pdy = sin(data->pa) * 25;
	}
	else if (keycode == 124)
	{
		data->pa += 0.1;
		if (data->pa > 2 * PI)
			data->pa -= 2 * PI;
		data->pdx = cos(data->pa) * 25;
		data->pdy = sin(data->pa) * 25;
	}
	return (0);
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
	return (worldmap);
}

int	main(void)
{
	t_data	*data;
	
	data = malloc(sizeof(t_data));
	data->mlx = malloc(sizeof(t_mlx_vars));
	data->img = malloc(sizeof(t_img_data));

	data->map = build_map();
	print_map(data);

	//initializing mlx and image
	data->mlx->mlx = mlx_init();
	data->mlx->mlx_window = mlx_new_window(data->mlx->mlx, WINWIDTH, WINHEIGHT, "cub3d");
	data->img->img = mlx_new_image(data->mlx->mlx, WINWIDTH, WINHEIGHT);
	data->img->addr = mlx_get_data_addr(data->img->img, &data->img->bits_per_pixel, &data->img->line_length, &data->img->endian);

	//draw_line(data, 10, 10, 160, 130, 0x00FF00FF);

	//giving default position coordinates
	data->pos_x = 200;
	data->pos_y = 200;

	// delta x and y for direction angle
	data->pdx = cos(data->pa);
	data->pdy = sin(data->pa);

	// key hooks and game loop
	draw_map(data);
	mlx_hook(data->mlx->mlx_window, 2, 1L << 0, keypressed, data);
	mlx_loop_hook(data->mlx->mlx, render_next_frame, data);

	mlx_loop(data->mlx->mlx);
	return (0);
}

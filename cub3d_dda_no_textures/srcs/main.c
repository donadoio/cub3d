/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/21 19:12:50 by idonado       #+#    #+#                 */
/*   Updated: 2021/10/23 18:24:41 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include <keycodes_osx.h> 

int	keypressed(int keycode, t_data	*data)
{
	double	old_dir_x;
	double	old_plane_x;
	
	clear_screen(data);
	if (keycode == UP_KEY)
	{
		if(data->map[(int)(data->pos_x + data->dir_x * 0.1)][(int)(data->pos_y)] == 0) data->pos_x += data->dir_x * 0.1;
    	if(data->map[(int)(data->pos_x)][(int)(data->pos_y + data->dir_y * 0.1)] == 0) data->pos_y += data->dir_y * 0.1;
		printf("UP\n");
	}
	else if (keycode == DOWN_KEY)
	{
		printf("DOWN\n");
	}
	else if (keycode == LEFT_KEY)
	{
		printf("LEFT\n");
	}
	else if (keycode == RIGHT_KEY)
	{
		printf("RIGHT\n");
	}
	else if (keycode == 123)
	{
		//both camera direction and camera plane must be rotated
    	old_dir_x = data->dir_x;
    	data->dir_x = data->dir_x * cos(0.1) - data->dir_y * sin(0.1);
    	data->dir_y = old_dir_x * sin(0.1) + data->dir_y * cos(0.1);
    	old_plane_x = data->plane_x;
    	data->plane_x = data->plane_x * cos(0.1) - data->plane_y * sin(0.1);
    	data->plane_y = old_plane_x * sin(0.1) + data->plane_y * cos(0.1);
	}
	else if (keycode == 124)
	{
		//both camera direction and camera plane must be rotated
    	old_dir_x = data->dir_x;
    	data->dir_x = data->dir_x * cos(-0.1) - data->dir_y * sin(-0.1);
    	data->dir_y = old_dir_x * sin(-0.1) + data->dir_y * cos(-0.1);
    	old_plane_x = data->plane_x;
    	data->plane_x = data->plane_x * cos(-0.1) - data->plane_y * sin(-0.1);
    	data->plane_y = old_plane_x * sin(-0.1) + data->plane_y * cos(-0.1);
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

int	render_next_frame(t_data *data)
{
	// used to calculate direction of ray from camera (?)
	double	camera_x;

	//direction fo ray
	double	ray_dir_x;
	double	ray_dir_y;

	//which box of the map we're in
    int map_x;
    int map_y;

	//length of ray from current position to next x or y-side
    double side_dist_x;
    double side_dist_y;

	//length of ray from one x or y-side to next x or y-side
    double delta_dist_x;
    double delta_dist_y;

	// used for calculating distance to wall
    double perp_wall_dist;

	//what direction to step in x or y-direction (either +1 or -1)
    int step_x;
    int step_y;

	//was there a wall hit?
	int hit = 0;

	//was a NS or a EW wall hit?
    int side;


	//used for line size calculation when drawing column by column
	int line_height;
    //calculate lowest and highest pixel to fill in current stripe
    int draw_start;
    int draw_end;

	int	color;
	int		x;

	x = 0;

	while (x < WINWIDTH)
	{
		//calculate ray position and directon
		camera_x = 2 * x / (double)x - 1;
		ray_dir_x = data->dir_x + data->plane_x * camera_x;
		ray_dir_y = data->dir_y + data->plane_y * camera_x;

		//calculating box in map
		map_x = (int)data->pos_x;
		map_y = (int)data->pos_y;

		//length of ray from one x or y-side to next x or y-side
		// possible crash ? check abs() function longer repacement
		if (ray_dir_x == 0)
			delta_dist_x = 1e30;
		else
			delta_dist_x = fabs(1 / ray_dir_x);
		if (ray_dir_y == 0)
			delta_dist_y = 1e30;
		else
			delta_dist_y = fabs(1 / ray_dir_y);

		hit = 0;

		//calculate step and initial sideDist
		if (ray_dir_x < 0)
		{
			step_x = -1;
			side_dist_x = (data->pos_x - map_x) * delta_dist_x;
		}
		else
		{
			step_x = 1;
			side_dist_x = (map_x + 1.0 - data->pos_x) * delta_dist_x;
		}
		if (ray_dir_y < 0)
		{
			step_y = -1;
			side_dist_y = (data->pos_y - map_y) * delta_dist_y;
		}
		else
		{
			step_y = -1;
			side_dist_y = (map_y + 1.0 - data->pos_y) * delta_dist_y;
		}
		

		//DDA algorithm
		while (hit == 0)
		{
			//jump to next map square, either in x-direction, or in y-direction
        	if (side_dist_x < side_dist_y)
        	{
        	  side_dist_x += delta_dist_x;
        	  map_x += step_x;
        	  side = 0;
        	}
        	else
        	{
        	  side_dist_y += delta_dist_y;
        	  map_y += step_y;
        	  side = 1;
        	}
        	//Check if ray has hit a wall
        	if (data->map[map_x][map_y] > 0)
				hit = 1;
		}

		//Calculate distance projected on camera direction 
      	if(side == 0)
			perp_wall_dist = (side_dist_x - delta_dist_x);
      	else
			perp_wall_dist = (side_dist_y - delta_dist_y);
		
		//Calculate height of line to draw on screen
      	line_height = (int)(WINHEIGHT / perp_wall_dist);
	
      	//calculate lowest and highest pixel to fill in current stripe
      	draw_start = -line_height / 2 + WINHEIGHT / 2;
      	if(draw_start < 0)
			draw_start = 0;
      	draw_end = line_height / 2 + WINHEIGHT / 2;
      	if(draw_end >= WINHEIGHT)
			draw_end = WINHEIGHT - 1;

		color = 0x00FF00FF;
		//give x and y sides different brightness
    	if (side == 1)
			{color = color / 2;}

		draw_vertical_line(data, x, draw_start, draw_end, color);

		x++;
	}


	mlx_put_image_to_window(data->mlx->mlx, data->mlx->mlx_window, data->img->img, 0, 0);
	usleep(500);
	return (0);
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

	//giving default position coordinates
	data->pos_x = 12;
	data->pos_y = 12;

	//direction coordinate
	data->dir_x = -1;
	data->dir_y = 0;

	//camera plane
	data->plane_x = 0;
	data->plane_y = 0.66;


	// key hooks and game loop
	mlx_hook(data->mlx->mlx_window, 2, 1L << 0, keypressed, data);
	mlx_loop_hook(data->mlx->mlx, render_next_frame, data);

	mlx_loop(data->mlx->mlx);
	return (0);
}

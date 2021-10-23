#include <cub3d.h>

void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	draw_line(t_data *data, int beginX, int beginY, int endX, int endY, int color)
{
	double deltaX = endX - beginX; // 10
	double deltaY = endY - beginY; // 0
	int pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));

	deltaX /= pixels; // 1
	deltaY /= pixels; // 0

	double pixelX = beginX;
	double pixelY = beginY;
	while (pixels)
	{
	    my_mlx_pixel_put(data->img, pixelX, pixelY, color);
	    pixelX += deltaX;
	    pixelY += deltaY;
	    --pixels;
	}
	return (0);
}

void	draw_vertical_line(t_data *data, int x, int begin, int end, int color)
{
	while (begin < end)
	{
		my_mlx_pixel_put(data->img, x, begin, color);
		begin++;
	}
	return ;
}

void	clear_screen(t_data *data)
{
	int x;
	int y;

	x = 0;
	while (x < WINWIDTH)
	{
		y = 0;
		while (y < WINHEIGHT)
		{
			my_mlx_pixel_put(data->img, x , y, 0x00000000);
			y++;
		}
		x++;
	}
	return ;
}
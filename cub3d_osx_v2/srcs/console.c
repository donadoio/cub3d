#include <cub3d.h>

void	print_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->map_height)
	{
		j = 0;
		while (j < data->map_width)
		{
			if (data->map[i][j] == 9 || data->map[i][j] == 8 || data->map[i][j] == 7 || data->map[i][j] == 6)
			{
				data->map[i][j] = 0;
				data->pos_x = i;
				data->pos_y = j;
			}
			printf("%d", data->map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	return ;
}

#include <cub3d.h>

int		**fill_map_check(t_data *data, int **tempmap, int i, int j)
{
	if (i > 0 && tempmap[i - 1][j] == 2)
		tempmap[i][j] = 2;
	if (i < data->map_height - 1 && tempmap[i + 1][j] == 2)
		tempmap[i][j] = 2;
	if (j > 0 && tempmap[i][j - 1] == 2)
		tempmap[i][j] = 2;
	if (j < data->map_width - 1 && tempmap[i][j + 1] == 2)
		tempmap[i][j] = 2;
	if (i > 0 && j > 0 && tempmap[i - 1][j - 1] == 2)
		tempmap[i][j] = 2;
	if (i < data->map_height - 1 && j > 0 &&
		tempmap[i + 1][j - 1] == 2)
		tempmap[i][j] = 2;
	if (j < data->map_width - 1 && i > 0 &&
		tempmap[i - 1][j + 1] == 2)
		tempmap[i][j] = 2;
	if (j < data->map_width - 1 && i < data->map_height - 1 &&
		tempmap[i + 1][j + 1] == 2)
		tempmap[i][j] = 2;
	return (tempmap);
}

void	free_tempmap(t_data *data, int **tempmap)
{
	int i;

	i = 0;
	while (i < data->map_height)
	{
		free(tempmap[i]);
		i++;
	}
	free(tempmap);
}

void	handle_temp_alloc_fail(t_data *data, int **tempmap, int i, int flag)
{
	int x;

	x = 0;
	if (flag == 1)
	{
		while (x < i)
		{
			free(tempmap[x]);
			x++;
		}
		free(tempmap);
	}
	//free stuff
    exit_delete_map(data, data->map_height, 0);
}
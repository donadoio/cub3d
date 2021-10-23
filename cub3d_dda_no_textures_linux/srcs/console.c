#include <cub3d.h>

void	print_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 24)
	{
		j = 0;
		while (j < 24)
		{
			printf("%d", data->map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	return ;
}

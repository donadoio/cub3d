/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/22 14:30:22 by idonado       #+#    #+#                 */
/*   Updated: 2021/08/25 15:25:41 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	new_line_found(char **line, char *buffer, size_t size)
{
	char	*newline;

	newline = buffer;
	while (*newline != '\0' && size != 42)
	{
		if (*newline == '\n')
			size = 42;
		newline++;
	}
	if (size == 42)
		newline--;
	if (*newline != '\n')
		newline = NULL;
	if (newline == NULL)
		return (0);
	*newline = '\0';
	*line = ft_strjoin_mod(*line, buffer, 0, 0);
	if (*line == NULL)
		return (2);
	*newline = '\n';
	size = ft_strlen(newline);
	ft_memmove(buffer, newline, size);
	buffer[size] = '\0';
	return (1);
}

static int	is_line_return(size_t is_line)
{
	if (is_line == 2)
		return (-1);
	else
		return (1);
}

static int	read_cycle(int fd, char **line, char *buffer)
{
	int		read_result;
	size_t	is_line;

	read_result = 1;
	while (read_result > 0)
	{
		read_result = read(fd, buffer, BUFFER_SIZE);
		if (read_result < 0)
			return (-1);
		buffer[read_result] = '\0';
		is_line = new_line_found(line, buffer, 0);
		if (is_line)
			return (is_line_return(is_line));
		else
		{
			*line = ft_strjoin_mod(*line, buffer, 0, 0);
			if (!(*line))
				return (-1);
		}
	}
	if (read_result > 0)
		return (1);
	else
		return (0);
}

static int	check_buffer(char **line, char *buffer, int *read_result, size_t i)
{
	char	*temp;

	temp = buffer;
	temp++;
	i = ft_strlen(temp);
	ft_memmove(buffer, temp, i);
	buffer[i] = '\0';
	i = new_line_found(line, buffer, 0);
	if (i)
	{
		if (i == 2)
			*read_result = -1;
		else
			*read_result = 1;
		return (1);
	}
	else
	{
		*line = ft_strjoin_mod(*line, buffer, 0, 0);
		if (!(*line))
			return (-1);
		return (0);
	}
	*read_result = 1;
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char	buffer[BUFFER_SIZE + 1];
	int			read_result;
	int			trigger;
	int			is_buffer;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, NULL, 0) < 0 || \
	line == NULL || fd > FOPEN_MAX)
		return (-1);
	*line = ft_strdup("");
	if (*line == NULL)
		return (-1);
	if (buffer[0] == '\n')
		is_buffer = 1;
	else
	{
		trigger = 0;
		is_buffer = 0;
	}
	if (is_buffer)
		trigger = check_buffer(line, buffer, &read_result, 0);
	if (!trigger)
		read_result = read_cycle(fd, line, buffer);
	return (read_result);
}

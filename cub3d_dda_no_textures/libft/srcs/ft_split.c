/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/09 19:38:41 by idonado       #+#    #+#                 */
/*   Updated: 2021/08/21 18:01:30 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static	size_t	wrds(char const *s, char c)
{
	size_t	words;

	words = 0;
	while (*s)
	{
		if (*s != c)
		{
			words++;
			while (*s && *s != c)
			{
				s++;
			}
			s--;
		}
		s++;
	}
	return (words);
}

static	char	*get_split(char const **s, char c)
{
	size_t	spaces;
	size_t	i;
	char	*result;
	char	*str;

	str = (char *)*s;
	spaces = 0;
	i = 0;
	while (*str && *str == c)
		str++;
	while (str[spaces] && str[spaces] != c)
		spaces++;
	result = malloc(sizeof(char) * (spaces + 1));
	if (result == NULL)
		return (NULL);
	while (*str && *str != c)
	{
		result[i] = *str;
		i++;
		str++;
	}
	result[i] = '\0';
	*s = str;
	return (result);
}

static	void	free_memory(char ***result)
{
	size_t	i;

	i = 0;
	while ((*result)[i])
	{
		free((*result)[i]);
		i++;
	}
	free(*result);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	words;
	char	**result;

	i = 0;
	words = 0;
	if (!s)
		return (NULL);
	words = wrds(s, c);
	result = malloc(sizeof(char *) * (words + 1));
	if (result == NULL)
		return (NULL);
	while (i < words)
	{
		result[i] = get_split(&s, c);
		if (result[i] == NULL)
		{
			free_memory(&result);
			return (NULL);
		}
		i++;
	}
	result[i] = (char *) NULL;
	return (result);
}

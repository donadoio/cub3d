/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/12 17:38:13 by idonado       #+#    #+#                 */
/*   Updated: 2021/08/21 18:04:49 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../hdrs/libft.h"

static	int	ft_strtrim_start(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static	int	ft_strtrim_end(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static	char	*ft_strtrim_process(char const *s1, size_t i, size_t j)
{
	size_t	k;
	char	*result;

	k = 0;
	result = (char *)malloc(sizeof(char) * ((j - i) + 2));
	if (result == NULL)
		return (NULL);
	k = 0;
	while (i <= j)
	{
		result[k] = s1[i];
		i++;
		k++;
	}
	result[k] = '\0';
	return (result);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	j;
	size_t	i;
	char	*result;

	i = 0;
	j = 0;
	if (s1 == NULL)
		return (NULL);
	while (s1[j] != '\0')
		j++;
	j--;
	while (ft_strtrim_start(s1[i], set))
	{
		i++;
		if (i == j)
			return (ft_strdup(""));
	}
	while (ft_strtrim_end(s1[j], set))
		j--;
	if ((i - 1) == j)
		return (ft_strdup(""));
	result = ft_strtrim_process(s1, i, j);
	return (result);
}

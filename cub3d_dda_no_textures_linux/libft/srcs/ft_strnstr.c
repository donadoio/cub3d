/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 15:03:49 by idonado       #+#    #+#                 */
/*   Updated: 2021/08/21 18:03:35 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static	int	check(const char *hay, const char *nd, int n, int i)
{
	int	j;

	j = 0;
	while (nd[j] != '\0' && hay[i] != '\0' && i <= n && nd[j] == hay[i])
	{
		i++;
		j++;
	}
	if (nd[j] == '\0')
		return (1);
	else
		return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;

	i = 0;
	if (!*needle)
		return ((char *)haystack);
	if (n >= 1)
		n = n - 1;
	while (haystack[i] != '\0' && i <= n)
	{
		if (check(haystack, needle, n, i))
		{
			return ((char *)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}

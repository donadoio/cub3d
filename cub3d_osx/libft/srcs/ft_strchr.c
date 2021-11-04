/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 16:58:57 by idonado        #+#    #+#                */
/*   Updated: 2019/11/30 15:11:05 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strchr(const char *s, int c)
{
	const char		*scpy;
	unsigned long	i;
	unsigned long	n;

	i = 0;
	n = 0;
	scpy = s;
	while (s[n] != '\0')
		n++;
	n++;
	while (i < n)
	{
		if (scpy[i] == '\0' && c != '\0')
			return (NULL);
		if (scpy[i] == c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}

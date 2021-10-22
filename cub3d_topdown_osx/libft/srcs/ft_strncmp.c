/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 16:29:57 by idonado       #+#    #+#                 */
/*   Updated: 2021/08/21 18:03:07 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned const char	*str1;
	unsigned const char	*str2;

	str1 = (unsigned const char *)s1;
	str2 = (unsigned const char *)s2;
	while (n > 0)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		if (!*str1 && *str1 == *str2)
			return (0);
		str1++;
		str2++;
		n--;
	}
	return (0);
}

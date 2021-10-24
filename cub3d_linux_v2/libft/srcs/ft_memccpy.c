/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memccpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/06 20:03:52 by idonado        #+#    #+#                */
/*   Updated: 2019/11/30 14:59:03 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dstcpy;
	unsigned char	*srccpy;
	size_t			i;

	dstcpy = (unsigned char *)dst;
	srccpy = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dstcpy[i] = srccpy[i];
		if (dstcpy[i] == (unsigned char)c)
			return ((void *)dstcpy + i + 1);
		i++;
	}
	return (NULL);
}

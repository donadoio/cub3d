/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/06 18:18:09 by idonado        #+#    #+#                */
/*   Updated: 2019/11/30 15:04:03 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dstcpy;
	unsigned char	*srccpy;
	size_t			i;

	dstcpy = (unsigned char *)dst;
	srccpy = (unsigned char *)src;
	i = 0;
	if (dst == NULL && src == NULL && n > 0)
		return (NULL);
	while (i < n)
	{
		dstcpy[i] = srccpy[i];
		i++;
	}
	return (dstcpy);
}

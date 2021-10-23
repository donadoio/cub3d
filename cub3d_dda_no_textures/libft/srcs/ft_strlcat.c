/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/13 19:40:39 by idonado       #+#    #+#                 */
/*   Updated: 2021/08/21 18:01:59 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (!dstsize || dstsize < dstlen)
		return (dstlen + srclen - (dstlen - dstsize));
	dstsize -= dstlen;
	ft_strlcpy(dst + dstlen, src, dstsize);
	return (dstlen + srclen);
}

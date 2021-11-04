/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/13 18:42:11 by idonado       #+#    #+#                 */
/*   Updated: 2021/08/05 16:23:13 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	char		*dstcpy;
	char		*end;
	const char	*srccpy;

	dstcpy = dst;
	end = dst + dstsize;
	srccpy = src;
	if (src == NULL)
		return (0);
	while (*srccpy != '\0' && dstcpy < end)
	{
		*dstcpy = *srccpy;
		dstcpy++;
		srccpy++;
	}
	if (dstcpy < end)
		*dstcpy = 0;
	else if (dstsize > 0)
		dstcpy[-1] = 0;
	while (*srccpy != '\0')
		srccpy++;
	return (srccpy - src);
}

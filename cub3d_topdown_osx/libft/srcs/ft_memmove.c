/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/06 20:54:40 by idonado       #+#    #+#                 */
/*   Updated: 2021/08/21 20:38:57 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static char	*copy(char *tdst, char *tsrc, int counter, size_t len)
{
	while (counter < (int)len)
	{
		tdst[counter] = tsrc[counter];
		counter++;
	}
	return (tdst);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*tdst;
	char	*tsrc;
	int		counter;

	tdst = (char *)dst;
	tsrc = (char *)src;
	counter = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (dst < src)
		tdst = copy(tdst, tsrc, counter, len);
	else
	{
		counter = (int)len;
		while (counter != 0)
		{
			tdst[counter - 1] = tsrc[counter - 1];
			counter--;
		}
	}
	return (tdst);
}

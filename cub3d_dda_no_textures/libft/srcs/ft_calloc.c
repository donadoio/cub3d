/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/08 18:04:25 by idonado       #+#    #+#                 */
/*   Updated: 2021/08/21 17:50:30 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../hdrs/libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*p;

	p = malloc(size * count);
	if (p == NULL)
		return (NULL);
	ft_bzero(p, (count * size));
	return (p);
}

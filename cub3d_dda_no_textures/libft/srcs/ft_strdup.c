/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/08 20:11:58 by idonado       #+#    #+#                 */
/*   Updated: 2021/08/05 16:23:02 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../hdrs/libft.h"

char	*ft_strdup(const char *s1)
{
	int		size;
	int		i;
	char	*tmp;

	size = 0;
	i = 0;
	size = ft_strlen(s1);
	tmp = malloc(sizeof(char) * size + 1);
	if (tmp == NULL)
		return (NULL);
	while (i < size)
	{
		tmp[i] = s1[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

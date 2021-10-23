/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/09 17:58:21 by idonado       #+#    #+#                 */
/*   Updated: 2021/08/21 18:05:03 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../hdrs/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	len_s;

	result = NULL;
	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	if (start >= ft_strlen((char *)s))
		return (ft_strdup(""));
	if (len_s - start < len)
		len = len_s - start;
	result = (char *)malloc(sizeof(char) * len + 1);
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, s + start, len + 1);
	return (result);
}

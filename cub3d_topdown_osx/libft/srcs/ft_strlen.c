/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 13:22:10 by idonado       #+#    #+#                 */
/*   Updated: 2021/08/21 18:02:18 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlen(const char *str)
{
	size_t	char_count;

	char_count = 0;
	while (str[char_count] != '\0')
	{
		char_count++;
	}
	return (char_count);
}

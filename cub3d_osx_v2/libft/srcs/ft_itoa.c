/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/12 15:54:44 by idonado       #+#    #+#                 */
/*   Updated: 2021/08/21 17:57:42 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../hdrs/libft.h"

static	int	ft_itoa_spaces(int n)
{
	if ((n / 1000000000) >= 1)
		return (10);
	if ((n / 100000000) >= 1)
		return (9);
	if ((n / 10000000) >= 1)
		return (8);
	if ((n / 1000000) >= 1)
		return (7);
	if ((n / 100000) >= 1)
		return (6);
	if ((n / 10000) >= 1)
		return (5);
	if ((n / 1000) >= 1)
		return (4);
	if ((n / 100) >= 1)
		return (3);
	if ((n / 10) >= 1)
		return (2);
	else
		return (1);
}

static	char	ft_itoa_op(int *n)
{
	char	c;

	c = (*n % 10) + '0';
	*n = *n / 10;
	return (c);
}

static	char	*ft_itoa_process_negative(int n, int spaces)
{
	char	*result;
	int		space_t;

	result = (char *)malloc(sizeof(char) * (spaces + 1));
	if (result == NULL)
		return (NULL);
	result[0] = '-';
	space_t = spaces - 1;
	if (n == 0)
		result[0] = '0';
	while (n != 0)
	{
		result[space_t] = ft_itoa_op(&n);
		space_t--;
	}
	result[spaces] = '\0';
	return (result);
}

static	char	*ft_itoa_process_positive(int n, int spaces)
{
	char	*result;
	int		space_t;

	result = (char *) malloc(sizeof(char) * (spaces + 1));
	if (result == NULL)
		return (NULL);
	space_t = spaces - 1;
	if (n == 0)
		result[0] = '0';
	while (n != 0)
	{
		result[space_t] = ft_itoa_op(&n);
		space_t--;
	}
	result[spaces] = '\0';
	return (result);
}

char	*ft_itoa(int n)
{
	int		spaces;
	int		temp;
	char	*result;

	spaces = 0;
	temp = n;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		spaces++;
		temp = n * -1;
		spaces = spaces + ft_itoa_spaces(temp);
		result = ft_itoa_process_negative(temp, spaces);
		return (result);
	}
	else
	{
		spaces = spaces + ft_itoa_spaces(temp);
		result = ft_itoa_process_positive(temp, spaces);
		return (result);
	}
}

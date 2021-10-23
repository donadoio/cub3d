/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalnum.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 19:13:58 by idonado       #+#    #+#                 */
/*   Updated: 2021/08/05 16:21:53 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) == 1)
		return (1);
	if (ft_isdigit(c) == 1)
		return (1);
	else
		return (0);
}

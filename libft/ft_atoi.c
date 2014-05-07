/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/03 15:56:51 by dsousa            #+#    #+#             */
/*   Updated: 2014/05/01 13:44:16 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	int		negative;
	int		value;

	negative = 0;
	value = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		negative = 1;
		str++;
	}
	while ((*str <= '9') && (*str >= '0'))
	{
		value = (value * 10) - (*str - '0');
		str++;
	}
	if (!negative)
		value = -value;
	return (value);
}

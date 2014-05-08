/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/06 14:57:58 by rbenjami          #+#    #+#             */
/*   Updated: 2014/05/06 15:17:06 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include "libft.h"

void	put_nbr(const char msg, va_list ap)
{
	if (msg == 'd' || msg == 'i')
		ft_putnbr_base(va_arg(ap, int), DECIMAL);
	else if (msg == 'o')
		ft_putnbr_base(va_arg(ap, int), OCTAL);
	else if (msg == 'x' || msg == 'X')
		ft_putnbr_base(va_arg(ap, int), HEXADECIMAL);
}

int		ft_printf(const char *msg, ...)
{
	va_list		ap;

	va_start(ap, msg);
	while (*msg)
	{
		if (*msg == '%')
		{
			msg++;
			if (*msg == '%')
				ft_putchar('%');
			else if (*msg == 'c')
				ft_putchar(va_arg(ap, int));
			else if (*msg == 's')
				ft_putstr(va_arg(ap, char*));
			else
				put_nbr(*msg, ap);
		}
		else
			ft_putchar(*msg);
		msg++;
	}
	va_end(ap);
	return (1);
}

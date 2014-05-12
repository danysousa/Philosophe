/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/06 14:46:33 by rbenjami          #+#    #+#             */
/*   Updated: 2014/05/06 14:56:19 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		error(const char *msg, ...)
{
	va_list		ap;

	va_start(ap, msg);
	while (*msg)
	{
		if (*msg == '%')
		{
			msg++;
			if (*msg == '%')
				ft_putchar_fd('%', 2);
			else if (*msg == 'c')
				ft_putchar_fd(va_arg(ap, int), 2);
			else if (*msg == 's')
				ft_putstr_fd(va_arg(ap, char*), 2);
			else if (*msg == 'd')
				ft_putnbr_fd(va_arg(ap, int), 2);
			else if (*msg == 'p')
				perror(va_arg(ap, const char*));
		}
		else
			ft_putcolored_char(*msg, 1);
		msg++;
	}
	va_end(ap);
	return (-42);
}
